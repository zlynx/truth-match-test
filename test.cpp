#include "functions.h"
#include "test-cases.h"
#include <gtest/gtest.h>

const char bigstring[] =
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
    "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
    "xxxxxxxxxxxxxxxxxxxxxxxx";
const size_t bigstring_len = sizeof(bigstring);

TEST(ToBoolTest, zlynx1) {
  EXPECT_EQ(zlynx1_tobool("true"), 1);
  EXPECT_EQ(zlynx1_tobool("false"), 0);
  EXPECT_EQ(zlynx1_tobool("True"), 1);
  EXPECT_EQ(zlynx1_tobool("False"), 0);
  EXPECT_EQ(zlynx1_tobool("1"), 1);
  EXPECT_EQ(zlynx1_tobool("0"), 0);
  EXPECT_EQ(zlynx1_tobool(""), -1);
  EXPECT_EQ(zlynx1_tobool(bigstring), -1);
}

TEST(ToBoolTest, zlynx2) {
  EXPECT_EQ(zlynx2_tobool("true"), 1);
  EXPECT_EQ(zlynx2_tobool("false"), 0);
  EXPECT_EQ(zlynx2_tobool("True"), 1);
  EXPECT_EQ(zlynx2_tobool("False"), 0);
  EXPECT_EQ(zlynx2_tobool("1"), 1);
  EXPECT_EQ(zlynx2_tobool("0"), 0);
  EXPECT_EQ(zlynx2_tobool(""), -1);
  EXPECT_EQ(zlynx2_tobool(bigstring), -1);
}

TEST(ToBoolTest, wovano) {
  EXPECT_EQ(wovano_tobool("true"), 1);
  EXPECT_EQ(wovano_tobool("false"), 0);
  EXPECT_EQ(wovano_tobool("True"), 1);
  EXPECT_EQ(wovano_tobool("False"), 0);
  EXPECT_EQ(wovano_tobool("1"), 1);
  EXPECT_EQ(wovano_tobool("0"), 0);
  EXPECT_EQ(wovano_tobool(""), -1);
  EXPECT_EQ(wovano_tobool(bigstring), -1);
}

TEST(ToBoolTest, chux1) {
  EXPECT_EQ(chux1_tobool("true"), 1);
  EXPECT_EQ(chux1_tobool("false"), 0);
  EXPECT_EQ(chux1_tobool("True"), 1);
  EXPECT_EQ(chux1_tobool("False"), 0);
  EXPECT_EQ(chux1_tobool("1"), 1);
  EXPECT_EQ(chux1_tobool("0"), 0);
  EXPECT_EQ(chux1_tobool(""), -1);
  EXPECT_EQ(chux1_tobool(bigstring), -1);
}

TEST(ToBoolTest, chux2) {
  EXPECT_EQ(chux2_tobool("true"), 1);
  EXPECT_EQ(chux2_tobool("false"), 0);
  EXPECT_EQ(chux2_tobool("True"), 1);
  EXPECT_EQ(chux2_tobool("False"), 0);
  EXPECT_EQ(chux2_tobool("1"), 1);
  EXPECT_EQ(chux2_tobool("0"), 0);
  EXPECT_EQ(chux2_tobool(""), -1);
  EXPECT_EQ(chux2_tobool(bigstring), -1);
}

TEST(ToBoolTest, user) {
  EXPECT_EQ(user_tobool("true", 4), 1);
  EXPECT_EQ(user_tobool("false", 5), 0);
  EXPECT_EQ(user_tobool("True", 4), 1);
  EXPECT_EQ(user_tobool("False", 5), 0);
  EXPECT_EQ(user_tobool("1", 1), 1);
  EXPECT_EQ(user_tobool("0", 1), 0);
  EXPECT_EQ(user_tobool("", 0), -1);
  EXPECT_EQ(user_tobool(bigstring, bigstring_len), -1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
