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
    YAML::Node config = YAML::LoadFile("../templates/custom.yaml");
    if (config["files"]["input"]["reference"]) {
        std::string reference = config["files"]["input"]["reference"].as<std::string>();
        std::cout << reference << std::endl;
    }
    if (config["files"]["output"]["output_directory"]) {
        std::string outputdirectory = config["files"]["output"]["output_directory"].as<std::string>();
        std::cout << outputdirectory << std::endl;
    }
    if (config["files"]["output"]["sequencing"]) {
        std::string sequencing = config["files"]["output"]["sequencing"].as<std::string>();
        std::cout << sequencing << std::endl;
    }
    if (config["files"]["output"]["read_length"]) {
        std::string readlength = config["files"]["output"]["read_length"].as<std::string>();
        std::cout << readlength << std::endl;
    }
    if (config["files"]["output"]["average_insert_size"]) {
        std::string averageinsertsize = config["files"]["output"]["average_insert_size"].as<std::string>();
        std::cout << averageinsertsize << std::endl;
    }
    if (config["files"]["output"]["sd"]) {
        std::string averageinsertsize = config["files"]["output"]["sd"].as<std::string>();
        std::cout << averageinsertsize << std::endl;
    }
    if (config["files"]["output"]["base_error_rate"]) {
        std::string baseerrorrate = config["files"]["output"]["base_error_rate"].as<std::string>();
        std::cout << baseerrorrate << std::endl;
    }
    if (config["files"]["output"]["coverage"]) {
        std::string coverage = config["files"]["output"]["coverage"].as<std::string>();
        std::cout << coverage << std::endl;
    }

    YAML::Node variationsNode = config["variants"];
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