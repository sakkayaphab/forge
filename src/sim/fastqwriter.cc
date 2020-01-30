//
// Created by Sakkayaphab Piwluang on 29/1/20.
//

#include "fastqwriter.h"

FastqWriter::FastqWriter() {

}

void FastqWriter::setSequence(std::string_view *sequence) {
    FastqWriter::sequence = sequence;
    FastqWriter::setLength(FastqWriter::sequence->size());
}

void FastqWriter::setOutputPath(std::string outputpath) {
    FastqWriter::outputpath = outputpath;
}

std::string_view *FastqWriter::getSequence() {
    return FastqWriter::sequence;
}

void FastqWriter::writeSequence() {
    std::cout << FastqWriter::getSequence()->size() << std::endl;
    FastqWriter::writeSingleEnd();
}

void FastqWriter::setConfig(Config *config) {
    FastqWriter::config = config;
}

Config *FastqWriter::getConfig() {
    return FastqWriter::config;
}

void FastqWriter::setLength(int64_t length) {
    FastqWriter::length = length;
}

void FastqWriter::writeSingleEnd() {
    int64_t lastpos = 0;
    int64_t space = 40;
    int64_t readlength = 30000;
    std::ofstream myfile;
    std::string baseq;
    int64_t numberbaseq = 0;
    myfile.open ("example.txt", std::fstream::app);
    for (;readlength+space+lastpos<FastqWriter::length;) {
//        (*sequence).substr(lastpos+space,lastpos+readlength+space).size();
//        std::string_view *seq = getSequenceByPos(lastpos+space,lastpos+readlength+space);
        if (numberbaseq!= readlength) {
            baseq = getBaseQ(readlength);
        }

        myfile << "@"+chr+"_"+std::to_string(lastpos+space)+"_"+std::to_string(lastpos+space+readlength)+"_3:0:0_2:0:0_0/1\n";
        myfile << (*sequence).substr(lastpos+space,readlength) << "\n+\n";
        myfile << baseq << "\n";
        std::cout << "pos : " << lastpos+space << " end : " << lastpos+readlength+space << " - " << (*sequence).substr(lastpos+space,readlength).size() << std::endl;

        lastpos = readlength+space+lastpos;
    }
    myfile.close();
}

std::string FastqWriter::getBaseQ(int64_t length) {
    std::string s(length, '2');
    return s;
}
