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
//    Config config;
//    config.setConfigFilePath("../templates/custom.yaml");
//    config.readConfigFile();
//

    SeqMod seqmod;
    seqmod.setSeq("GGGCAGTGGGAGGGAACTGAGACTGGGGAGGGACAAAGGCTGCTCTGTCCTGGTGCTCCCACAAAGGAGAAGGGCTGATCACTCAAAGTTGCGAACACCAA");
    std::cout << seqmod.getSeq()<< std::endl;
    std::string seq1 = seqmod.copy(0, 10);
    std::cout << seq1 << std::endl;
    std::string seqrev = seqmod.reverseComplement(seq1);
    std::cout << seqrev << std::endl;
    seqmod.erase(0, 10);
    std::cout << seqmod.getSeq() << std::endl;



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