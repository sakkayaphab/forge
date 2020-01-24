//
// Created by Sakkayaphab Piwluang on 24/1/20.
//

#include "containermanager.h"


ContainerManager::ContainerManager() {

}

std::vector<BlockContainer> ContainerManager::getBlockContainers() {
    return ContainerManager::blockcontainers;
}

void ContainerManager::setBlockContainers(std::vector<BlockContainer> bcs) {
    ContainerManager::blockcontainers = bcs;
}