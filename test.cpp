#include "gtest/gtest.h"

#include "tests/board_test.hpp"
#include "tests/piece_test.hpp"
#include "tests/movement_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
