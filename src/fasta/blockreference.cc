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

unsigned long long BlockReference::getNumberOfRef() {

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

    unsigned long long  iDsNumber = seqan::numSeqs(faiIndex);

    return iDsNumber;
}

std::vector<BlockContainer> BlockReference::getAllChrBlockContainer() {
    unsigned long long iDsNumber = getNumberOfRef();
    unsigned long long i = 0;
    std::vector<BlockContainer> bcs;
    for (i=0;i<iDsNumber;i++) {
        BlockContainer bc = getBlockContainerByID(i);
        bcs.push_back(bc);
    }

    return bcs;
}

BlockContainer BlockReference::getBlockContainerByID(unsigned long long id) {
    BlockContainer bc;

    seqan::Dna5String sequenceInfix;
    seqan::readSequence(sequenceInfix, faiIndex, id);
    seqan::CharString name = seqan::sequenceName(faiIndex,id);
    std::string chrname = seqan::toCString(name);
    std::vector<Block> blocks = convertSeqToBlockWithoutMasked(chrname,&sequenceInfix);
    bc.setBlocks(blocks);
    bc.setChr(chrname);
    return bc;
}

std::vector<Block> BlockReference::convertSeqToBlockWithoutMasked(std::string chrname,seqan::Dna5String *seq) {
    std::vector<Block> blocks;

    unsigned currentPosition = 0;
    unsigned sumPosition = 0;
    for (char n:*seq) {
        // X for hard masked, N for soft masked
        if (n=='N'||n=='n'||n=='X'||n=='x') {
            if (sumPosition>0) {
                Block rr;
                rr.setChrPos(chrname);
                rr.setPos(currentPosition-sumPosition);
                rr.setEnd(currentPosition);
                blocks.push_back(rr);
                std::cout << currentPosition-sumPosition << " - " << currentPosition << " = " << currentPosition-(currentPosition-sumPosition) <<  std::endl;

            }
            sumPosition = 0;
        } else {
            sumPosition++;
        }

        currentPosition++;
    }

    if (sumPosition>0) {
        Block rr;
        rr.setChrPos(chrname);
        rr.setPos(currentPosition-sumPosition);
        rr.setEnd(currentPosition);
        blocks.push_back(rr);
        std::cout << currentPosition-sumPosition << " - " << currentPosition <<  std::endl;
    }

    return blocks;
}

std::vector<Block> BlockReference::convertSeqToBlockWithMasked(std::string chrname,seqan::Dna5String *seq) {
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