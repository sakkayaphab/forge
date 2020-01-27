//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#include "config.h"

Config::Config() {

}


void Config::readConfigFile() {

    YAML::Node configNode = YAML::LoadFile("../templates/custom.yaml");
    if (configNode["files"]["input"]["reference"]) {
        std::string reference = configNode["files"]["input"]["reference"].as<std::string>();
        std::cout << reference << std::endl;
        Config::setReferencePath(reference);
    }
    if (configNode["files"]["output"]["output_directory"]) {
        std::string outputdirectory = configNode["files"]["output"]["output_directory"].as<std::string>();
        std::cout << outputdirectory << std::endl;
        Config::setOutputDirectoryPath(outputdirectory);
    }
    if (configNode["files"]["output"]["sequencing"]) {
        std::string sequencing = configNode["files"]["output"]["sequencing"].as<std::string>();
        std::cout << sequencing << std::endl;
        Config::setSequencing(sequencing);
    }
    if (configNode["files"]["output"]["read_length"]) {
        std::string readlength = configNode["files"]["output"]["read_length"].as<std::string>();
        Config::setTextReadlength(readlength);
    }
    if (configNode["files"]["output"]["average_insert_size"]) {
        std::string averageinsertsize = configNode["files"]["output"]["average_insert_size"].as<std::string>();
        std::cout << averageinsertsize << std::endl;
        Config::setTextAverageInsertSize(averageinsertsize);
    }
    if (configNode["files"]["output"]["sd"]) {
        std::string sd = configNode["files"]["output"]["sd"].as<std::string>();
        std::cout << sd << std::endl;
        Config::setTextSD(sd);
    }
    if (configNode["files"]["output"]["base_error_rate"]) {
        std::string baseerrorrate = configNode["files"]["output"]["base_error_rate"].as<std::string>();
        std::cout << baseerrorrate << std::endl;
        Config::setTextBaseErrorRate(baseerrorrate);
    }
    if (configNode["files"]["output"]["coverage"]) {
        std::string coverage = configNode["files"]["output"]["coverage"].as<std::string>();
        std::cout << coverage << std::endl;
        Config::setTextCoverage(coverage);
    }

    YAML::Node variationsNode = configNode["variants"];
    for(YAML::const_iterator variant=variationsNode.begin();variant!=variationsNode.end();++variant) {
        const std::string keyvariations=variant->first.as<std::string>();
        YAML::Node svtypesNode = variationsNode[keyvariations];
        for(YAML::const_iterator svtype=svtypesNode.begin();svtype!=svtypesNode.end();++svtype) {
            const std::string keyrange=svtype->first.as<std::string>();
            std::cout << keyrange << std::endl;
            if (keyrange=="range") {
                YAML::Node range = svtypesNode[keyrange];
                for (std::size_t j=0;j<range.size();j++) {
                    std::cout << range[j].as<std::string>() << "\n";
                }
            }
            if (keyrange=="number") {
                YAML::Node range = svtypesNode[keyrange];
                for (std::size_t j=0;j<range.size();j++) {
                    std::cout << range[j].as<std::string>() << "\n";
                }
            }
        }
    }
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
    Config::setThreads(Config::convertStringToInt(threads));
}

void Config::setReadlength(int64_t readlength) {
    Config::readlength = readlength;
}

void Config::setTextReadlength(std::string readlength) {
    Config::setReadlength(Config::convertStringToInt64(readlength));
}

void Config::setAverageInsertSize(int64_t averageinsertsize) {
    Config::averageinsertsize = averageinsertsize;
}

void Config::setTextAverageInsertSize(std::string averageinsertsize) {
    Config::setAverageInsertSize(Config::convertStringToInt64(averageinsertsize));
}

void Config::setSD(int64_t sd) {
    Config::sd = sd;
}

void Config::setTextSD(std::string sd) {
    Config::setSD(Config::convertStringToInt64(sd));
}

void Config::setBaseErrorRate(float baseerrorrate) {
    Config::baseerrorrate =baseerrorrate;
}

void Config::setTextBaseErrorRate(std::string baseerrorrate) {
    Config::setBaseErrorRate(Config::convertStringToFloat(baseerrorrate));
}

void Config::setCoverage(int64_t coverage) {
    Config::coverage = coverage;
}

void Config::setTextCoverage(std::string coverage) {
    Config::setCoverage(Config::convertStringToInt64(coverage));
}

int64_t Config::getReadLength() {
    return Config::readlength;
}

int64_t Config::getAverageInsertSize() {
    return Config::averageinsertsize;
}

int64_t Config::getSD() {
    return Config::sd;
}

float Config::getBaseErrorRate() {
    return Config::baseerrorrate;
}

int64_t Config::getCoverage() {
    return Config::coverage;
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

void Config::setConfigFilePath(std::string configfilepath) {
    Config::configfilepath = configfilepath;
}

std::string Config::getConfigFilePath() {
    return Config::configfilepath;
}