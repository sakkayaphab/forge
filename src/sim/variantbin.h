//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#ifndef FORGE_VARIANTBIN_H
#define FORGE_VARIANTBIN_H

#include <vector>
#include "variant.h"
#include <algorithm>
#include <random>

class VariantBin {
    std::vector<Variant> variantlist;
    unsigned seed;
    std::default_random_engine rnge;
    int64_t  space = 0;
public:
    VariantBin();
    void setSpace(int64_t space);
    int64_t getSpace();
    void addVariant(Variant variant);
    void addVariantByParameter(std::string svtype, int64_t length);
    void setSeed(unsigned seed);
    unsigned getSeed();
    void shuffleBin();
    std::vector<Variant> getVariantList();
};

#endif //FORGE_VARIANTBIN_H
