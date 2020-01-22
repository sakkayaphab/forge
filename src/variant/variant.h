//
// Created by Sakkayaphab Piwluang on 19/1/20.
//

#ifndef FORGE_VARIANT_H
#define FORGE_VARIANT_H


#include <cstdint>
#include <string>

class Variant {
    std::string chrpos;
    int64_t pos=0;
    std::string chrend;
    int64_t end=0;
    std::string svtype;

public:
    Variant();
};


#endif //FORGE_VARIANT_H
