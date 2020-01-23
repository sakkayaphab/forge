//
// Created by Sakkayaphab Piwluang on 24/1/20.
//

#ifndef FORGE_BLOCK_H
#define FORGE_BLOCK_H


#include <cstdint>
#include <string>

class Block {
private:
    std::string chrpos;
    int64_t pos=0;
    int64_t end=0;
public:
    Block();
    int64_t getPos();
    int64_t getEnd();
    void setPos(int64_t pos);
    void setEnd(int64_t end);
    std::string getChrPos();
    void setChrPos(std::string chrpos);
};


#endif //FORGE_BLOCK_H
