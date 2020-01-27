//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#ifndef FORGE_FASTQWRITER_H
#define FORGE_FASTQWRITER_H

#include <string>

class FastqWriter {
private:
    std::string instrumentname;
    std::string flowcell;
    std::string tilenumber;
    std::string xcoordinate;
    std::string ycoordinate;
    std::string indexnumber;
    std::string memberofpair;

    std::string fastqoutputpath;
public:
    FastqWriter();
    void setFastqOutputPath(std::string fastqoutputpath);
    std::string getFastqOutputPath();
    void writeFastq();
};


#endif //FORGE_FASTQWRITER_H
