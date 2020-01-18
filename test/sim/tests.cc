#include <gtest/gtest.h>
#include <iostream>
#include "fasta/fasta.h"
//#include "caller/readdepthanalysis.h"
//#include "bwt/bwt.h"
//#include "caller/stringsearch.h"
//#include "caller/stringsearchalignment.h"

TEST(FilePathTest, getFilePathName)
{
    FastaReader fastaReader;
    fastaReader.setFilePath((filepath.getReferencePath()));
    fastaReader.setIndexFilePath((filepath.getReferencePath()) + ".fai");
    fastaReader.initialize();
}
