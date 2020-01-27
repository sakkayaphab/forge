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
#include <vector>
#include "config.h"
#include "seqmod.h"
#include <stdlib.h>
#include "approxvariation.h"
class Sim {
    private:
        std::string fastaPath;
        Config config;

    public:
        Sim();
        void setFastaPath(std::string path);
        std::string getFastaPath();
        std::string getFastaIndexPath();
        void readFasta();
};


#endif //FORGE_SIM_H
