//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#ifndef FORGE_VARIANTRANGE_H
#define FORGE_VARIANTRANGE_H


#include <cstdint>

class VariantRange {
    int64_t max;
    int64_t min;
    int number;
public:
    VariantRange();
    void setMax(int64_t max);
    void setMin(int64_t min);
    void setNumber(int number);
    int64_t getMax();
    int64_t getMin();
    int getNumber();
};


#endif //FORGE_VARIANTRANGE_H
