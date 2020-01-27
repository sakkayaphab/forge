#include <gtest/gtest.h>
#include <iostream>
#include "sim/variantrange.h"
#include <string>
#include "sim/seqmod.h"

TEST(HelloTest, getHello)
{
    std::cout << "Hello world" << std::endl;
}

TEST(VariantRangeTest, variantrange1)
{
    VariantRange vr;
    vr.setTextRange("100-1000");
    ASSERT_EQ(100, vr.getMinLength());
    ASSERT_EQ(1000, vr.getMaxLength());
}

TEST(VariantRangeTest, variantrange2)
{
    VariantRange vr;
    vr.setTextRange(" 100 - 1000 ");
    ASSERT_EQ(100, vr.getMinLength());
    ASSERT_EQ(1000, vr.getMaxLength());
}

TEST(SeqModTest, seqmod1)
{
    std::string source = "GGGCAGTGGGAGGGAACTGAGACTGGGGAGGGACAAAGGCTGCTCTGTCCTGGTGCTCCCACAAAGGAGAAGGGCTGATCACTCAAAGTTGCGAACACCAA";
    SeqMod seqmod;
    seqmod.setSeq(source);
    ASSERT_EQ(source,seqmod.getSeq());
    std::string seq1 = seqmod.copy(0, 10);
    ASSERT_EQ("GGGCAGTGGG",seq1);
    std::string seqrev = seqmod.reverseComplement(seq1);
    ASSERT_EQ("CCCACTGCCC",seqrev);
}


