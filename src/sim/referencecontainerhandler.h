//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#ifndef FORGE_REFERENCECONTAINERHANDLER_H
#define FORGE_REFERENCECONTAINERHANDLER_H

#include <vector>
#include <string>
#include "referencecontainer.h"
#include <fasta/containermanager.h>
#include <algorithm>
#include <random>

class ReferenceContainerHandler {
private:
    std::vector<ReferenceContainer> referencecontainerlist;
    int64_t orderBC=0;
    unsigned seed=0;
    std::default_random_engine rnge;

public:
    ReferenceContainerHandler();
    void addContainerManagerToReferenceContainer(ContainerManager cm);
    void showReferenceContainer();
    void shuffleReferenceContainer();
    int64_t getSize();
    void setSeed(unsigned seed);
    unsigned getSeed();
    std::vector<ReferenceContainer> *getReferenceContainerList();
};


#endif //FORGE_REFERENCECONTAINERHANDLER_H
