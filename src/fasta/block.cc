//
// Created by Sakkayaphab Piwluang on 24/1/20.
//

#include "block.h"


Block::Block() {

}

int64_t Block::getPos() {
    return Block::pos;
}

int64_t Block::getEnd() {
    return Block::end;
}

void Block::setPos(int64_t pos) {
    Block::pos = pos;
}

void Block::setEnd(int64_t end) {
    Block::end = end;
}

std::string Block::getChrPos() {
    return Block::chrpos;
}

std::string Block::getChrEnd() {
    return Block::chrend;
}

void Block::setChrPos(std::string chrpos) {
    Block::chrpos = chrpos;
}

void Block::setChrEnd(std::string chrend) {
    Block::chrend = chrend;
}