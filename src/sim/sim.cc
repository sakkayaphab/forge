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
    BlockReference blockref(Sim::fastaPath);
    uint64_t numberIDs = blockref.getNumberOfRef();
//    std::cout << numberIDs << std::endl;
//    blockref.getAllChrBlockContainer();

    BlockContainer bc = blockref.getBlockContainerByID(0);
    std::cout << bc.getSumLength() << std::endl;

}