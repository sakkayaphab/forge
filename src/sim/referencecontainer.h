//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#ifndef FORGE_REFERENCECONTAINER_H
#define FORGE_REFERENCECONTAINER_H

#include <string>
#include <vector>
#include "variantblock.h"
class ReferenceContainer {
private:
    std::string chr;
    int64_t pos=0;
    int64_t end=0;
    std::vector<VariantBlock> variantblocklist;

public:
    ReferenceContainer();
    void setChr(std::string chr);
    void setPos(int64_t pos);
    void setEnd(int64_t end);
    int64_t getPos();
    int64_t getEnd();
    std::string getChr();
    void setVariantBlocks(std::vector<VariantBlock> variantblocklist);
    std::vector<VariantBlock> getVariantBlocks();
    void addVariantBlock(VariantBlock vb);
};


#endif //FORGE_REFERENCECONTAINER_H
