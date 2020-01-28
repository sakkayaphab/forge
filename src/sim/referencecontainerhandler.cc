//
// Created by Sakkayaphab Piwluang on 28/1/20.
//

#include "referencecontainerhandler.h"

ReferenceContainerHandler::ReferenceContainerHandler() {

}

void ReferenceContainerHandler::addContainerManagerToReferenceContainer(ContainerManager cm) {
    for (BlockContainer j:cm.getBlockContainers()) {
        for (Block k:j.getBlocks()) {
            ReferenceContainer tempRC;
            tempRC.setChr(k.getChr());
            tempRC.setPos(k.getPos());
            tempRC.setEnd(k.getEnd());
            tempRC.setOrderNumber(orderBC);
            orderBC++;
            referencecontainerlist.push_back(tempRC);
        }
    }
}

void ReferenceContainerHandler::showReferenceContainer() {
    for (ReferenceContainer x:referencecontainerlist) {
        std::cout << x.getPos() << " " << x.getEnd() << " > " << x.getVariantBlocks().size() << std::endl;
    }
}

void ReferenceContainerHandler::shuffleReferenceContainer() {
    std::shuffle(std::begin(ReferenceContainerHandler::referencecontainerlist), std::end(ReferenceContainerHandler::referencecontainerlist), rnge);
}