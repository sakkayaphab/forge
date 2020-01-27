//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#ifndef FORGE_SEQMOD_H
#define FORGE_SEQMOD_H

#include <string>
#include <algorithm>
#include <cassert>
#include <iostream>

class SeqMod {

private:
    std::string source;
public:
    SeqMod();
    void setSeq(std::string seq);
    std::string getSeq();
    std::string copy(int64_t pos, int64_t end);
    void erase(int64_t pos, int64_t end);
    void insert(int64_t pos, std::string seq);
    std::string reverseComplement(std::string seq);
};


#endif //FORGE_SEQMOD_H
