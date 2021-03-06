//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#ifndef FORGE_VARIANTBLOCK_H
#define FORGE_VARIANTBLOCK_H


#include <cstdint>
#include <string>
#include <iostream>
class VariantBlock {
private:
    int64_t pos = 0;
    int64_t end = 0;
    int64_t appxAltLength = 0;
    int64_t appxRefLength = 0;
    std::string svtype;
    std::string alt;
    std::string ref;
    int64_t space = 0;


public:
    VariantBlock();

    void setPos(int64_t pos);

    int64_t getPos();

    void setEnd(int64_t end);

    int64_t getEnd();

    void setAppxAltLength(int64_t altLength);
    void setAppxRefLength(int64_t refLength);
    int64_t getAppxRefLengthWithSpace();
    int64_t getAppxAltLength();
    int64_t getAppxRefLength();

    void setSvType(std::string svtype);

    std::string getSvtype();

    void setAlt(std::string alt);

    std::string getAlt();

    void setRef(std::string ref);

    std::string getRef();

    void setSpace(int64_t bases);

    int64_t getSpace();

    int64_t getPosWithSpace();

    int64_t getEndWithSpace();
    void show();
};


#endif //FORGE_VARIANTBLOCK_H
