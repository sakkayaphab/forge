//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#include "config.h"

Config::Config() {

}

bool Config::FileExists(std::string filename) {
    std::ifstream ifile(filename.c_str());
    return (bool)ifile;
}

void Config::setSeed(unsigned seed) {
    Config::seed = seed;
}

unsigned Config::getSeed() {
    return Config::seed;
}

void Config::readConfigFile() {
    if (!FileExists(getConfigFilePath())) {
        std::cerr << "not found file : " << getConfigFilePath() << std::endl;
        return;
    }

    YAML::Node configNode = YAML::LoadFile(getConfigFilePath());
    if (configNode["files"]["input"]["reference"]) {
        std::string reference = configNode["files"]["input"]["reference"].as<std::string>();
        Config::setReferencePath(reference);
    }
    if (configNode["files"]["output"]["output_directory"]) {
        std::string outputdirectory = configNode["files"]["output"]["output_directory"].as<std::string>();
        Config::setOutputDirectoryPath(outputdirectory);
    }

    if (configNode["config"]["sequencing"]) {
        std::string sequencing = configNode["config"]["sequencing"].as<std::string>();
        Config::setSequencing(sequencing);
    }
    if (configNode["config"]["read_length"]) {
        std::string readlength = configNode["config"]["read_length"].as<std::string>();
        Config::setTextReadlength(readlength);
    }

    if (configNode["config"]["insert_size"]) {
        std::string insertsize = configNode["config"]["insert_size"].as<std::string>();
        Config::setTextAverageInsertSize(insertsize);
    }

    if (configNode["config"]["debug"]) {
        std::string debug = configNode["config"]["debug"].as<std::string>();
        std::cout << debug << std::endl;
    }

    if (configNode["config"]["sd_insert_size"]) {
        std::string sd = configNode["config"]["sd_insert_size"].as<std::string>();
        Config::setTextSD(sd);
    }
    if (configNode["config"]["base_error_rate"]) {
        std::string baseerrorrate = configNode["config"]["base_error_rate"].as<std::string>();
        Config::setTextBaseErrorRate(baseerrorrate);
    }
    if (configNode["config"]["coverage"]) {
        std::string coverage = configNode["config"]["coverage"].as<std::string>();
        Config::setTextCoverage(coverage);
    }


    YAML::Node variationsNode = configNode["variations"];
    for(YAML::const_iterator variant=variationsNode.begin();variant!=variationsNode.end();++variant) {
        const std::string keyvariations=variant->first.as<std::string>();
        VariantionConfig vc;
        vc.setSvType(keyvariations);
        YAML::Node svtypesNode = variationsNode[keyvariations];

        std::vector<std::string> textRangeList;
        std::vector<std::string> textNumberList;

        for(YAML::const_iterator svtype=svtypesNode.begin();svtype!=svtypesNode.end();++svtype) {
            const std::string keyrange=svtype->first.as<std::string>();
            if (keyrange=="range") {
                int tcount =0;
                YAML::Node range = svtypesNode[keyrange];
                for (std::size_t j=0;j<range.size();j++) {
                    textRangeList.push_back(range[j].as<std::string>());
                }
            }
            if (keyrange=="number") {
                YAML::Node range = svtypesNode[keyrange];
                for (std::size_t j=0;j<range.size();j++) {
                    textNumberList.push_back(range[j].as<std::string>());
                }
            }
        }

        std::vector<VariantionRange> vrlist;
        if (textRangeList.size()!=0) {
            for (int i=0;i<textRangeList.size();i++) {
                VariantionRange tempVR;
                tempVR.setTextRange(textRangeList[i]);
                tempVR.setTextNumber(textNumberList[i]);
                vrlist.push_back(tempVR);
            }
        } else {
            std::cerr << "range and number are uncorrect" << std::endl;
            exit(1);
        }

        vc.setVariantRangeList(vrlist);
        Config::addVariantionConfig(vc);

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

void Config::addVariantionConfig(VariantionConfig vc) {
    Config::variantionconfigs.push_back(vc);
}

void Config::setVariantionConfig(std::vector<VariantionConfig> vcs) {
    Config::variantionconfigs = vcs;
}

std::vector<VariantionConfig> Config::getVariantionConfig() {
    return Config::variantionconfigs;
}
