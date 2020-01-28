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
//    ArrangementContainer::runDumpVariantWorstFitDecreasing();
        ArrangementContainer::runDumpVariantRound();
}

void ArrangementContainer::runDumpVariantWorstFitDecreasing() {
    std::cout << getReferenceContainerHandler()->getSizeReferenceContainer() << std::endl;
    for (VariantBlock vb:getVariantBin()->getVariantList()) {
        bool added = false;

        for (int64_t i =0;i< getReferenceContainerHandler()->getSizeReferenceContainer(); i++) {
            if (getReferenceContainerHandler()->getReferenceContainerList()->at(i).haveSpaceToAdd(vb)) {
                getReferenceContainerHandler()->getReferenceContainerList()->at(i).addVariantBlock(vb);
                added = true;
                break;
            }
        }
        if (!added) {
            std::cerr << "ERR : cannot add variant because no space to add" << std::endl;
            exit(1);
        }
    }
}

void ArrangementContainer::runDumpVariantRound() {
    std::cout << getReferenceContainerHandler()->getSizeReferenceContainer() << std::endl;
    int64_t position=0;
    for (VariantBlock vb:getVariantBin()->getVariantList()) {
        bool added = false;

        int passed = false;
        for (;;) {
            position++;
            if (position>= getReferenceContainerHandler()->getSizeReferenceContainer()) {
                if (passed) {
                    std::cerr << "ERR : cannot add variant because no space to add" << std::endl;
                    exit(1);
                }
                position = 0;
                passed = true;
            }
            if (getReferenceContainerHandler()->getReferenceContainerList()->at(position).haveSpaceToAdd(vb)) {
                getReferenceContainerHandler()->getReferenceContainerList()->at(position).addVariantBlock(vb);
                added = true;
                break;
            }
        }

        if (!added) {
            std::cerr << "ERR : cannot add variant because no space to add" << std::endl;
            exit(1);
        }
    }
}

void ArrangementContainer::showReferenceContainerContainVaraintOnly() {
    for (ReferenceContainer n:*getReferenceContainerHandler()->getReferenceContainerList()) {
        if (n.getVariantBlocks().size()!=0) {
            n.showSummary();
        }
    }
}
