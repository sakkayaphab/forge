#ifndef VCFDATALINE_H
#define VCFDATALINE_H
#include <string>
#include <vector>
#include <map>
class Dataline
{
private:

    std::string CHROM;
    std::string POS;
    std::string ID;
    std::string REF;
    std::string ALT;
    std::string QUAL;
    std::string FILTER;
    std::map<std::string, std::string> mapINFO;
    std::string FORMAT;
    std::vector<std::string> SAMPLE;

    
  
public:
  Dataline();

  //set traditional data
  void setTextCHROM(std::string value);
  void setTextPOS(std::string value);
  void setTextID(std::string value);
  void setTextREF(std::string value);
  void setTextALT(std::string value);
  void setTextQUAL(std::string value);
  void setTextFILTER(std::string value);
  void setMapINFO(std::string key,std::string value);
  void setTextFORMAT(std::string value);
  void setTextSAMPLE(std::vector<std::string> value);

  std::string getTextCHROM();
  std::string getTextPOS();
  std::string getTextID();
  std::string getTextREF();
  std::string getTextALT();
  std::string getTextQUAL();
  std::string getTextFILTER();
  std::string getMapINFOByKey(std::string key);
  std::string getTextINFO();
  std::string getTextFORMAT();
  std::string getTextSAMPLE();

  void getMapInfoVector(std::vector<std::string> *keys,std::vector<std::string> *values);

    std::string getTextRecord();
};

#endif