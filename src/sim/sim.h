//
// Created by Sakkayaphab Piwluang on 23/1/20.
//

#ifndef FORGE_SIM_H
#define FORGE_SIM_H

#include <iostream>
#include <fstream>
#include <string>
#include <fasta/fastareader.h>
#include <vcf/vcfwriter.h>
#include <vcf/dataline.h>
class Sim {
    private:
        std::string fastaPath;
    public:
        Sim();
        void setFastaPath(std::string path);
        void readFasta();
};


#endif //FORGE_SIM_H
