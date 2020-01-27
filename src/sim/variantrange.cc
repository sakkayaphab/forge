//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#include "variantrange.h"

VariantRange::VariantRange() {

}

void VariantRange::setMax(int64_t max) {
    VariantRange::max = max;
}

void VariantRange::setMin(int64_t min) {
    VariantRange::min = min;
}

void VariantRange::setNumber(int number) {
    VariantRange::number = number;
}

int64_t VariantRange::getMax() {
    return VariantRange::max;
}

int64_t VariantRange::getMin() {
    return VariantRange::min;
}

int VariantRange::getNumber() {
    return VariantRange::number;
}
