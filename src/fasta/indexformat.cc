//
// Created by Sakkayaphab Piwluang on 26/1/20.
//

#include "indexformat.h"

IndexFormat::IndexFormat() {

}

std::string IndexFormat::getName() {
    return IndexFormat::NAME;
}

int64_t IndexFormat::getLength() {
    return IndexFormat::LENGTH;
}

int64_t IndexFormat::getOffset() {
    return IndexFormat::OFFSET;
}

int64_t IndexFormat::getLineBases() {
    return IndexFormat::LINEBASES;
}

int64_t IndexFormat::getLineWidth() {
    return IndexFormat::LINEWIDTH;
}

int64_t IndexFormat::getQualOffset() {
    return IndexFormat::QUALOFFSET;
}

void IndexFormat::setName(std::string NAME) {
    IndexFormat::NAME = NAME;
}

void IndexFormat::setLength(int64_t LENGTH) {
    IndexFormat::LENGTH = LENGTH;
}

void IndexFormat::setOffset(int64_t OFFSET) {
    IndexFormat::OFFSET = OFFSET;
}

void IndexFormat::setLineBases(int64_t LINEBASES) {
    IndexFormat::LINEBASES = LINEBASES;
}

void IndexFormat::setLineWidth(int64_t LINEWIDTH) {
    IndexFormat::LINEWIDTH = LINEWIDTH;
}

void IndexFormat::setQualOffset(int64_t QUALOFFSET) {
    IndexFormat::QUALOFFSET = QUALOFFSET;
}
