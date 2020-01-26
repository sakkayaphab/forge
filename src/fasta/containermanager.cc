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

void ContainerManager::writeBlockContainerTextFile(std::string outpath) {
    std::vector<std::string> textlist;
    std::ofstream myfile;
    myfile.open(outpath);

    for (BlockContainer bc : blockcontainers) {
        std::vector<std::string> list = bc.getBlockTextList();
        myfile << "#" << bc.getChr() << std::endl;
        for (std::string x:list) {
            myfile << x << std::endl;
        }
    }

    myfile.close();
}

void ContainerManager::loadBlockContainersFromFile(std::string filepath) {
    std::ifstream file(filepath);
    std::string line;
    std::string chrnow;
    std::vector<Block> blocks;
    while (std::getline(file, line)) {
        if (line.length() == 0) {
            continue;
        }

        if (line[0] == '#') {
            if (blocks.size() != 0) {
                BlockContainer blockcontainer;
                blockcontainer.setBlocks(blocks);
                blockcontainer.setChr(chrnow);
                blocks.clear();
                ContainerManager::blockcontainers.push_back(blockcontainer);
            }
            chrnow = line.substr(1);
        } else {
            std::vector<std::string> results = split(line, '\t');
            Block block;
            block.setChr(chrnow);
            block.setTextPos(results.at(0));
            block.setTextEnd(results.at(1));
            blocks.push_back(block);
        }
    }
}

std::vector<std::string> ContainerManager::split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void ContainerManager::showBlockContainers() {
    for (BlockContainer bc:blockcontainers) {
        std::cout << bc.getChr() << " " << bc.getSumLength() << std::endl;
    }
}