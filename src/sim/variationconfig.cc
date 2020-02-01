//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#include "variationconfig.h"


VariantionConfig::VariantionConfig() {

}

void VariantionConfig::setSvType(std::string svtype) {
    VariantionConfig::svtype = svtype;
}

void VariantionConfig::setVariantRangeList(std::vector<VariantionRange> variantrangelist) {
    VariantionConfig::variantrangelist = variantrangelist;
}

std::string VariantionConfig::getSvType() {
    return VariantionConfig::svtype;
}

std::vector<VariantionRange> VariantionConfig::getVariantRangeList() {
    return VariantionConfig::variantrangelist;
}

void VariantionConfig::addVariantRangeToList(VariantionRange variantrange) {
    VariantionConfig::variantrangelist.push_back(variantrange);
}

int VariantionConfig::getNumberOfVariant() {
    int number = 0;
    for (VariantionRange x:variantrangelist) {
        number+=x.getNumber();
    }
    return number;
}
