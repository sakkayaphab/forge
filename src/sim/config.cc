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
