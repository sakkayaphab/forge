#include "fastareader.h"



FastaReader::FastaReader() {
}

void FastaReader::initialize() {
    if (hasIndexFilePath()) {
        faidx.initialize();
    } else {
        faidx.genarateIndexFile(getFilePath(), getIndexFilePath());
        faidx.initialize();
    }
}

bool FastaReader::FileExists(std::string filename) {
    std::ifstream ifile(filename.c_str());
    return (bool) ifile;
}

bool FastaReader::hasIndexFilePath() {
    return FileExists(getIndexFilePath());
}

bool FastaReader::hasFilePath() {
    return FileExists(getFilePath());
}

void FastaReader::exitIfNoFilePath() {
    if (!hasIndexFilePath()) {
        std::cerr << "not found index file" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!hasFilePath()) {
        std::cerr << "not found file path" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void FastaReader::setIndexFilePath(std::string t_indexfilepath) {
    faidx.setIndexFilePath(t_indexfilepath);
}

std::string FastaReader::getIndexFilePath() {
    return faidx.getIndexFilePath();
}

void FastaReader::setFilePath(std::string filepath) {
    fasta.setFilePath(filepath);
}

std::string FastaReader::getFilePath() {
    return fasta.getFilePath();
}

std::string FastaReader::getSeqbyPosition(std::string chromosome, int64_t start, int64_t end) {
    int64_t offsetstart = faidx.getOffsetStartByPosition(chromosome, start);
    int64_t offsetend = faidx.getOffsetEndByPosition(chromosome, end);

    return fasta.getSeqByOffset(offsetstart, offsetend);
}

std::string FastaReader::getSeqbyChr(std::string chromosome) {
    if (!faidx.hasChromosomeName(chromosome)) {
        return "";
    }

    int64_t length = faidx.getLengthbyChromosome(chromosome);
    int64_t offset = faidx.getOffsetbyChromosome(chromosome);
    int64_t offsetend = faidx.getOffsetEndByPosition(chromosome, length);

    return fasta.getSeqByOffset(offset, offsetend);
}

Faidx FastaReader::getFastaIndex() {
    return faidx;
}


ContainerManager FastaReader::getAllChrBlockContainerWithThreads(int threads) {

    tbb::global_control c(tbb::global_control::max_allowed_parallelism, threads);
    ContainerManager cm;
    std::vector<BlockContainer> bcs;
    std::mutex mxBCS;
    tbb::parallel_for(0, faidx.getSize(), [&](int i) {
        mxBCS.lock();
        i++;
        mxBCS.unlock();
        BlockContainer bc = getBlockContainerByChr(faidx.getChrByNumberID(i - 1));

        mxBCS.lock();
        bcs.push_back(bc);
        mxBCS.unlock();
    });

    cm.setBlockContainers(bcs);

    return cm;
}

ContainerManager FastaReader::getAllChrBlockContainerWithSingleThread() {
    ContainerManager cm;
    std::vector<BlockContainer> bcs;

    std::ifstream file(FastaReader::getFilePath());
    std::vector<IndexFormat> indexList;

    std::string tempNAME;
    int64_t tempLENGTH = 0;
    std::string tempSEQ;
    int64_t sumOffset = 0;
    std::string line;
    while (std::getline(file, line)) {
        if (line.at(0) == '>') {
            if (tempLENGTH != 0) {
                BlockContainer bc;
                std::vector<Block> blocks = convertSeqToBlockWithoutMasked(tempNAME, &tempSEQ);
                bc.setBlocks(blocks);
                bc.setChr(tempNAME);
                bcs.push_back(bc);
                tempNAME = "";
                tempLENGTH = 0;
                tempSEQ = "";
                blocks.clear();

            }
            std::string delimiter = " ";
            std::string token = line.substr(0, line.find(delimiter));
            tempNAME = token.substr(1);
            sumOffset += line.size() + 1;
        } else {
            tempLENGTH += line.size();
            tempSEQ += line;
            sumOffset += line.size() + 1;
        }
    }

    BlockContainer bc;
    std::string seq = getSeqbyChr(tempNAME);
    std::vector<Block> blocks = convertSeqToBlockWithoutMasked(tempNAME, &seq);
    bc.setBlocks(blocks);
    bc.setChr(tempNAME);
    bcs.push_back(bc);

    cm.setBlockContainers(bcs);

    return cm;
}

BlockContainer FastaReader::getBlockContainerByChr(std::string chrname) {
    BlockContainer bc;
    std::string seq = getSeqbyChr(chrname);
    std::vector<Block> blocks = convertSeqToBlockWithoutMasked(chrname, &seq);
    bc.setBlocks(blocks);
    bc.setChr(chrname);
    blocks.clear();
    return bc;
}

std::vector<Block> FastaReader::convertSeqToBlockWithoutMasked(std::string chrname, std::string *seq) {
    std::vector<Block> blocks;

    unsigned currentPosition = 0;
    unsigned sumPosition = 0;
    std::string currentSeq;
    for (char n:*seq) {
        // X for hard masked, N for soft masked
        if (n == 'N' || n == 'n' || n == 'X' || n == 'x') {
            if (sumPosition > 0) {
                Block rr;
                rr.setChr(chrname);
                rr.setPos(currentPosition - sumPosition);
                rr.setEnd(currentPosition);
                rr.setSeq(currentSeq);
                blocks.push_back(rr);
            }
            sumPosition = 0;
            currentSeq.clear();
        } else {
            sumPosition++;
            if (FastaReader::isSaveSeqInBlockContainer()) {
                currentSeq += n;
            }
        }

        currentPosition++;
    }

    if (sumPosition > 0) {
        Block rr;
        rr.setChr(chrname);
        rr.setPos(currentPosition - sumPosition);
        rr.setEnd(currentPosition);
        rr.setSeq(currentSeq);
        blocks.push_back(rr);
    }

    return blocks;
}

std::vector<Block> FastaReader::convertSeqToBlockWithMasked(std::string chrname, std::string *seq) {
    std::vector<Block> blocks;

    unsigned currentPosition = 0;
    unsigned sumPosition = 0;

    for (char n:*seq) {
        // X for hard masked, N for soft masked
        if (n == 'N' || n == 'n' || n == 'X' || n == 'x') {
            sumPosition++;
        } else {
            if (sumPosition > 0) {
                Block rr;
                rr.setChr(chrname);
                rr.setPos(currentPosition - sumPosition);
                rr.setEnd(currentPosition);
                blocks.push_back(rr);
            }
            sumPosition = 0;
        }

        currentPosition++;
    }

    if (sumPosition > 0) {
        Block rr;
        rr.setChr(chrname);
        rr.setPos(currentPosition - sumPosition);
        rr.setEnd(currentPosition);
        blocks.push_back(rr);
    }

    return blocks;
}

void FastaReader::showChromosomeRegion(FastaReader::ChromosomeRegion cr) {
    int64_t regionlength = 0;
    for (RegionRange x:cr.RegionRange) {
        regionlength += x.end - x.pos;
        std::cout << x.chrname <<
                  ", " << x.pos <<
                  ", " << x.end <<
                  " | " << x.end - x.pos <<
                  std::endl;
    }

    std::cout << "region length w/o masked : " << regionlength << std::endl;
}

void FastaReader::saveSeqInBlockContainer(bool save) {
    FastaReader::saveseqinRC = save;
}

bool FastaReader::isSaveSeqInBlockContainer() {
    return FastaReader::saveseqinRC;
}

ContainerManager FastaReader::getOnlylChrBlockContainer(std::string chrname) {
    ContainerManager cm;
    std::vector<BlockContainer> bcs;
    BlockContainer bc = getBlockContainerByChr(chrname);
    bcs.push_back(bc);

    cm.setBlockContainers(bcs);

    return cm;
}