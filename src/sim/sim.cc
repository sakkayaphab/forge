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


    YAML::Node configNode = YAML::LoadFile("../templates/custom.yaml");
    if (configNode["files"]["input"]["reference"]) {
        std::string reference = configNode["files"]["input"]["reference"].as<std::string>();
        std::cout << reference << std::endl;
        config.setReferencePath(reference);
    }
    if (configNode["files"]["output"]["output_directory"]) {
        std::string outputdirectory = configNode["files"]["output"]["output_directory"].as<std::string>();
        std::cout << outputdirectory << std::endl;
        config.setOutputDirectoryPath(outputdirectory);
    }
    if (configNode["files"]["output"]["sequencing"]) {
        std::string sequencing = configNode["files"]["output"]["sequencing"].as<std::string>();
        std::cout << sequencing << std::endl;
        config.setSequencing(sequencing);
    }
    if (configNode["files"]["output"]["read_length"]) {
        std::string readlength = configNode["files"]["output"]["read_length"].as<std::string>();
        std::cout << readlength << std::endl;

    }
    if (configNode["files"]["output"]["average_insert_size"]) {
        std::string averageinsertsize = configNode["files"]["output"]["average_insert_size"].as<std::string>();
        std::cout << averageinsertsize << std::endl;
    }
    if (configNode["files"]["output"]["sd"]) {
        std::string averageinsertsize = configNode["files"]["output"]["sd"].as<std::string>();
        std::cout << averageinsertsize << std::endl;
    }
    if (configNode["files"]["output"]["base_error_rate"]) {
        std::string baseerrorrate = configNode["files"]["output"]["base_error_rate"].as<std::string>();
        std::cout << baseerrorrate << std::endl;
    }
    if (configNode["files"]["output"]["coverage"]) {
        std::string coverage = configNode["files"]["output"]["coverage"].as<std::string>();
        std::cout << coverage << std::endl;
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