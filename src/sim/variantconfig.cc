//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#include "variantconfig.h"


VariantConfig::VariantConfig() {

}

void VariantConfig::setSvType(std::string svtype) {
    VariantConfig::svtype = svtype;
}

void VariantConfig::setVariantRangeList(std::vector<VariantRange> variantrangelist) {
    VariantConfig::variantrangelist = variantrangelist;
}

std::string VariantConfig::getSvType() {
    return VariantConfig::svtype;
}

std::vector<VariantRange> VariantConfig::getVariantRangeList() {
    return VariantConfig::variantrangelist;
}

void VariantConfig::addVariantRangeToList(VariantRange variantrange) {
    VariantConfig::variantrangelist.push_back(variantrange);
}

int VariantConfig::getNumberOfVariant() {
    int number = 0;
    for (VariantRange x:variantrangelist) {
        number+=x.getNumber();
    }
    return number;
}
