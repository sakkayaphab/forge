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

class BlockReference {
private:
    std::string fastaPath;
    seqan::FaiIndex faiIndex;

public:
    BlockReference(std::string fastaPath);
    std::string getFastaPath();
    void setFastaPath(const std::string fastaPath);
    uint64_t getNumberOfRef();
    std::string *getSequence(std::string chrname,uint64_t pos,uint64_t end);
    std::string getSequenceName(uint64_t rID);

};


#endif //FORGE_BLOCKREFERENCE_H
