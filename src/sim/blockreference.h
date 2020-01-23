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
public:
    BlockReference(std::string fastaPath);
    std::string getFastaPath();
    void setFastaPath(const std::string fastaPath);
    uint64_t getNumberOfRef();



};


#endif //FORGE_BLOCKREFERENCE_H
