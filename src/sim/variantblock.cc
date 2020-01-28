//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#include "variantblock.h"

VariantBlock::VariantBlock() {

}

void VariantBlock::setPos(int64_t pos) {
    VariantBlock::pos = pos;
}

int64_t VariantBlock::getPos() {
    return VariantBlock::pos;
}

void VariantBlock::setEnd(int64_t end) {
    VariantBlock::end = end;
}

int64_t VariantBlock::getEnd() {
    return VariantBlock::end;
}

void VariantBlock::setSvType(std::string svtype) {
    VariantBlock::svtype = svtype;
}

std::string VariantBlock::getSvtype() {
    return VariantBlock::svtype;
}

void VariantBlock::setAlt(std::string alt) {
    VariantBlock::alt = alt;
}

std::string VariantBlock::getAlt() {
    return VariantBlock::alt;
}

void VariantBlock::setRef(std::string ref) {
    VariantBlock::ref = ref;
}

std::string VariantBlock::getRef() {
    return VariantBlock::ref;
}

void VariantBlock::setSpace(int64_t bases) {
    VariantBlock::space = bases;
}

int64_t VariantBlock::getSpace() {
    return VariantBlock::space;
}

int64_t VariantBlock::getPosWithSpace() {
    return VariantBlock::getPos() - VariantBlock::getSpace();
}

int64_t VariantBlock::getEndWithSpace() {
    return VariantBlock::getEnd() + VariantBlock::getSpace();
}

void VariantBlock::setAppxAltLength(int64_t altLength) {
    VariantBlock::appxAltLength = altLength;
}

void VariantBlock::setAppxRefLength(int64_t refLength) {
    VariantBlock::appxRefLength = refLength;
}

int64_t VariantBlock::getAppxAltLength() {
    return VariantBlock::appxAltLength;
}

int64_t VariantBlock::getAppxRefLength() {
    return VariantBlock::appxRefLength;
}

int64_t VariantBlock::getAppxRefLengthWithSpace() {
    return VariantBlock::appxRefLength + (VariantBlock::getSpace() * 2);
}

void VariantBlock::show() {
    std::cout << "svtype: " << getSvtype()  << " length: " << getAppxRefLengthWithSpace() << " space: " << getSpace() << std::endl;
}
