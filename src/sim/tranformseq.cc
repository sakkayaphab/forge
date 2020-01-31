//
// Created by Sakkayaphab Piwluang on 31/1/20.
//

#include "tranformseq.h"

TranformSeq::TranformSeq() {

}

std::vector<std::string> TranformSeq::split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void TranformSeq::ConvertSyntax(std::string syntax) {
    std::cout << syntax << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::vector<std::string> listsplit = split(syntax,';');
    for (std::string x:listsplit) {
        if (x.size()==1) {
            std::cout << x << std::endl;
        } else {
            splitSvMethod(x,NULL,NULL);
        }
    }
}

void TranformSeq::splitSvMethod(std::string source, std::string *svtype, std::vector<std::string> *regions) {
    std::cout << source.substr(0,3) << std::endl;
    std::vector<std::string> listsplit = split( source.substr(4,source.size()-4-1),',');
    for (std::string x:listsplit) {
        std::cout << x << std::endl;
    }
}
