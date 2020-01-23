//
// Created by Sakkayaphab Piwluang on 23/1/20.
//

#include "blockreference.h"


BlockReference::BlockReference(std::string fastaPath) {
    BlockReference::fastaPath = fastaPath;
}

std::string BlockReference::getFastaPath() {
    return fastaPath;
}

void BlockReference::setFastaPath(std::string fastaPath) {
    BlockReference::fastaPath = fastaPath;
}

uint64_t BlockReference::getNumberOfRef() {

    if (!seqan::open(faiIndex, fastaPath.c_str()))
    {
        if (!seqan::build(faiIndex, fastaPath.c_str()))
        {
            std::cerr << "ERROR: Index could not be loaded or built.\n";
        }
        if (!seqan::save(faiIndex))    // Name is stored from when reading.
        {
            std::cerr << "ERROR: Index could not be written do disk.\n";
        }
    }

    uint64_t iDsNumber = seqan::numSeqs(faiIndex);

    return iDsNumber;
}

BlockContainer BlockReference::getBlockContainerByID(uint64_t id) {
    BlockContainer bc;

    seqan::Dna5String sequenceInfix;
    seqan::readSequence(sequenceInfix, faiIndex, id);
    seqan::CharString name = seqan::sequenceName(faiIndex,id);
    std::string chrname = seqan::toCString(name);
    std::vector<Block> blocks = convertSeqToBlock(chrname,&sequenceInfix);
    bc.setBlocks(blocks);

    return bc;
}

std::vector<Block> BlockReference::convertSeqToBlock(std::string chrname,seqan::Dna5String *seq) {
    std::vector<Block> blocks;

    int64_t currentPosition = 0;
    int64_t sumPosition = 0;
    for (char n:*seq) {
        // X for hard masked, N for soft masked
        if (n=='N'||n=='n'||n=='X'||n=='x') {
            sumPosition++;
        } else {
            if (sumPosition>0) {
                Block rr;
                rr.setChrPos(chrname);
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
        rr.setChrPos(chrname);
        rr.setPos(currentPosition-sumPosition);
        rr.setEnd(currentPosition);
        blocks.push_back(rr);
    }

    return blocks;
}