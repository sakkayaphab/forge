//
// Created by Sakkayaphab Piwluang on 23/1/20.
//

#ifndef FORGE_SIM_H
#define FORGE_SIM_H

#include "fasta/blockreference.h"
#include <iostream>

class Sim {
    private:
        std::string fastaPath;
    public:
        Sim();
        void setFastaPath(std::string path);
        void readFasta();
};


#endif //FORGE_SIM_H
