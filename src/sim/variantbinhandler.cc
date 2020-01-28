//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#include "variantbinhandler.h"

VariantBinHandler::VariantBinHandler() {

}

void VariantBinHandler::addVariant(VariantBlock variant) {
    VariantBinHandler::variantlist.push_back(variant);
}

void VariantBinHandler::setSeed(unsigned seed) {
    VariantBinHandler::seed = seed;
    std::default_random_engine tempRnge(seed);
    rnge = tempRnge;
}

unsigned VariantBinHandler::getSeed() {
    return VariantBinHandler::seed;
}

void VariantBinHandler::shuffleVariantList() {
    std::shuffle(std::begin(VariantBinHandler::variantlist), std::end(VariantBinHandler::variantlist), rnge);
}

std::vector<VariantBlock> VariantBinHandler::getVariantList() {
    return VariantBinHandler::variantlist;
}

void VariantBinHandler::addVariantByParameter(std::string svtype, int64_t length) {
    VariantBlock tempVariant;
    tempVariant.setSpace(VariantBinHandler::space);
    tempVariant.setSvType(svtype);
    if (svtype=="INS") {
        tempVariant.setAppxRefLength(1);
    } else if (svtype=="TRA") {
        tempVariant.setAppxRefLength(1);
    } else {
        tempVariant.setAppxRefLength(length);
    }
    VariantBinHandler::addVariant(tempVariant);
}

void VariantBinHandler::setSpace(int64_t space) {
    VariantBinHandler::space = space;
}

int64_t VariantBinHandler::getSpace() {
    return VariantBinHandler::space;
}

void VariantBinHandler::addVariantByRange(std::string svtype, int64_t minlength, int64_t maxlength, int number) {
    std::uniform_int_distribution<int64_t> dis(minlength, maxlength);
    for (int i=0;i<number;i++) {
        addVariantByParameter(svtype,dis(rnge));
    }
}

void VariantBinHandler::showVariantList() {
    for (VariantBlock x:variantlist) {
        x.show();
    }
}

void VariantBinHandler::sortVariantList() {
    std::sort(VariantBinHandler::variantlist.begin(),
              VariantBinHandler::variantlist.end(),
              [](VariantBlock& lhs, VariantBlock& rhs)
              {
                  return lhs.getAppxRefLengthWithSpace() > rhs.getAppxRefLengthWithSpace();
              });
}


