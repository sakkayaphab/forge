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
