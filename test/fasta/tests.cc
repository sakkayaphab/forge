#include <gtest/gtest.h>
#include <iostream>
#include "fasta/fastareader.h"
#include <string>
#include <bits/stdc++.h>
#include <filesystem>


TEST(FilePathTest, getTestFasta1)
{
    std::string referencepath = "../test/data/reference.fa";
    std::string referenceindexpath = "../test/data/reference.fa.fai";
    std::string path = "../";
    for (const auto & entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;

    FastaReader fastaReader;
    fastaReader.setFilePath(referencepath);
    fastaReader.setIndexFilePath(referenceindexpath);
    fastaReader.initialize();
    std::cout << fastaReader.getIndexFilePath() << std::endl;
    std::cout << fastaReader.getFilePath() << std::endl;
    std::cout << fastaReader.hasIndexFilePath() << std::endl;
    std::cout << fastaReader.hasFilePath() << std::endl;
    fastaReader.exitIfNoFilePath();
    std::string seqrefString = fastaReader.getSeqbyPosition("chr1",0,10);
    ASSERT_EQ("CGAGCCGAAC", seqrefString);
}

//TEST(FilePathTest, getTestFasta2)
//{
//    FastaReader fastaReader;
//    fastaReader.setFilePath(referencepath);
//    fastaReader.setIndexFilePath(referenceindexpath);
//    fastaReader.initialize();
//    std::string seqrefString = fastaReader.getSeqbyPosition("chr2",0,10);
//    ASSERT_EQ("GTCCTCGGTG", seqrefString);
//}
//
//TEST(FilePathTest, getTestFasta3)
//{
//    FastaReader fastaReader;
//    fastaReader.setFilePath(referencepath);
//    fastaReader.setIndexFilePath(referenceindexpath);
//    fastaReader.initialize();
//    std::string seqrefString = fastaReader.getSeqbyPosition("chr1",51,51+10);
//    ASSERT_EQ("TAAAGGGGTC", seqrefString);
//}
//
//TEST(FilePathTest, getTestFasta4)
//{
//    FastaReader fastaReader;
//    fastaReader.setFilePath(referencepath);
//    fastaReader.setIndexFilePath(referenceindexpath);
//    fastaReader.initialize();
//    std::string seqrefString = fastaReader.getSeqbyPosition("chr2",76,76+10);
//    ASSERT_EQ("GCCCCAGCTC", seqrefString);
//}