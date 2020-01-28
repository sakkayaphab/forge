//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#include "variantbin.h"

VariantBin::VariantBin() {

}

void VariantBin::addVariant(Variant variant) {
    VariantBin::variantlist.push_back(variant);
}

void VariantBin::setSeed(unsigned seed) {
    VariantBin::seed = seed;
}

unsigned VariantBin::getSeed() {
    return VariantBin::seed;
}

void VariantBin::shuffleBin() {
    std::default_random_engine rnge(VariantBin::seed);
    std::shuffle(std::begin(VariantBin::variantlist), std::end(VariantBin::variantlist), rnge);
}

std::vector<Variant> VariantBin::getVariantList() {
    return VariantBin::variantlist;
}
