//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#include "variation.h"

Variation::Variation() {

}

void Variation::setPos(int64_t pos) {
    Variation::pos = pos;
}

int64_t Variation::getPos() {
    return Variation::pos;
}

void Variation::setEnd(int64_t end) {
    Variation::end = end;
}

int64_t Variation::getEnd() {
    return Variation::end;
}

void Variation::setSvType(std::string svtype) {
    Variation::svtype = svtype;
}

std::string Variation::getSvtype() {
    return std::string();
}

void Variation::setAlt(std::string alt) {
    Variation::alt = alt;
}

std::string Variation::getAlt() {
    return Variation::alt;
}

void Variation::setRef(std::string ref) {
    Variation::ref = ref;
}

std::string Variation::getRef() {
    return Variation::ref;
}

void Variation::setSpace(int64_t bases) {
    Variation::space = bases;
}


int64_t Variation::getSpace() {
    return Variation::space;
}


int64_t Variation::getPosWithSpace() {
    return Variation::getPos()-Variation::getSpace();
}

int64_t Variation::getEndWithSpace() {
    return Variation::getEnd()+Variation::getSpace();
}

void Variation::setAltLength(int64_t altLength) {
    Variation::altLength = altLength;
}

int64_t Variation::getAltLength() {
    return Variation::altLength;
}
