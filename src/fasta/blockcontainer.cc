//
// Created by Sakkayaphab Piwluang on 24/1/20.
//

#include "blockcontainer.h"


BlockContainer::BlockContainer() {

}


void BlockContainer::setBlocks(std::vector<Block> blocks) {
    BlockContainer::blocks = blocks;
}


void BlockContainer::setChr(std::string chrname) {
    BlockContainer::chrname = chrname;
}

std::string BlockContainer::getChr() {
    return BlockContainer::chrname;
}

uint64_t BlockContainer::getSumLength() {
    uint64_t sumLength = 0;
    for (Block b:blocks) {
        sumLength += b.getEnd()-b.getPos();
    }
    return sumLength;
}

std::vector<std::string> BlockContainer::getBlockTextList() {
    std::vector<std::string> blocktextlist;
    for (Block b:blocks) {
        std::string temp;
        temp += b.getTextPos();
        temp += "\t";
        temp += b.getTextEnd();
        blocktextlist.push_back(temp);
    }

    return blocktextlist;
}