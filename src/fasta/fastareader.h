#ifndef FASTAREADER_H
#define FASTAREADER_H
#include <string>
#include <vector>
#include <map>
#include <stdint.h>
#include "faidx.h"
#include "fasta.h"
#include <algorithm>

class FastaReader
{
private:
  Faidx faidx;
  Fasta fasta;

public:
  FastaReader();
  void setFilePath(std::string filepath);
  std::string getFilePath();
  bool hasFilePath();
  void setIndexFilePath(std::string indexfilepath);
  std::string getIndexFilePath();
  bool hasIndexFilePath();
  void exitIfNoFilePath();
  bool FileExists(std::string filename);
  void initialize();
  std::string getSeqbyPosition(std::string chromosome, int64_t start, int64_t end);
  std::string getSeqbyChr(std::string chromosome);
  Faidx getFastaIndex();

  void replaceSeqToUppercase(std::string *str)
  {
    std::transform((*str).begin(), (*str).end(), (*str).begin(), ::toupper);
  }

  struct RegionRange {
        int64_t pos = 0;
        int64_t end = 0;
  };

    struct ChromosomeRegion
    {
        int64_t LENGTH= 0;
        int64_t OFFSET= 0;
        int64_t LINEBASES= 0;
        int64_t LINEWIDTH= 0;
        int64_t QUALOFFSET= 0;
    };

    FastaReader::ChromosomeRegion  getChromosomeRegionWithoutGap();
    std::vector<FastaReader::ChromosomeRegion>  getChromosomeRegionsWithoutGap();

};

#endif