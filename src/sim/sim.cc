//
// Created by Sakkayaphab Piwluang on 23/1/20.
//

#include "sim.h"

Sim::Sim() {

}

void Sim::setFastaPath(std::string path) {
    Sim::fastaPath = path;
}

void Sim::readFasta() {
    FastaReader fastareader;
    fastareader.setFilePath(fastaPath);
    fastareader.setIndexFilePath(fastaPath+".fai");
    fastareader.initialize();
    fastareader.exitIfNoFilePath();
    ContainerManager cm  = fastareader.getAllChrBlockContainerWithSingleThread();
    cm.showBlockContainers();

}