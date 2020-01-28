//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#ifndef FORGE_ARRANGEMENTCONTAINER_H
#define FORGE_ARRANGEMENTCONTAINER_H

#include <string>
#include <iostream>
#include "variantbinhandler.h"
#include "referencecontainer.h"
#include "variantbinhandler.h"
#include "referencecontainerhandler.h"

class ArrangementContainer {
private:
    VariantBinHandler *variantbin;
    std::vector<ReferenceContainer> *referencecontainer;
    ReferenceContainerHandler *rch;
public:
    ArrangementContainer();
    void setVariantBin(VariantBinHandler *variantbin);
    void setReferenceContainerHandler(ReferenceContainerHandler *rch);
    VariantBinHandler *getVariantBin();
    ReferenceContainerHandler *getReferenceContainerHandler();

};


#endif //FORGE_ARRANGEMENTCONTAINER_H
