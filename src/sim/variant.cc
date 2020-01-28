//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#include "variant.h"

Variant::Variant() {

}

void Variant::setPos(int64_t pos) {
    Variant::pos = pos;
}

int64_t Variant::getPos() {
    return Variant::pos;
}

void Variant::setEnd(int64_t end) {
    Variant::end = end;
}

int64_t Variant::getEnd() {
    return Variant::end;
}

void Variant::setSvType(std::string svtype) {
    Variant::svtype = svtype;
}

std::string Variant::getSvtype() {
    return std::string();
}

void Variant::setAlt(std::string alt) {
    Variant::alt = alt;
}

std::string Variant::getAlt() {
    return Variant::alt;
}

void Variant::setRef(std::string ref) {
    Variant::ref = ref;
}

std::string Variant::getRef() {
    return Variant::ref;
}

void Variant::setSpace(int64_t bases) {
    Variant::space = bases;
}

int64_t Variant::getSpace() {
    return Variant::space;
}

int64_t Variant::getPosWithSpace() {
    return Variant::getPos() - Variant::getSpace();
}

int64_t Variant::getEndWithSpace() {
    return Variant::getEnd() + Variant::getSpace();
}

void Variant::setAltLength(int64_t altLength) {
    Variant::altLength = altLength;
}

int64_t Variant::getAltLength() {
    return Variant::altLength;
}
