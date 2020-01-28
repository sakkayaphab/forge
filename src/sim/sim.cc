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
    unsigned seed = 0;

    std::default_random_engine rnge(seed);



    Config config;
    config.setReferencePath(Sim::getFastaPath());
    config.setReferenceIndexPath(Sim::getFastaIndexPath());

    config.setConfigFilePath("../templates/custom.yaml");
    config.readConfigFile();

    VariantBin variantbin;
    std::vector<VariantionConfig> vcs = config.getVariantionConfig();
    for (VariantionConfig vc:vcs) {
        for (VariantionRange r:vc.getVariantRangeList()) {
            std::uniform_int_distribution<int64_t> dis(r.getMinLength(), r.getMaxLength());
            for (int i=0;i<r.getNumber();i++) {
                Variant tempVariant;
                tempVariant.setAppxRefLength(dis(rnge));
                tempVariant.setAppxRefLength(dis(rnge));
            }
            std::cout << '\n';
        }
    }
//
//
//    ContainerManager cm;
//    cm.loadBlockContainersFromFile("ll");
////    cm.showBlockContainers();
//
//    ApproxVariation apxv;
//    apxv.setConfig(&config);
//    apxv.setContainerManager(&cm);
//    apxv.execute();
//    srand (seed);


//    printf ("Again the first number: %d\n", rand()%100);
//    printf ("Again the first number: %d\n", rand()%100);
//    printf ("Again the first number: %d\n", rand()%100);
//
//    printf ("Again the first number: %d\n", rand()%100);

//    FastaReader fastareader;
//    fastareader.setFilePath(getFastaPath());
//    fastareader.setIndexFilePath(getFastaIndexPath());
//    fastareader.initialize();
//    fastareader.exitIfNoFilePath();
//    ContainerManager cm  = fastareader.getAllChrBlockContainerWithSingleThread();
//    cm.removeAllBlocksSmallerThan(((101*2)+400+50)*10);
//    cm.showBlockContainers();
//    cm.writeBlockContainerTextFile("ll");


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