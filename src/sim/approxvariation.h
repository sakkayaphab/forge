//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#ifndef FORGE_APPROXVARIATION_H
#define FORGE_APPROXVARIATION_H

#include <string>
#include "config.h"
#include "fasta/containermanager.h"

class ApproxVariation {
    Config *config;
    ContainerManager *containermanager;
public:
    ApproxVariation();
    void setConfig(Config *cfg);
    Config *getConfig();
    void setContainerManager(ContainerManager *cm);
    ContainerManager *getContainerManager();
    void execute();


};


#endif //FORGE_APPROXVARIATION_H
