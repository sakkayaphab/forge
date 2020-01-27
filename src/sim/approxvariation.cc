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
    std::vector<VariantionConfig> vc = getConfig()->getVariantionConfig();

}
