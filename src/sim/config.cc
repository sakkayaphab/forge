//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#include "config.h"

Config::Config() {

}

void Config::setReferencePath(std::string referencepath) {
    Config::referencepath = referencepath;
}

void Config::setReferenceIndexPath(std::string referenceindexpath) {
    Config::referenceindexpath = referenceindexpath;
}

void Config::setOutputDirectoryPath(std::string outputDirectoryPath) {
    Config::outputdirectorypath = outputDirectoryPath;
}

void Config::setThreads(int threads) {
    Config::threads = threads;
}

std::string Config::getReferencePath() {
    return Config::referencepath;
}

std::string Config::getReferenceIndexPath() {
    return Config::referenceindexpath;
}

std::string Config::getOutputDirectoryPath() {
    return Config::outputdirectorypath;
}

int Config::getThreads() {
    return Config::threads;
}

void Config::setSequencing(std::string sequencing) {
    Config::sequencing = sequencing;
}

std::string Config::getSequencing() {
    return Config::sequencing;
}

void Config::setTextThreads(std::string threads) {

}

void Config::setReadlength(int readlength) {

}

void Config::setTextReadlength(std::string readlength) {

}

void Config::setAverageInsertSize(int64_t averageinsertsize) {

}

void Config::setTextAverageInsertSize(std::string averageinsertsize) {

}

void Config::setSD(int64_t sd) {

}

void Config::setTextSD(std::string sd) {

}

void Config::setBaseErrorRate(float baseerrorrate) {

}

void Config::setTextBaseErrorRate(std::string baseerrorrate) {

}

void Config::setCoverage(int64_t coverage) {

}

void Config::setTextCoverage(std::string coverage) {

}

int Config::getReadLength() {
    return 0;
}

int64_t Config::getAverageInsertSize() {
    return 0;
}

int64_t Config::getSD() {
    return 0;
}

float Config::getBaseErrorRate() {
    return 0;
}

int64_t Config::getCoverage() {
    return 0;
}

int64_t Config::convertStringToInt64(std::string text) {
    int64_t value = std::strtoll(text.c_str(), NULL, 0);
    return value;
}

int Config::convertStringToInt(std::string text) {
    int64_t value = std::stoi(text.c_str(), NULL, 0);
    return value;
}

float Config::convertStringToFloat(std::string text) {
    float number = std::strtof(text.c_str(), 0);
    return number;
}