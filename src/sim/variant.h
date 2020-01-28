//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#ifndef FORGE_VARIANT_H
#define FORGE_VARIANT_H


#include <cstdint>
#include <string>

class Variant {
private:
    int64_t pos = 0;
    int64_t end = 0;
    int64_t altLength = 0;
    std::string svtype;
    std::string alt;
    std::string ref;
    int64_t space = 0;


public:
    Variant();

    void setPos(int64_t pos);

    int64_t getPos();

    void setEnd(int64_t end);

    int64_t getEnd();

    void setAltLength(int64_t altLength);

    int64_t getAltLength();

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
};


#endif //FORGE_VARIANT_H
