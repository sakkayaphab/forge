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
    seqan::FaiIndex faiIndex;
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