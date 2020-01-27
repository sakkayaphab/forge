//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#ifndef FORGE_VARIANTCONFIG_H
#define FORGE_VARIANTCONFIG_H

#include <string>
#include <vector>
#include "variantrange.h"

class VariantConfig {
    private:
        std::string svtype;
        std::vector<VariantRange> variantrangelist;

    public:
        VariantConfig();
        void setSvType(std::string svtype);
        void setVariantRangeList(std::vector<VariantRange> variantrangelist);
        std::string getSvType();
        std::vector<VariantRange> getVariantRangeList();
        void addVariantRangeToList(VariantRange variantrange);
        int getNumberOfVariant();

};


#endif //FORGE_VARIANTCONFIG_H
