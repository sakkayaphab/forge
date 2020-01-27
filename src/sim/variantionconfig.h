//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#ifndef FORGE_VARIANTIONCONFIG_H
#define FORGE_VARIANTIONCONFIG_H

#include <string>
#include <vector>
#include "variantionrange.h"

class VariantionConfig {
    private:
        std::string svtype;
        std::vector<VariantionRange> variantrangelist;

    public:
        VariantionConfig();
        void setSvType(std::string svtype);
        void setVariantRangeList(std::vector<VariantionRange> variantrangelist);
        std::string getSvType();
        std::vector<VariantionRange> getVariantRangeList();
        void addVariantRangeToList(VariantionRange variantrange);
        int getNumberOfVariant();


};


#endif //FORGE_VARIANTIONCONFIG_H
