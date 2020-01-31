//
// Created by Sakkayaphab Piwluang on 31/1/20.
//

#ifndef FORGE_FASTAWRITER_H
#define FORGE_FASTAWRITER_H

#include <string>
#include <iostream>
#include <fstream>
class FastaWriter {
private:
public:
    FastaWriter();
    void writeRefFile(std::string filepath, std::string *seq, std::string chr, int64_t pos, int64_t end);
};


#endif //FORGE_FASTAWRITER_H
