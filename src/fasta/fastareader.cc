#include "fastareader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

FastaReader::FastaReader()
{
}

void FastaReader::initialize()
{
    faidx.initialize();
}

bool FastaReader::FileExists(std::string filename) {
    std::ifstream ifile(filename.c_str());
    return (bool)ifile;
}

bool FastaReader::hasIndexFilePath() {
    return FileExists(getIndexFilePath());
}

bool FastaReader::hasFilePath() {
    return FileExists(getFilePath());
}

void FastaReader::exitIfNoFilePath() {
    if (!hasIndexFilePath()) {
        exit (EXIT_FAILURE);
    }

    if (!hasFilePath()) {
        exit (EXIT_FAILURE);
    }
}

void FastaReader::setIndexFilePath(std::string t_indexfilepath)
{
    faidx.setIndexFilePath(t_indexfilepath);
}

std::string FastaReader::getIndexFilePath()
{
    return faidx.getIndexFilePath();
}

void FastaReader::setFilePath(std::string filepath)
{
    fasta.setFilePath(filepath);
}

std::string FastaReader::getFilePath()
{
    return fasta.getFilePath();
}

std::string FastaReader::getSeqbyPosition(std::string chromosome,int64_t start,int64_t  end) {
    int64_t offsetstart = faidx.getOffsetStartByPosition(chromosome,start);
    int64_t offsetend  = faidx.getOffsetEndByPosition(chromosome,end);

    return fasta.getSeqByOffset(offsetstart,offsetend);
}

std::string FastaReader::getSeqbyChr(std::string chromosome) {
    if (!faidx.hasChromosomeName(chromosome)) {
        return "";
    }

    int64_t length = faidx.getLengthbyChromosome(chromosome);
    int64_t offsetend = faidx.getOffsetbyChromosome(chromosome);
    std::cout << "length :" << length << std::endl;
    std::cout << "offsetend :" << offsetend << std::endl;
//
    int64_t offsetstart = faidx.getOffsetStartByPosition(chromosome,0);
//    int64_t offsetend  = faidx.getOffsetEndByPosition(chromosome,offsetend);

    return fasta.getSeqByOffset(offsetstart,offsetend);
}