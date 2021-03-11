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

TEST(MovementBehavior, PawnsMove) {
        Board* b = new Board();
        b->addPiece(new Pawn('c', '2', 'w', 'P', b));
        b->addPiece(new Pawn('c', '7', 'b', 'p', b));

        ASSERT_EQ(true, b->getCell('c', '2')->move('c', '3'));
        ASSERT_EQ(true, b->getCell('c', '7')->move('c', '5'));
        delete b;
}

TEST(MovementBehavior, RookMove) {
        Board* b = new Board();
        b->addPiece(new Rook('a', '1', 'w', 'R', b));
        b->addPiece(new Rook('a', '8', 'b', 'r', b));

        ASSERT_EQ(true, b->getCell('a', '1')->move('a', '7'));
        ASSERT_EQ(false, b->getCell('a', '8')->move('a', '3'));
        delete b;
}

TEST(MovementBehavior, BishopMove) {
        Board* b = new Board();
        b->addPiece(new Bishop('c', '1', 'w', 'B', b));
        b->addPiece(new Bishop('c', '8', 'b', 'b', b));

        ASSERT_EQ(true, b->getCell('c', '1')->move('e', '3'));
        ASSERT_EQ(true, b->getCell('c', '8')->move('g', '4'));
        delete b;
}

TEST(MovementBehavior, KnightMove) {
        Board* b = new Board();
        b->addPiece(new Knight('a', '5', 'w', 'N', b));

        ASSERT_EQ(true, b->getCell('a', '5')->move('b', '7'));
        ASSERT_EQ(true, b->getCell('b', '7')->move('d', '8'));
        ASSERT_EQ(true, b->getCell('d', '8')->move('f', '7'));
        ASSERT_EQ(true, b->getCell('f', '7')->move('g', '5'));
        ASSERT_EQ(true, b->getCell('g', '5')->move('f', '3'));
        ASSERT_EQ(true, b->getCell('f', '3')->move('d', '2'));
        ASSERT_EQ(true, b->getCell('d', '2')->move('b', '3'));
        ASSERT_EQ(true, b->getCell('b', '3')->move('a', '5'));
        delete b;
}

TEST(MovementBehavior, KingMove) {
        Board* b = new Board();
        b->addPiece(new King('d', '4', 'w', 'K', b));

        ASSERT_EQ(true, b->getCell('d', '4')->move('d', '5'));
        ASSERT_EQ(true, b->getCell('d', '5')->move('d', '4'));
        ASSERT_EQ(true, b->getCell('d', '4')->move('c', '4'));
        ASSERT_EQ(true, b->getCell('c', '4')->move('d', '4'));
        ASSERT_EQ(true, b->getCell('d', '4')->move('e', '5'));
        ASSERT_EQ(true, b->getCell('e', '5')->move('f', '4'));
        ASSERT_EQ(true, b->getCell('f', '4')->move('e', '3'));
        ASSERT_EQ(true, b->getCell('e', '3')->move('d', '4'));
        delete b;
}

TEST(MovementBehavior, QueenMove) {
        Board* b = new Board();
        b->addPiece(new Queen('d', '4', 'w', 'Q', b));

        ASSERT_EQ(true, b->getCell('d', '4')->move('d', '6'));
        ASSERT_EQ(true, b->getCell('d', '6')->move('d', '4'));
        ASSERT_EQ(true, b->getCell('d', '4')->move('b', '4'));
        ASSERT_EQ(true, b->getCell('b', '4')->move('d', '4'));
        ASSERT_EQ(true, b->getCell('d', '4')->move('f', '6'));
        ASSERT_EQ(true, b->getCell('f', '6')->move('h', '4'));
        ASSERT_EQ(true, b->getCell('h', '4')->move('f', '2'));
        ASSERT_EQ(true, b->getCell('f', '2')->move('d', '4'));
        delete b;
}

TEST(MovementBehavior, InvalidPawnMove) {
        Board* b = new Board();
        b->addPiece(new Pawn('c', '2', 'w', 'P', b));
        b->addPiece(new Pawn('c', '7', 'b', 'p', b));

        ASSERT_EQ(false, b->getCell('c', '2')->move('c', '5'));
        ASSERT_EQ(false, b->getCell('c', '7')->move('c', '8'));
        delete b;
}

TEST(MovementBehavior, InvalidRookMove) {
        Board* b = new Board();
        b->addPiece(new Rook('a', '1', 'w', 'R', b));
        b->addPiece(new Rook('a', '8', 'b', 'r', b));

        ASSERT_EQ(false, b->getCell('a', '1')->move('b', '7'));
        ASSERT_EQ(false, b->getCell('a', '8')->move('c', '3'));
        delete b;
}

TEST(MovementBehavior, InvalidBishopMove) {
        Board* b = new Board();
        b->addPiece(new Bishop('c', '1', 'w', 'B', b));
        b->addPiece(new Bishop('c', '8', 'b', 'b', b));

        ASSERT_EQ(false, b->getCell('c', '1')->move('e', '0'));
        ASSERT_EQ(false, b->getCell('c', '8')->move('c', '4'));
        delete b;
}

TEST(MovementBehavior, InvalidKnightMove) {
        Board* b = new Board();
        b->addPiece(new Knight('a', '5', 'w', 'N', b));

        ASSERT_EQ(false, b->getCell('a', '5')->move('b', '8'));
	delete b;
}

TEST(MovementBehavior, InvalidKingMove) {
        Board* b = new Board();
        b->addPiece(new King('d', '4', 'w', 'K', b));

        ASSERT_EQ(false, b->getCell('d', '4')->move('d', '6'));
	delete b;
}

TEST(MovementBehavior, InvalidQueenMove) {
        Board* b = new Board();
        b->addPiece(new Queen('d', '4', 'w', 'Q', b));

        ASSERT_EQ(false, b->getCell('d', '4')->move('e', '7'));
	delete b;
}

#endif
