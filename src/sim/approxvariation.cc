//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#include "approxvariation.h"

ApproxVariation::ApproxVariation() {

}

void ApproxVariation::setConfig(Config *cfg) {
    ApproxVariation::config = cfg;
}

Config *ApproxVariation::getConfig() {
    return ApproxVariation::config;
}

void ApproxVariation::setContainerManager(ContainerManager *cm) {
    ApproxVariation::containermanager = cm;
}

ContainerManager *ApproxVariation::getContainerManager() {
    return ApproxVariation::containermanager;
}

void ApproxVariation::execute() {
    std::vector<BlockContainer> bcs = getContainerManager()->getBlockContainers();
    std::vector<Block> blocks = bcs.at(0).getBlocks();
    for (Block bk:blocks) {
        std::cout << bk.getChr() << " " << bk.getPos() << " " << bk.getEnd() << std::endl;
    }

//    std::vector<VariantionConfig> vcs = getConfig()->getVariantionConfig();
//    for (VariantionConfig vc:vcs) {
//
//    }
}
