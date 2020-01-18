#include <gtest/gtest.h>
#include <iostream>
#include "fasta/fastareader.h"
#include <string>
#include <bits/stdc++.h>


std::string referencepath = "../../../test/data/reference.fa";
std::string referenceindexpath = "../../../test/data/reference.fa.fai";

TEST(FilePathTest, getTestFasta1)
{
    FastaReader fastaReader;
    fastaReader.setFilePath(referencepath);
    fastaReader.setIndexFilePath(referenceindexpath);
    fastaReader.initialize();
    fastaReader.exitIfNoFilePath();
    std::string seqrefString = fastaReader.getSeqbyPosition("chr1",0,10);
    ASSERT_EQ("CGAGCCGAAC", seqrefString);
}

TEST(FilePathTest, getTestFasta2)
{
    FastaReader fastaReader;
    fastaReader.setFilePath(referencepath);
    fastaReader.setIndexFilePath(referenceindexpath);
    fastaReader.initialize();
    std::string seqrefString = fastaReader.getSeqbyPosition("chr2",0,10);
    ASSERT_EQ("GTCCTCGGTG", seqrefString);
}

TEST(FilePathTest, getTestFasta3)
{
    FastaReader fastaReader;
    fastaReader.setFilePath(referencepath);
    fastaReader.setIndexFilePath(referenceindexpath);
    fastaReader.initialize();
    std::string seqrefString = fastaReader.getSeqbyPosition("chr1",50,50+10);
    ASSERT_EQ("TAAAGGGGTC", seqrefString);
}

TEST(FilePathTest, getTestFasta4)
{
    FastaReader fastaReader;
    fastaReader.setFilePath(referencepath);
    fastaReader.setIndexFilePath(referenceindexpath);
    fastaReader.initialize();
    std::string seqrefString = fastaReader.getSeqbyPosition("chr2",75,75+10);
    ASSERT_EQ("GCCCCAGCTC", seqrefString);
}