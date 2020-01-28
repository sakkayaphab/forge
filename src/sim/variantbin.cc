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
    std::default_random_engine tempRnge(seed);
    rnge = tempRnge;
}

unsigned VariantBin::getSeed() {
    return VariantBin::seed;
}

void VariantBin::shuffleBin() {
    std::shuffle(std::begin(VariantBin::variantlist), std::end(VariantBin::variantlist), rnge);
}

std::vector<Variant> VariantBin::getVariantList() {
    return VariantBin::variantlist;
}

void VariantBin::addVariantByParameter(std::string svtype, int64_t length) {
    Variant tempVariant;
    tempVariant.setSpace(VariantBin::space);
    tempVariant.setSvType(svtype);
    if (svtype=="INS") {
        tempVariant.setAppxRefLength(1);
    } else if (svtype=="TRA") {
        tempVariant.setAppxRefLength(1);
    } else {
        tempVariant.setAppxRefLength(length);
    }

    VariantBin::addVariant(tempVariant);
}

void VariantBin::setSpace(int64_t space) {
    VariantBin::space = space;
}

int64_t VariantBin::getSpace() {
    return VariantBin::space;
}


