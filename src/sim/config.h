//
// Created by Sakkayaphab Piwluang on 27/1/20.
//

#ifndef FORGE_CONFIG_H
#define FORGE_CONFIG_H

#include <string>

class Config {
    private:
        std::string referencepath;
        std::string referenceindexpath;
        std::string outputdirectorypath;
        int threads=1;


    public:
        Config();
        void setReferencePath(std::string referencepath);
        void setReferenceIndexPath(std::string referenceindexpath);
        void setOutputDirectoryPath(std::string outputDirectoryPath);
        void setThreads(int threads);
        std::string getReferencePath();
        std::string getReferenceIndexPath();
        std::string getOutputDirectoryPath();
        int getThreads();

};


#endif //FORGE_CONFIG_H
