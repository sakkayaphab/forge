#include "shortread.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

Shortread::~Shortread()
{

}

Shortread::Shortread()
{

}

void Shortread::execute() {
    std::ifstream file("/data/users/duangdao/kan/reference/ucsc_hg19.fa");
    std::string str;
    std::vector<std::string> file_contents;
    std::cout << "/data/users/duangdao/kan/reference/ucsc_hg19.fa" << std::endl;
    while (std::getline(file, str))
    {
        file_contents.push_back(str);
    }
}