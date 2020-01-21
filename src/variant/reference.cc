//
// Created by Sakkayaphab Piwluang on 19/1/20.
//

#include <iostream>
#include "reference.h"


Reference::Reference() {

}

std::string Reference::getFastaPath() {
    return fastapath;
}

void Reference::setFastaPath(std::string fastapath) {
    Reference::fastapath = fastapath;
}

std::string Reference::getFastaIndexPath() {
    return fastaindexpath;
}

void Reference::setFastaIndexPath(std::string fastaindexpath) {
    Reference::fastaindexpath = fastaindexpath;
}

void Reference::getAllInfo() {
    fastaReader.setFilePath(getFastaPath());
    fastaReader.setIndexFilePath(getFastaIndexPath());
    fastaReader.initialize();
    fastaReader.exitIfNoFilePath();
    Faidx faidx = fastaReader.getFastaIndex();
    std::vector<Faidx::FileFormat> faidxRecords = faidx.getRecords();
    for (Faidx::FileFormat record : faidxRecords) {
        std::cout << record.NAME << std::endl;
    }

//    std::string seq = fastaReader.getSeqbyChr("chr1");
//    std::string seq = fastaReader.getSeqbyPosition("chr1",0,10);
//    std::string str2 = seq.substr (seq.length()-100000,seq.length()-1);
//    std::cout << "pass2" << str2.length() << str2 << std::endl;
//    std::cout << "pass" << seq.length() << seq[seq.length()-1] << std::endl;
}
