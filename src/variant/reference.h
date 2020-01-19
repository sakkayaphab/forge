//
// Created by Sakkayaphab Piwluang on 19/1/20.
//

#ifndef FORGE_REFERENCE_H
#define FORGE_REFERENCE_H

#include <string>
#include "fasta/fastareader.h"

class Reference {
private:
    std::string fastapath;
    std::string fastaindexpath;
//    FastaReader fastaReader;


public:
    Reference();
    std::string getFastaPath();
    void setFastaPath(std::string fastapath);
    std::string getFastaIndexPath();
    void setFastaIndexPath(std::string fastaindexpath);
//    void getAllInfo();
};


#endif //FORGE_REFERENCE_H
