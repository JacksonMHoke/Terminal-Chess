#ifndef MOVEMENT_TEST_HPP
#define MOVEMENT_TEST_HPP

#include "gtest/gtest.h"
#include "../board.hpp"
#include "../movement/MovementBehavior.hpp"
#include "../pieces/piece.hpp"
#include "../BoardFactory.hpp"
#include "../ClassicBoardFactory.hpp"
#include "../HoardBoardFactory.hpp"
#include <iostream>
#include <string>
#include <vector>

TEST(MovementBehavior, PawnMove) {
	EXPECT_EQ(false, true);	
}

TEST(MovementBehavior, RookMove) {
        EXPECT_EQ(false, true);
}

TEST(MovementBehavior, BishopMove) {
        EXPECT_EQ(false, true);
}

TEST(MovementBehavior, KnightMove) {
        EXPECT_EQ(false, true);
}

TEST(MovementBehavior, KingMove) {
        EXPECT_EQ(false, true);
}

TEST(MovementBehavior, QueenMove) {
        EXPECT_EQ(false, true);
}

TEST(MovementBehavior, InvalidPawnMove) {
        EXPECT_EQ(false, true);
}

TEST(MovementBehavior, InvalidRookMove) {
        EXPECT_EQ(false, true);
}

TEST(MovementBehavior, InvalidBishopMove) {
        EXPECT_EQ(false, true);
}

TEST(MovementBehavior, InvalidKnightMove) {
        EXPECT_EQ(false, true);
}

TEST(MovementBehavior, InvalidKingMove) {
        EXPECT_EQ(false, true);
}

TEST(MovementBehavior, InvalidQueenMove) {
        EXPECT_EQ(false, true);
}

#endif
