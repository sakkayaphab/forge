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

void Block::setPos(unsigned pos) {
    Block::pos = pos;
}

void Block::setEnd(unsigned end) {
    Block::end = end;
}

std::string Block::getChr() {
    return Block::chr;
}

void Block::setChr(std::string chr) {
    Block::chr = chr;
}

std::string Block::getTextPos() {
    return std::to_string(pos);
}

std::string Block::getTextEnd() {
    return std::to_string(end);
}

void Block::setTextPos(std::string textpos) {
    pos = stoul(textpos, 0, 10);
}

void Block::setTextEnd(std::string textend) {
    end = stoul(textend, 0, 10);
}

void Block::setSeq(std::string seq) {
    Block::seq = seq;
}

std::string Block::getSeq() {
    return Block::seq;
}
