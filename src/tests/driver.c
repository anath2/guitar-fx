#include "gtest/gtest.h"

double square_root (double x)
{
  return (x * x);
}

TEST (SquareRootTest, PositiveNos) {
    EXPECT_EQ (9, square_root (3));
}

int main() {
  return RUN_ALL_TESTS();
}
