//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#include "seqmod.h"

SeqMod::SeqMod() {

}

std::string SeqMod::copy(int64_t pos, int64_t end) {
    std::string buffer = source.substr(pos,end);
    return buffer;
}

void SeqMod::setSeq(std::string seq) {
    SeqMod::source = seq;
}

std::string SeqMod::getSeq() {
    return SeqMod::source;
}

void SeqMod::erase(int64_t pos, int64_t end) {
    source.erase (pos,end-pos);
}

void SeqMod::insert(int64_t pos, std::string seq) {
    source.insert(pos, seq);
}

inline char complement(char n)
{
    switch(n)
    {
        case 'A':
            return 'T';
        case 'T':
            return 'A';
        case 'G':
            return 'C';
        case 'C':
            return 'G';
        case 'a':
            return 't';
        case 't':
            return 'a';
        case 'g':
            return 'c';
        case 'c':
            return 'g';
    }
    assert(false);
    return ' ';
}

std::string SeqMod::reverseComplement(std::string seq) {
    transform(
            begin(seq),
            end(seq),
            begin(seq),
            complement);
    reverse(seq.begin(), seq.end());
    return seq;
}
