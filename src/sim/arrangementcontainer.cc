//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#include "arrangementcontainer.h"

ArrangementContainer::ArrangementContainer() {

}

void ArrangementContainer::setVariantBin(VariantBinHandler *variantbin) {
    ArrangementContainer::variantbin = variantbin;
}

void ArrangementContainer::setReferenceContainerHandler(ReferenceContainerHandler *rch) {
    ArrangementContainer::rch = rch;
}

VariantBinHandler *ArrangementContainer::getVariantBin() {
    return ArrangementContainer::variantbin;
}

ReferenceContainerHandler *ArrangementContainer::getReferenceContainerHandler() {
    return ArrangementContainer::rch;
}

void ArrangementContainer::execute() {
    ArrangementContainer::runWorstFitDecreasing();
}

void ArrangementContainer::runWorstFitDecreasing() {
    std::cout << getReferenceContainerHandler()->getSize() << std::endl;
    for (VariantBlock vb:getVariantBin()->getVariantList()) {
        bool added = false;

        for (int64_t i =0;i<getReferenceContainerHandler()->getSize();i++) {
            std::cout << i << "/" << getReferenceContainerHandler()->getSize() << std::endl;
            if (getReferenceContainerHandler()->getReferenceContainerList()->at(i).haveSpaceToAdd(vb)) {
                getReferenceContainerHandler()->getReferenceContainerList()->at(i).addVariantBlock(vb);
                added = true;
                break;
            }
            break;
        }
        if (!added) {
            std::cerr << "cannot add variant because no space to add" << std::endl;
            exit(1);
        }
    }
}
