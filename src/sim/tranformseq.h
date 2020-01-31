//
// Created by Sakkayaphab Piwluang on 31/1/20.
//

#ifndef FORGE_TRANFORMSEQ_H
#define FORGE_TRANFORMSEQ_H

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

class TranformSeq {
private:
public:
    TranformSeq();
    void ConvertSyntax(std::string syntax);
    std::vector<std::string> split(const std::string &s, char delimiter);
    void splitSvMethod(std::string source,std::string *svtype,std::vector<std::string> *regions);
};


#endif //FORGE_TRANFORMSEQ_H
