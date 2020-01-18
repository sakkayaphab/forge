#include <gtest/gtest.h>
#include <iostream>
#include "fasta/fastareader.h"
#include <string>
#include <bits/stdc++.h>
#include <dirent.h>
#include <sys/types.h>

using namespace std;
void list_dir(const char *path) {
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        cout << entry->d_name << endl;
    }
    closedir(dir);
}

TEST(FilePathTest, getTestFasta1)
{
    std::string referencepath = "../test/data/reference.fa";
    std::string referenceindexpath = "../test/data/reference.fa.fai";
    list_dir("../..");

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