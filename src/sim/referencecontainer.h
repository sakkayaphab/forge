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
    int64_t pos;
    int64_t end;
    std::vector<VariantBlock> variantblocklist;

public:
    ReferenceContainer();
    void setChr(std::string chr);
    void setPos(int64_t pos);
    void setEnd(int64_t end);
};


#endif //FORGE_REFERENCECONTAINER_H
