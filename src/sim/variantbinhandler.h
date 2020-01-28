//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#ifndef FORGE_VARIANTBINHANDLER_H
#define FORGE_VARIANTBINHANDLER_H

#include <vector>
#include "variantblock.h"
#include <algorithm>
#include <random>

class VariantBinHandler {
    std::vector<VariantBlock> variantlist;
    unsigned seed=0;
    std::default_random_engine rnge;
    int64_t  space = 0;
public:
    VariantBinHandler();
    void setSpace(int64_t space);
    int64_t getSpace();
    void addVariant(VariantBlock variant);
    void addVariantByParameter(std::string svtype, int64_t length);
    void addVariantByRange(std::string svtype,int64_t minlength,int64_t maxlength,int number);
    void setSeed(unsigned seed);
    unsigned getSeed();
    void shuffleBin();
    std::vector<VariantBlock> getVariantList();
    void showVariantList();
};

#endif //FORGE_VARIANTBINHANDLER_H
