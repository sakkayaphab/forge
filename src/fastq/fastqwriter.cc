//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#include "fastqwriter.h"

FastqWriter::FastqWriter() {

}

void FastqWriter::setFastqOutputPath(std::string fastqoutputpath) {
    FastqWriter::fastqoutputpath = fastqoutputpath;
}

std::string FastqWriter::getFastqOutputPath() {
    return FastqWriter::fastqoutputpath;
}

void FastqWriter::writeFastq() {

}
