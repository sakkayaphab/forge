#ifndef FAIDX_H
#define FAIDX_H
#include <string>
#include <vector>
#include <map>
#include <stdint.h>
#include "indexformat.h"
class Faidx
{
public:

private:
  std::string indexfilepath;

  struct OffsetFile {
    int64_t start= 0;
    int64_t end= 0;
  };

  std::vector<IndexFormat> faidxlist;

  int64_t getApproximateLineStart(std::string chromosome,int64_t start);
  int64_t getApproximateLineEnd(std::string chromosome,int64_t end);

  int64_t getApproximateOffsetStart(std::string chromosome,int64_t start);
  int64_t getApproximateOffsetEnd(std::string chromosome,int64_t end);
public:
  Faidx();
  void initialize();
  void setIndexFilePath(std::string indexfilepath);
  std::string getIndexFilePath();

  bool hasChromosomeName(std::string chr);
  int64_t getLengthbyChromosome(std::string chr);
  int64_t getOffsetbyChromosome(std::string chr);
  int64_t getLinebasesbyChromosome(std::string chr);
  int64_t getLinewidthbyChromosome(std::string chr);
  int64_t getQualoffsetbyChromosome(std::string chr);

  int64_t getOffsetEndByPosition(std::string chromosome, int64_t end);
  int64_t getOffsetStartByPosition(std::string chromosome, int64_t start);
  int getSize();

  std::vector<IndexFormat>  getRecords();
  std::string getChrByNumberID(int numberid);
  void genarateIndexFile(std::string fastapath,std::string outputindexpath);
};

#endif