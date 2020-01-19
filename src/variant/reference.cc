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
    std::string seq = fastaReader.getSeqbyChr("chr1");
    std::cout << "pass" << seq.length() << std::endl;
}
