#include <gtest/gtest.h>
#include <iostream>
#include "fasta/fastareader.h"

TEST(FilePathTest, getFilePathName)
{
    FastaReader fastaReader;
    fastaReader.setFilePath("../../test/data/reference");
    fastaReader.setIndexFilePath("../../test/data/reference" + ".fai");
    fastaReader.initialize();
    std::string seqrefString = fastareader.getSeqbyPosition("chr1",0,10);
    ASSERT_EQ("CGAGCCGAAC", seqrefString);
}
