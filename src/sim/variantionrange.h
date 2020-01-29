//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#ifndef FORGE_VARIANTIONRANGE_H
#define FORGE_VARIANTIONRANGE_H


#include <cstdint>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class VariantionRange {
private:
    int64_t maxlength=0;
    int64_t minlength=0;
    int number=0;

public:
    VariantionRange();

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
    void setTextMaxLength(std::string max);
    void setTextMinLength(std::string min);
    void setNumber(int number);
    int64_t getMaxLength();
    int64_t getMinLength();
    int getNumber();
    void setTextRange(std::string textrange);
    void setTextNumber(std::string number);
    std::vector<std::string> split(const std::string &s, char delimiter);
    int64_t convertStringToInt64(std::string text);
    int convertStringToInt(std::string text);

};


#endif //FORGE_VARIANTIONRANGE_H
