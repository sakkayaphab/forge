//
// Created by Sakkayaphab Piwluang on 24/1/20.
//

#ifndef FORGE_CONTAINERMANAGER_H
#define FORGE_CONTAINERMANAGER_H

#include "blockcontainer.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class ContainerManager {
    private:
        std::vector<BlockContainer> blockcontainers;

    public:
        ContainerManager();
        std::vector<BlockContainer> getBlockContainers();
        void setBlockContainers(std::vector<BlockContainer> bc);
        void writeBlockContainerTextFile(std::string outpath);
        void loadBlockContainersFromFile(std::string filepath);
        std::vector<std::string> split(const std::string &s, char delimiter);
        void showBlockContainers();
        void removeAllBlocksSmallerThan(int64_t bases);
};


#endif //FORGE_CONTAINERMANAGER_H
