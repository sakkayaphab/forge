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
    faidx.initialize();
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

std::vector<FastaReader::ChromosomeRegion>  FastaReader::getAllRegionChromosomeWithoutGap() {
    std::vector<FastaReader::ChromosomeRegion> crlist;
    std::vector<Faidx::FileFormat> faidxRecords = faidx.getRecords();
    for (Faidx::FileFormat record : faidxRecords) {
        ChromosomeRegion cr = getRegionChromosomeWithoutGap(record.NAME);
        crlist.push_back(cr);
    }
    return crlist;
}

FastaReader::ChromosomeRegion  FastaReader::getRegionChromosomeWithoutGap(std::string chrname) {
    std::string seq = getSeqbyChr(chrname);

    FastaReader::ChromosomeRegion chrRegion;
    int64_t currentPosition = 0;
    int64_t sumPosition = 0;
    for (char n:seq) {
        // X for hard masked, N for soft masked
        if (n=='N'||n=='n'||n=='X'||n=='x') {
            sumPosition++;
        } else {
            if (sumPosition>0) {
                RegionRange rr;
                rr.chrname = chrname;
                rr.pos = currentPosition-sumPosition;
                rr.end = currentPosition;
                chrRegion.RegionRange.push_back(rr);
            }
            sumPosition = 0;
        }

        currentPosition++;
    }

    if (sumPosition>0) {
        RegionRange rr;
        rr.chrname = chrname;
        rr.pos = currentPosition-sumPosition;
        rr.end = currentPosition;
        chrRegion.RegionRange.push_back(rr);
    }

    return chrRegion;
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