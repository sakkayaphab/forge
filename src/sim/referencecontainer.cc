//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#include "referencecontainer.h"

ReferenceContainer::ReferenceContainer() {

}

void ReferenceContainer::setChr(std::string chr) {
    ReferenceContainer::chr = chr;
}

void ReferenceContainer::setPos(int64_t pos) {
    ReferenceContainer::pos = pos;
}

void ReferenceContainer::setEnd(int64_t end) {
    ReferenceContainer::end = end;
}

int64_t ReferenceContainer::getPos() {
    return ReferenceContainer::pos;
}

int64_t ReferenceContainer::getEnd() {
    return ReferenceContainer::end;
}

std::string ReferenceContainer::getChr() {
    return ReferenceContainer::chr;
}

void ReferenceContainer::setVariantBlocks(std::vector<VariantBlock> variantblocklist) {
    ReferenceContainer::variantblocklist = variantblocklist;
}

std::vector<VariantBlock> ReferenceContainer::getVariantBlocks() {
    return ReferenceContainer::variantblocklist;
}

void ReferenceContainer::addVariantBlock(VariantBlock vb) {
    ReferenceContainer::variantblocklist.push_back(vb);
}

void ReferenceContainer::setOrderNumber(int64_t ordernumber) {
    ReferenceContainer::ordernumber = ordernumber;
}

int64_t ReferenceContainer::getOrderNumber() {
    return ReferenceContainer::ordernumber;
}

bool ReferenceContainer::haveSpaceToAdd(VariantBlock vb) {
    std::cout << "vb.getAppxRefLengthWithSpace() : " << vb.getAppxRefLengthWithSpace() << std::endl;
    std::cout << "getFreeSpace() : " << getFreeSpace() << std::endl;

    if (getFreeSpace()>=vb.getAppxRefLengthWithSpace()) {
        return true;
    }
    return false;
}

int64_t ReferenceContainer::getAllVariantBlockSize() {
    int64_t totalsize = 0;
    for (VariantBlock n:ReferenceContainer::getVariantBlocks()) {
        totalsize += n.getAppxRefLengthWithSpace();
    }
    return totalsize;
}

int64_t ReferenceContainer::getCapacity() {
    return ReferenceContainer::getEnd()-ReferenceContainer::getPos();
}

int64_t ReferenceContainer::getFreeSpace() {
    return ReferenceContainer::getCapacity()-ReferenceContainer::getAllVariantBlockSize();
}
