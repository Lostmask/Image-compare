#include <gtest/gtest.h>
#include "imgcompare.h"

TEST(Dummy, empty)
{
    SUCCEED();
}
TEST(ImagesCompare, create)
{
    auto comp = mycompare::ImagesCompare::create("test_name", "test_name2");
}
TEST(ImagesComapare, run_on_same)
{
    auto comp = mycompare::ImagesCompare::create("test_files/test_pic_1.png", "test_files/test_pic_1.png");
    EXPECT_EQ(100, comp->run());
}