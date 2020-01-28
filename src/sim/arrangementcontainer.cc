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
    ArrangementContainer::rch =rch;
}

VariantBinHandler *ArrangementContainer::getVariantBin() {
    return ArrangementContainer::variantbin;
}

ReferenceContainerHandler *ArrangementContainer::getReferenceContainerHandler() {
    return ArrangementContainer::rch;
}

void ArrangementContainer::execute() {
    
}
