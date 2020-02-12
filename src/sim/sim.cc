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
//    TranformSeq tranformseq;
//    tranformseq.ConvertSyntax("A;INV[A,B,C];C");
//    return;
//    FastaReader fastareader;
//    fastareader.setFilePath(getFastaPath());
//    fastareader.setIndexFilePath(getFastaIndexPath());
//    fastareader.initialize();
//    fastareader.exitIfNoFilePath();
//    std::string seq = fastareader.getSeqbyChr("1");
//
//    std::string_view seqView = seq;
//    FastqWriter fqw;
//    fqw.setSequence(&seqView);
//    fqw.setOutputPath("1.fq");
//////    for (int i=0;i<22;i++) {
//        fqw.writeSequence();
//////    }
//
//    return;

    Config config;
    config.setReferencePath(Sim::getFastaPath());
    config.setReferenceIndexPath(Sim::getFastaIndexPath());
    config.setConfigFilePath("../templates/custom.yaml");
    config.readConfigFile();

    VariantBinHandler variantbin;
    variantbin.setSpace((101*2)+(400*5));
    std::vector<VariantionConfig> vcs = config.getVariantionConfig();
    for (VariantionConfig vc:vcs) {
        for (VariantionRange r:vc.getVariantRangeList()) {
            std::cout << vc.getSvType() << " " << r.getMinLength()<< " "  << r.getMaxLength()<< " "  << r.getNumber() << std::endl;
//            variantbin.addVariantByRange(vc.getSvType(),r.getMinLength(),r.getMaxLength(),r.getNumber());
        }
    }
    variantbin.shuffleVariantList();
//    return;

    FastaReader fastareader;
    fastareader.setFilePath(getFastaPath());
    fastareader.setIndexFilePath(getFastaIndexPath());
    fastareader.initialize();
    fastareader.exitIfNoFilePath();
    fastareader.saveSeqInBlockContainer(false);
    ContainerManager cm  = fastareader.getAllChrBlockContainerWithThreads(8);
//    ContainerManager cm  = fastareader.getAllChrBlockContainerWithSingleThread();
    cm.removeAllBlocksSmallerThan(((101*2)+400+50)*10);
    std::cout << config.getOutputDirectoryPath() << std::endl;
    for (BlockContainer bc:cm.getBlockContainers()) {
        for (Block b:bc.getBlocks()) {
                FastaWriter fastawriter;
                std::string rrseq = fastareader.getSeqbyPosition(b.getChr(),b.getPos(),b.getEnd());
                fastawriter.writeRefFile(config.getOutputDirectoryReferencePath()+"/" + b.getChr() + "." + std::to_string(b.getPos()), &rrseq,
                                     b.getChr(), b.getPos(), b.getEnd());
        }
    }


//    ReferenceContainerHandler rch;
//    rch.addContainerManagerToReferenceContainer(cm);
//
//// ArrangementContainer
//    ArrangementContainer arrangementcontainer;
//    arrangementcontainer.setVariantBin(&variantbin);
//    arrangementcontainer.setReferenceContainerHandler(&rch);
//    arrangementcontainer.execute();
//    arrangementcontainer.showReferenceContainerContainVaraintOnly();




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