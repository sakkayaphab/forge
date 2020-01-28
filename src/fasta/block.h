//
// Created by Sakkayaphab Piwluang on 24/1/20.
//

#ifndef FORGE_BLOCK_H
#define FORGE_BLOCK_H


#include <string>
#include <sstream>
#include <iostream>

class Block {
private:
    std::string chr;
    int64_t pos=0;
    int64_t end=0;
public:
    Block();
    int64_t getPos();
    int64_t getEnd();
    void setPos(unsigned pos);
    void setEnd(unsigned end);
    std::string getChr();
    void setChr(std::string chrpos);
    std::string getTextPos();
    std::string getTextEnd();
    void setTextPos(std::string textpos);
    void setTextEnd(std::string textend);

};


#endif //FORGE_BLOCK_H
