//
// Created by Sakkayaphab Piwluang on 24/1/20.
//

#ifndef FORGE_CONTAINERMANAGER_H
#define FORGE_CONTAINERMANAGER_H

#include "blockcontainer.h"

class ContainerManager {
    private:
        std::vector<BlockContainer> blockcontainers;

    public:
        ContainerManager();
        std::vector<BlockContainer> getBlockContainers();
        void setBlockContainers(std::vector<BlockContainer> bc);
};


#endif //FORGE_CONTAINERMANAGER_H
