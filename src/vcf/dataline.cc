#include "dataline.h"

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

void Dataline::setMapINFO(std::string key,std::string value)
{
    mapINFO[key] = value;
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

std::string Dataline::getMapINFOByKey(std::string key) {
    return mapINFO[key];
}


std::string Dataline::getTextINFO()
{
    std::vector<std::string> keys;
    std::vector<std::string> values;
    Dataline::getMapInfoVector(&keys,&values);
    std::string text;
    for (int i=0;i<keys.size();i++) {
        if (i==0) {
            text += keys.at(i);
            text += "=";
            text += values.at(i);
        } else {
            text += ";";
            text += keys.at(i);
            text += "=";
            text += values.at(i);
        }

    }

    return text;
}

void Dataline::getMapInfoVector(std::vector<std::string> *keys,std::vector<std::string> *values) {
    for ( std::map<std::string,std::string>::iterator it=mapINFO.begin() ; it != mapINFO.end(); ++it )
    {
        keys->push_back(it->first);
        values->push_back(it->second);
    }
}

std::string Dataline::getTextFORMAT()
{
    return FORMAT;
}
std::string Dataline::getTextSAMPLE()
{
    return "";
}

std::string Dataline::getTextRecord() {
    return Dataline::getTextCHROM()+"\t"+
            Dataline::getTextPOS()+"\t"+
            Dataline::getTextID()+"\t"+
            Dataline::getTextREF()+"\t"+
            Dataline::getTextALT()+"\t"+
            Dataline::getTextQUAL()+"\t"+
            Dataline::getTextFILTER()+"\t"+
            Dataline::getTextINFO();
}