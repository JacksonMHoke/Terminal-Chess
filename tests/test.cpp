#include "gtest/gtest.h"

#include "board_test.hpp"
#include "piece_test.hpp"
#include "movement_test.hpp"
#include "bishop_test.hpp"
#include "rook_test.hpp"
#include "knight_test.hpp"
#include "queen_test.hpp"
#include "ClassicBoardFactory_test.hpp"
#include "HoardBoardFactory_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
