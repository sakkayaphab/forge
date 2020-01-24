#include <gtest/gtest.h>
#include <iostream>
#include "fasta/block.h"

TEST(FilePathTest, getFilePathName)
{
    Block block;
    block.setTextPos("300000000");
    ASSERT_EQ(300000000, block.getPos());
    block.setTextEnd("300000000");
    ASSERT_EQ(300000000, block.getEnd());
}
