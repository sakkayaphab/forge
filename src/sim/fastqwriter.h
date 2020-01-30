//
// Created by Sakkayaphab Piwluang on 29/1/20.
//

#ifndef FORGE_FASTQWRITER_H
#define FORGE_FASTQWRITER_H

#include <string>
#include <iostream>
#include "config.h"
#include <string_view>
#include <fstream>
class FastqWriter {

private:
    std::string_view *sequence;
    std::string outputpath;
    Config *config;
    int64_t length;
    std::string chr = "chr1";

public:
    FastqWriter();
    void setSequence(std::string_view *sequence);
    void setOutputPath(std::string outputpath);
    void setConfig(Config *config);
    Config *getConfig();
    void writeSequence();
    void writeSingleEnd();
    void setLength(int64_t length);
    std::string getBaseQ(int64_t length);
    std::string_view *getSequence();
};


#endif //FORGE_FASTQWRITER_H
