//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#ifndef FORGE_REFERENCECONTAINERHANDLER_H
#define FORGE_REFERENCECONTAINERHANDLER_H

#include <vector>
#include <string>
#include "referencecontainer.h"
#include <fasta/containermanager.h>
class ReferenceContainerHandler {
private:
    std::vector<ReferenceContainer> referencecontainerlist;
    int64_t orderBC=0;

public:
    ReferenceContainerHandler();
    void addContainerManagerToReferenceContainer(ContainerManager cm);
    void showReferenceContainer();
};


#endif //FORGE_REFERENCECONTAINERHANDLER_H
