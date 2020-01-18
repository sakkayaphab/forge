#include <gtest/gtest.h>
#include <iostream>
#include "fasta/fastareader.h"
//#include "caller/readdepthanalysis.h"
//#include "bwt/bwt.h"
//#include "caller/stringsearch.h"
//#include "caller/stringsearchalignment.h"

TEST(FilePathTest, getFilePathName)
{
FastaReader fastaReader;
fastaReader.setFilePath("../../test/data/reference");
fastaReader.setIndexFilePath("../../test/data/reference" + ".fai");
fastaReader.initialize();
}
