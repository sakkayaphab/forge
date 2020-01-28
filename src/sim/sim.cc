//
// Created by Sakkayaphab Piwluang on 23/1/20.
//

#include "sim.h"

Sim::Sim() {

}

void Sim::setFastaPath(std::string path) {
    Sim::fastaPath = path;
}

std::string Sim::getFastaPath() {
    return Sim::fastaPath;
}

std::string Sim::getFastaIndexPath() {
    return Sim::fastaPath+".fai";
}

void Sim::readFasta() {

    Config config;
    config.setReferencePath(Sim::getFastaPath());
    config.setReferenceIndexPath(Sim::getFastaIndexPath());

    config.setConfigFilePath("../templates/custom.yaml");
    config.readConfigFile();

    VariantBinHandler variantbin;
    variantbin.setSpace((101*2)+(400*10));
    std::vector<VariantionConfig> vcs = config.getVariantionConfig();
    for (VariantionConfig vc:vcs) {
        for (VariantionRange r:vc.getVariantRangeList()) {
            std::cout << vc.getSvType() << " " << r.getMinLength()<< " "  << r.getMaxLength()<< " "  << r.getNumber() << std::endl;
            variantbin.addVariantByRange(vc.getSvType(),r.getMinLength(),r.getMaxLength(),r.getNumber());
        }
    }
//    variantbin.sortVariantList();
    variantbin.shuffleVariantList();


//    FastaReader fastareader;
//    fastareader.setFilePath(getFastaPath());
//    fastareader.setIndexFilePath(getFastaIndexPath());
//    fastareader.initialize();
//    fastareader.exitIfNoFilePath();
//    ContainerManager cm  = fastareader.getAllChrBlockContainerWithSingleThread();
//    cm.removeAllBlocksSmallerThan(((101*2)+400+50)*10);
//    cm.writeBlockContainerTextFile("ll");


    ContainerManager cm;
    cm.loadBlockContainersFromFile("ll");
//    std::cout << cm.getBlockContainers().size() << std::endl;
//    return;
// ReferenceContainerHandler
    ReferenceContainerHandler rch;
    rch.addContainerManagerToReferenceContainer(cm);
    rch.showReferenceContainer();
    rch.shuffleReferenceContainer();
//    rch.showReferenceContainer();


// ArrangementContainer
    ArrangementContainer arrangementcontainer;
    arrangementcontainer.setVariantBin(&variantbin);
    arrangementcontainer.setReferenceContainerHandler(&rch);
    arrangementcontainer.execute();
    arrangementcontainer.showReferenceContainerContainVaraintOnly();
    std::cout << arrangementcontainer.getReferenceContainerHandler()->getSizeReferenceContainer() << std::endl;


//    printf ("Again the first number: %d\n", rand()%100);
//    printf ("Again the first number: %d\n", rand()%100);
//    printf ("Again the first number: %d\n", rand()%100);
//
//    printf ("Again the first number: %d\n", rand()%100);



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