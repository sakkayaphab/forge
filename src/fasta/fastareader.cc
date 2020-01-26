#include "fastareader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include <cstring>


FastaReader::FastaReader()
{
}

void FastaReader::initialize()
{
    faidx.genarateIndexFile(getFilePath(),getIndexFilePath());
//    if (hasIndexFilePath()) {
//        faidx.initialize();
//    } else {
//
//    }
}

bool FastaReader::FileExists(std::string filename) {
    std::ifstream ifile(filename.c_str());
    return (bool)ifile;
}

bool FastaReader::hasIndexFilePath() {
    return FileExists(getIndexFilePath());
}

bool FastaReader::hasFilePath() {
    return FileExists(getFilePath());
}

void FastaReader::exitIfNoFilePath() {
    if (!hasIndexFilePath()) {
        exit (EXIT_FAILURE);
    }

    if (!hasFilePath()) {
        exit (EXIT_FAILURE);
    }
}

void FastaReader::setIndexFilePath(std::string t_indexfilepath)
{
    faidx.setIndexFilePath(t_indexfilepath);
}

std::string FastaReader::getIndexFilePath()
{
    return faidx.getIndexFilePath();
}

void FastaReader::setFilePath(std::string filepath)
{
    fasta.setFilePath(filepath);
}

std::string FastaReader::getFilePath()
{
    return fasta.getFilePath();
}

std::string FastaReader::getSeqbyPosition(std::string chromosome,int64_t start,int64_t  end) {
    int64_t offsetstart = faidx.getOffsetStartByPosition(chromosome,start);
    int64_t offsetend  = faidx.getOffsetEndByPosition(chromosome,end);

    return fasta.getSeqByOffset(offsetstart,offsetend);
}

std::string FastaReader::getSeqbyChr(std::string chromosome) {
    if (!faidx.hasChromosomeName(chromosome)) {
        return "";
    }

    int64_t length = faidx.getLengthbyChromosome(chromosome);
    int64_t offset = faidx.getOffsetbyChromosome(chromosome);
    int64_t offsetend  = faidx.getOffsetEndByPosition(chromosome,length);

    return fasta.getSeqByOffset(offset,offsetend);
}

Faidx FastaReader::getFastaIndex() {
    return faidx;
}


ContainerManager FastaReader::getAllChrBlockContainer() {

    tbb::global_control c(tbb::global_control::max_allowed_parallelism, 10);
    ContainerManager cm;
    std::vector<BlockContainer> bcs;
    std::mutex mxBCS;
    tbb::parallel_for(0, faidx.getSize(), [&](int i) {
        mxBCS.lock();
        i++;
        mxBCS.unlock();
        BlockContainer bc = getBlockContainerByChr(faidx.getChrByNumberID(i-1));

        mxBCS.lock();
        bcs.push_back(bc);
        mxBCS.unlock();
    });


    cm.setBlockContainers(bcs);

    return cm;
}

BlockContainer FastaReader::getBlockContainerByChr(std::string chrname) {
    BlockContainer bc;
    std::string seq = getSeqbyChr(chrname);
    std::vector<Block> blocks = convertSeqToBlockWithoutMasked(chrname,&seq);
    bc.setBlocks(blocks);
    bc.setChr(chrname);
    return bc;
}

std::vector<Block> FastaReader::convertSeqToBlockWithoutMasked(std::string chrname,std::string *seq) {
    std::vector<Block> blocks;

    unsigned currentPosition = 0;
    unsigned sumPosition = 0;
    for (char n:*seq) {
        // X for hard masked, N for soft masked
        if (n=='N'||n=='n'||n=='X'||n=='x') {
            if (sumPosition>0) {
                Block rr;
                rr.setChr(chrname);
                rr.setPos(currentPosition-sumPosition);
                rr.setEnd(currentPosition);
                blocks.push_back(rr);
            }
            sumPosition = 0;
        } else {
            sumPosition++;
        }

        currentPosition++;
    }

    if (sumPosition>0) {
        Block rr;
        rr.setChr(chrname);
        rr.setPos(currentPosition-sumPosition);
        rr.setEnd(currentPosition);
        blocks.push_back(rr);
    }

    return blocks;
}

std::vector<Block> FastaReader::convertSeqToBlockWithMasked(std::string chrname,std::string *seq) {
    std::vector<Block> blocks;

    unsigned currentPosition = 0;
    unsigned sumPosition = 0;

    for (char n:*seq) {
        // X for hard masked, N for soft masked
        if (n=='N'||n=='n'||n=='X'||n=='x') {
            sumPosition++;
        } else {
            if (sumPosition>0) {
                Block rr;
                rr.setChr(chrname);
                rr.setPos(currentPosition-sumPosition);
                rr.setEnd(currentPosition);
                blocks.push_back(rr);
            }
            sumPosition = 0;
        }

        currentPosition++;
    }

    if (sumPosition>0) {
        Block rr;
        rr.setChr(chrname);
        rr.setPos(currentPosition-sumPosition);
        rr.setEnd(currentPosition);
        blocks.push_back(rr);
    }

    return blocks;
}

void FastaReader::showChromosomeRegion(FastaReader::ChromosomeRegion cr) {
    int64_t regionlength=0;
    for (RegionRange x:cr.RegionRange) {
        regionlength += x.end-x.pos;
        std::cout << x.chrname <<
        ", " << x.pos <<
        ", " << x.end <<
        " | " << x.end-x.pos <<
        std::endl;
    }

    std::cout << "region length w/o masked : " << regionlength << std::endl;
}
