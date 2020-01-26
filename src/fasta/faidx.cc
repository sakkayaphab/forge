#include "faidx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>

Faidx::Faidx() {
}

void Faidx::initialize() {
    std::ifstream file(indexfilepath);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;

        IndexFormat fftoken;
        int i = 0;
        while (std::getline(iss, token, '\t')) {
            if (i == 0) {
                fftoken.setName(token);
            } else if (i == 1) {
                fftoken.setLength(strtoll(token.c_str(), NULL, 10));
            } else if (i == 2) {
                fftoken.setOffset(strtoll(token.c_str(), NULL, 10));
            } else if (i == 3) {
                fftoken.setLineBases(strtoll(token.c_str(), NULL, 10));
            } else if (i == 4) {
                fftoken.setLineWidth(strtoll(token.c_str(), NULL, 10));
                faidxlist.push_back(fftoken);
            } else {
                std::cerr << "fasta index error because it has tab more than normal" << std::endl;
                exit(1);
            }
            i++;
        }
    }
}

bool Faidx::hasChromosomeName(std::string chr) {
    for (int i = 0; i < faidxlist.size(); i++) {
        if (faidxlist.at(i).getName() == chr) {
            return true;
        }
    }

    return false;
}

int64_t Faidx::getLengthbyChromosome(std::string chr) {
    for (int i = 0; i < faidxlist.size(); i++) {
        if (faidxlist.at(i).getName() == chr) {
            return faidxlist.at(i).getLength();
        }
    }
    return 0;
}

int64_t Faidx::getOffsetbyChromosome(std::string chr) {
    for (int i = 0; i < faidxlist.size(); i++) {
        if (faidxlist.at(i).getName() == chr) {
            return faidxlist.at(i).getOffset();
        }
    }
    return 0;
}

int64_t Faidx::getLinebasesbyChromosome(std::string chr) {
    for (int i = 0; i < faidxlist.size(); i++) {
        if (faidxlist.at(i).getName() == chr) {
            return faidxlist.at(i).getLineBases();
        }
    }
    return 0;
}

int64_t Faidx::getLinewidthbyChromosome(std::string chr) {
    for (int i = 0; i < faidxlist.size(); i++) {
        if (faidxlist.at(i).getName() == chr) {
            return faidxlist.at(i).getLineWidth();
        }
    }
    return 0;
}

int64_t Faidx::getQualoffsetbyChromosome(std::string chr) {
    for (int i = 0; i < faidxlist.size(); i++) {
        if (faidxlist.at(i).getName() == chr) {
            return faidxlist.at(i).getQualOffset();
        }
    }
    return 0;
}

void Faidx::setIndexFilePath(std::string t_indexfilepath) {
    indexfilepath = t_indexfilepath;
}

std::string Faidx::getIndexFilePath() {
    return indexfilepath;
}

int64_t Faidx::getApproximateLineStart(std::string chromosome, int64_t start) {
    return floor(start / getLinebasesbyChromosome(chromosome));
}

int64_t Faidx::getApproximateLineEnd(std::string chromosome, int64_t end) {
    return ceil(end / getLinebasesbyChromosome(chromosome)) + 1;
}

int64_t Faidx::getApproximateOffsetStart(std::string chromosome, int64_t start) {

    int64_t apppointstart = getApproximateLineStart(chromosome, start);
    int64_t diff = start - apppointstart * getLinebasesbyChromosome(chromosome);

    return apppointstart * getLinewidthbyChromosome(chromosome) + diff;
}

int64_t Faidx::getApproximateOffsetEnd(std::string chromosome, int64_t end) {

    int64_t apppointend = getApproximateLineEnd(chromosome, end);
    int64_t diff = apppointend * getLinebasesbyChromosome(chromosome) - end;

    return (apppointend * getLinewidthbyChromosome(chromosome) - 1) - diff;
}

int64_t Faidx::getOffsetEndByPosition(std::string chromosome, int64_t end) {
    if (!hasChromosomeName(chromosome)) {
        std::cout << "not found this chromosome : " << chromosome << std::endl;
    }

    int64_t startoffset = getOffsetbyChromosome(chromosome);

    return startoffset + getApproximateOffsetEnd(chromosome, end);
}

int64_t Faidx::getOffsetStartByPosition(std::string chromosome, int64_t start) {
    if (!hasChromosomeName(chromosome)) {
        std::cout << "not found this chromosome : " << chromosome << std::endl;
    }

    int64_t startoffset = getOffsetbyChromosome(chromosome);

    return startoffset + getApproximateOffsetStart(chromosome, start);
}

std::vector<IndexFormat> Faidx::getRecords() {
    return faidxlist;
}

int Faidx::getSize() {
    return faidxlist.size();
}

std::string Faidx::getChrByNumberID(int numberid) {
    return faidxlist.at(numberid).getName();
}

void Faidx::genarateIndexFile(std::string fastapath, std::string outputindexpath) {
    std::ifstream file(fastapath);
    std::string line;

    std::string tempNAME;
    int64_t tempLENGTH = 0;
    int64_t tempOFFSET = 0;
    int64_t tempLINEBASES = 0;
    int64_t tempLINEWIDTH = 0;
    int64_t tempQUALOFFSET = 0;
    int64_t sumOffset = 0;
    while (std::getline(file, line)) {
        if (line.at(0) == '>') {
            if (tempLENGTH != 0) {
                std::cout << tempNAME << "\t"
                          << tempLENGTH << "\t"
                          << tempOFFSET << "\t"
                          << tempLINEBASES << "\t"
                          << tempLINEWIDTH << std::endl;
                tempLENGTH = 0;
                tempOFFSET = 0;
                tempLINEBASES = 0;
                tempLINEWIDTH = 0;
                tempQUALOFFSET = 0;
            }
            std::string delimiter = " ";
            std::string token = line.substr(0, line.find(delimiter));
            tempNAME = token.substr(1);
//            std::cout << token.substr(1) << std::endl;
            tempOFFSET = sumOffset + line.size() + 1;
            sumOffset += line.size() + 1;
        } else {
            tempLENGTH += line.size();
            if (tempLINEBASES == 0) {
                tempLINEBASES = line.size();
            }
            if (tempLINEWIDTH == 0) {
                tempLINEWIDTH = line.size() + 1;
            }

            sumOffset += line.size() + 1;
        }
    }


    std::cout << tempNAME << "\t"
              << tempLENGTH << "\t"
              << tempOFFSET << "\t"
              << tempLINEBASES << "\t"
              << tempLINEWIDTH << std::endl;

}