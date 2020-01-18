#include <gtest/gtest.h>
#include <iostream>
#include "fasta/fastareader.h"

std::string referencepath = "../../test/data/reference"
std::string referenceindexpath = "../../test/data/reference.fai"

TEST(FilePathTest, getFilePathName)
{
    FastaReader fastaReader;
    fastaReader.setFilePath(referencepath);
    fastaReader.setIndexFilePath(referenceindexpath);
    fastaReader.initialize();
    std::string seqrefString = fastareader.getSeqbyPosition("chr1",0,10);
    ASSERT_EQ("CGAGCCGAAC", seqrefString);
}
