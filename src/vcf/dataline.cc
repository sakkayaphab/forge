#include <sstream>
#include "dataline.h"
#include <stdlib.h>
#include <cstdlib>
#include <cstring>

Dataline::Dataline()
{
}

void Dataline::setTextCHROM(std::string value)
{
    CHROM = value;
}
void Dataline::setTextPOS(std::string value)
{
    POS = value;
}

void Dataline::setTextID(std::string value)
{
    ID = value;
}

void Dataline::setTextREF(std::string value)
{
    REF = value;
}

void Dataline::setTextALT(std::string value)
{
    ALT = value;
}

void Dataline::setTextQUAL(std::string value)
{
    QUAL = value;
}

void Dataline::setTextFILTER(std::string value)
{
    FILTER = value;
}

void Dataline::setTextFORMAT(std::string value)
{
    FORMAT = value;
}

void Dataline::setTextSAMPLE(std::vector<std::string> value)
{
    SAMPLE = value;
}

std::string Dataline::getTextCHROM()
{
    return CHROM;
}
std::string Dataline::getTextPOS()
{
    return POS;
}
std::string Dataline::getTextID()
{
    return ID;
}
std::string Dataline::getTextREF()
{
    return REF;
}
std::string Dataline::getTextALT()
{
    return ALT;
}
std::string Dataline::getTextQUAL()
{
    return QUAL;
}
std::string Dataline::getTextFILTER()
{
    return FILTER;
}
std::string Dataline::getTextINFO()
{
    std::vector<InfoField> datalist = getInfoFieldlist();
    std::string info;
    for (InfoField x:datalist) {
        info += x.getKey();
        info += "=";
        info += x.getValue();
        info += ";";
    }

    return info;
}



std::vector<InfoField> Dataline::getInfoFieldlist() {
    std::vector<InfoField> records;

    for ( std::map<std::string,std::string>::iterator it=mapInfo.begin() ; it != mapInfo.end(); ++it )
    {
        InfoField record;
        record.setKey(it->first);
        record.setValue(it->second);
        records.push_back(record);
    }

    return records;
}

std::string Dataline::getTextFORMAT()
{
    return FORMAT;
}
std::string Dataline::getTextSAMPLE()
{
    return "";
}

void Dataline::setTextInfoKeyValue(std::string key,std::string value) {
    mapInfo[key]=value;
}

std::string Dataline::getTextInfoValue(std::string key) {
    return mapInfo[key];
}

std::vector<std::string> SplitStringToVectorString(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<int64_t> SplitStringToVectorInt64(std::string value, char divider) {
    std::vector<std::string> token = SplitStringToVectorString(value, divider);
    std::vector<int64_t> data;
    for (std::string x:token) {
        int base = 10;
        char *end;
        int64_t number = std::strtoll(x.c_str(), &end, base);
        data.push_back(number);
    }

    return data;
}