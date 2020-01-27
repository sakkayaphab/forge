#include <gtest/gtest.h>
#include <iostream>
#include "sim/variantrange.h"

TEST(FilePathTest, getFilePathName)
{
    std::cout << "Hello world" << std::endl;
}

TEST(FilePathTest, variantrange)
{
    VariantRange vr;
    vr.setTextRange("100-1000");
    ASSERT_EQ(100, vr.getMinLength());
    ASSERT_EQ(1000, vr.getMaxLength());
}
