//
// Created by Sakkayaphab Piwluang on 24/1/20.
//

#ifndef FORGE_BLOCKCONTAINER_H
#define FORGE_BLOCKCONTAINER_H

#include "block.h"
#include <vector>


class BlockContainer {
    std::vector<Block> blocks;
    std::string chrname;
public:
    BlockContainer();
    void setBlocks(std::vector<Block> blocks);
    void setChr(std::string chrname);
    std::string getChr();
    uint64_t getSumLength();
    std::vector<std::string> getBlockTextList();

};


#endif //FORGE_BLOCKCONTAINER_H
