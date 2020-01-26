//
// Created by Sakkayaphab Piwluang on 23/1/20.
//

#include "sim.h"

Sim::Sim() {

}

void Sim::setFastaPath(std::string path) {
    Sim::fastaPath = path;
}

void Sim::readFasta() {
    YAML::Node config = YAML::LoadFile("../templates/config.yaml");
    std::string reference = config["file"]["input"]["reference"].as<std::string>();
    std::cout << reference << std::endl;
    std::string outputdirectory = config["file"]["output"]["outputdirectory"].as<std::string>();
    std::cout << outputdirectory << std::endl;
    std::string sequencing = config["file"]["output"]["sequencing"].as<std::string>();
    std::cout << sequencing << std::endl;

    YAML::Node sensors = config["variant"];
    for(YAML::const_iterator it=sensors.begin(); it!=sensors.end(); ++it){
//        const std::string &key=it->first.as<std::string>();
//        std::cout << key << std::endl;

//        YAML::Node attributes = it->second;
//        YAML::Node id = attributes["id"];
//        YAML::Node name = attributes["name"];
//        for(int i=0; i<2; ++i){
//            std::cout << attributes[i].as<std::string>() << std::endl;
//        }
//
////        std::string DeviceName = it->["username"].as<std::string>();
////        Eigen::Vector2f pos;
////        YAML::Node attributes = it->second;
////        YAML::Node position = attributes["position"];
//
    }

//    const std::string username = config["username"].as<std::string>();
//    std::cout << username << std::endl;
//    FastaReader fastareader;
//    fastareader.setFilePath(fastaPath);
//    fastareader.setIndexFilePath(fastaPath+".fai");
//    fastareader.initialize();
//    fastareader.exitIfNoFilePath();
//    ContainerManager cm  = fastareader.getAllChrBlockContainerWithSingleThread();
//    cm.showBlockContainers();


    // VCF

//    VCFWriter vcfwriter;
//    Dataline dl;
//    dl.setTextPOS("1000");
//    dl.setTextCHROM("chr1");
//    dl.setTextID("ID");
//    dl.setTextALT(".");
//    dl.setTextREF(".");
//    dl.setTextQUAL("60");
//    dl.setMapINFO("END","10000");
//    dl.setMapINFO("SVTYPE","DEL");
//    dl.setMapINFO("DP","10");
//    std::cout << dl.getTextRecord() << std::endl;

}