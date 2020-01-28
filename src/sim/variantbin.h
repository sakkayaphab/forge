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
public:
    VariantBin();
    void addVariant(Variant variant);
    void addVariantByLength(std::string svtype, int64_t length);
    void setSeed(unsigned seed);
    unsigned getSeed();
    void shuffleBin();
    std::vector<Variant> getVariantList();
};

#endif //FORGE_VARIANTBIN_H
