//
// Created by Sakkayaphab Piwluang on 23/1/20.
//

#ifndef FORGE_BLOCKREFERENCE_H
#define FORGE_BLOCKREFERENCE_H

#include <string>
#include <stdint.h>
#include <seqan/sequence.h>
#include <seqan/seq_io.h>
#include <seqan/stream.h>
#include "block.h"
#include "blockcontainer.h"
#include "containermanager.h"

class BlockReference {
private:
    std::string fastaPath;
    seqan::FaiIndex faiIndex;

public:
    BlockReference(std::string fastaPath);
    std::string getFastaPath();
    void setFastaPath(const std::string fastaPath);
    unsigned long long getNumberOfRef();
    BlockContainer getBlockContainerByID(unsigned long long id);
    ContainerManager getAllChrBlockContainer();
    std::vector<Block> convertSeqToBlockWithoutMasked(std::string chrname,seqan::Dna5String *seq);
    std::vector<Block> convertSeqToBlockWithMasked(std::string chrname,seqan::Dna5String *seq);

};


#endif //FORGE_BLOCKREFERENCE_H
