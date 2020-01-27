//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#ifndef FORGE_CONFIG_H
#define FORGE_CONFIG_H

#include <string>
#include <cstdint>
#include <yaml-cpp/yaml.h>
#include <iostream>
#include <fstream>

class Config {
private:
    std::string configfilepath;
    std::string referencepath;
    std::string referenceindexpath;
    std::string outputdirectorypath;
    int threads = 1;
    std::string sequencing;
    int64_t readlength = 0;
    int64_t averageinsertsize = 0;
    int64_t sd = 0;
    float baseerrorrate = 0;
    int64_t coverage = 0;

public:
    Config();

    void readConfigFile();

    void setConfigFilePath(std::string configfilepath);

    std::string getConfigFilePath();

    void setReferencePath(std::string referencepath);

    bool FileExists(std::string filename);

    void setReferenceIndexPath(std::string referenceindexpath);

    void setOutputDirectoryPath(std::string outputDirectoryPath);

    void setThreads(int threads);

    void setTextThreads(std::string threads);

    void setSequencing(std::string sequencing);

    std::string getReferencePath();

    std::string getReferenceIndexPath();

    std::string getOutputDirectoryPath();

    int getThreads();

    std::string getSequencing();

    void setReadlength(int64_t readlength);

    void setTextReadlength(std::string readlength);

    void setAverageInsertSize(int64_t averageinsertsize);

    void setTextAverageInsertSize(std::string averageinsertsize);

    void setSD(int64_t sd);

    void setTextSD(std::string sd);

    void setBaseErrorRate(float baseerrorrate);

    void setTextBaseErrorRate(std::string baseerrorrate);

    void setCoverage(int64_t coverage);

    void setTextCoverage(std::string coverage);

    int64_t getReadLength();

    int64_t getAverageInsertSize();

    int64_t getSD();

    float getBaseErrorRate();

    int64_t getCoverage();

    int64_t convertStringToInt64(std::string text);

    int convertStringToInt(std::string text);

    float convertStringToFloat(std::string text);


};


#endif //FORGE_CONFIG_H
