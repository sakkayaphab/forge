#ifndef WRITER_H
#define WRITER_H
#include <string>
#include <vector>
#include "vcf.h"

class VCFWriter: public Vcf
{
  private:
    std::string outputPath;
    
  public:
    VCFWriter();
    void setOutputPath(std::string path);
    void writeBufferAndClear();
    void writeHeader();
};

#endif