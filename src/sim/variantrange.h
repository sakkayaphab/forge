//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#ifndef FORGE_VARIANTRANGE_H
#define FORGE_VARIANTRANGE_H


#include <cstdint>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class VariantRange {
    int64_t maxlength;
    int64_t minlength;
    int number;
public:
    VariantRange();

    template<typename T, typename P>
    T remove_if(T beg, T end, P pred)
    {
        T dest = beg;
        for (T itr = beg;itr != end; ++itr)
            if (!pred(*itr))
                *(dest++) = *itr;
        return dest;
    }

    void setMaxLength(int64_t max);
    void setMinLength(int64_t min);
    void setNumber(int number);
    int64_t getMaxLength();
    int64_t getMinLength();
    int getNumber();
    void setTextRange(std::string textrange);
    std::vector<std::string> split(const std::string &s, char delimiter);
    int64_t convertStringToInt64(std::string text);

};


#endif //FORGE_VARIANTRANGE_H
