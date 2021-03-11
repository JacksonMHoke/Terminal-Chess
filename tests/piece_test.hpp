#ifndef PIECE_TEST_HPP
#define PIECE_TEST_HPP

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
#include <sstream>

//pawn king

TEST(Piece, Pawn) {
    BoardFactory* fact = new ClassicBoardFactory();
    Board* b = fact->createBoard();

    //checking if all board/piece variables change accordingly
    //when moving the pawn 1 up
    b->getCell('e','2')->move('e','3');
    ASSERT_EQ('P', b->getCell('e','3')->getPiece());
    ASSERT_EQ('e', b->getCell('e','3')->getCol());
    ASSERT_EQ('3', b->getCell('e','3')->getRow());
    ASSERT_EQ('w', b->getCell('e','3')->getColor());


    //checking if invalid move keeps all stats the same
    b->getCell('e','3')->move('f','4');
    ASSERT_EQ('P', b->getCell('e','3')->getPiece());
    ASSERT_EQ('e', b->getCell('e','3')->getCol());
    ASSERT_EQ('3', b->getCell('e','3')->getRow());
    ASSERT_EQ('w', b->getCell('e','3')->getColor());


    //checking if moving 2 not from initial pos will keep all stats the same
    b->getCell('e','3')->move('e','5');
    ASSERT_EQ('P', b->getCell('e','3')->getPiece());
    ASSERT_EQ('e', b->getCell('e','3')->getCol());
    ASSERT_EQ('3', b->getCell('e','3')->getRow());
    ASSERT_EQ('w', b->getCell('e','3')->getColor());


    //checking for black pawn movement
    b->getCell('f','7')->move('f','6');
    b->getCell('f','6')->move('f','5');
    b->getCell('f','5')->move('f','4');
    ASSERT_EQ('p', b->getCell('f','4')->getPiece());
    ASSERT_EQ('f', b->getCell('f','4')->getCol());
    ASSERT_EQ('4', b->getCell('f','4')->getRow());
    ASSERT_EQ('b', b->getCell('f','4')->getColor());


    //checking for white taking diagonally
    b->getCell('e','3')->move('f','4');
    ASSERT_EQ('P', b->getCell('f','4')->getPiece());
    ASSERT_EQ('f', b->getCell('f','4')->getCol());
    ASSERT_EQ('4', b->getCell('f','4')->getRow());
    ASSERT_EQ('w', b->getCell('f','4')->getColor());


    //checking for black taking diagonally
    b->getCell('e','7')->move('e','6');
    b->getCell('e','6')->move('e','5');
    b->getCell('e','5')->move('f','4');
    ASSERT_EQ('p', b->getCell('f','4')->getPiece());
    ASSERT_EQ('f', b->getCell('f','4')->getCol());
    ASSERT_EQ('4', b->getCell('f','4')->getRow());
    ASSERT_EQ('b', b->getCell('f','4')->getColor());

    //checking for black giving invalid move when pawn move
    //puts own king in check
    b->getCell('f','1')->move('b','5');
    ASSERT_EQ(false, b->getCell('d','7')->move('d','6'));


    //checking if pawn move can block a check on black king
    b->getCell('b','5')->move('c','4');
    b->getCell('d','7')->move('d','6');
    b->getCell('c','4')->move('b','5');
    ASSERT_EQ(true, b->getCell('c','7')->move('c','6'));

    delete b;
    delete fact;
}

TEST(Piece, King) {
    //Testing if king can move in all possible directions
    Board* b = new Board();
    b->addPiece(new King('e','4','w','K', b));
    ASSERT_EQ('K', b->getCell('e','4')->getPiece());
    ASSERT_EQ('4', b->getCell('e','4')->getRow());
    ASSERT_EQ('e', b->getCell('e','4')->getCol());
    ASSERT_EQ('w', b->getCell('e','4')->getColor());
    //testing moving up
    b->getCell('e','4')->move('e','5');
    ASSERT_EQ('K', b->getCell('e','5')->getPiece());
    ASSERT_EQ('5', b->getCell('e','5')->getRow());
    ASSERT_EQ('e', b->getCell('e','5')->getCol());
    ASSERT_EQ('w', b->getCell('e','5')->getColor());
    //testing moving down
    b->getCell('e','5')->move('e','4');
    ASSERT_EQ('K', b->getCell('e','4')->getPiece());
    ASSERT_EQ('4', b->getCell('e','4')->getRow());
    ASSERT_EQ('e', b->getCell('e','4')->getCol());
    ASSERT_EQ('w', b->getCell('e','4')->getColor());
    //testing moving right
    b->getCell('e','4')->move('f','4');
    ASSERT_EQ('K', b->getCell('f','4')->getPiece());
    ASSERT_EQ('4', b->getCell('f','4')->getRow());
    ASSERT_EQ('f', b->getCell('f','4')->getCol());
    ASSERT_EQ('w', b->getCell('f','4')->getColor());
    //testing moving left
    b->getCell('f','4')->move('e','4');
    ASSERT_EQ('K', b->getCell('e','4')->getPiece());
    ASSERT_EQ('4', b->getCell('e','4')->getRow());
    ASSERT_EQ('e', b->getCell('e','4')->getCol());
    ASSERT_EQ('w', b->getCell('e','4')->getColor());
    //testing downleft
    b->getCell('e','4')->move('d','3');
    ASSERT_EQ('K', b->getCell('d','3')->getPiece());
    ASSERT_EQ('3', b->getCell('d','3')->getRow());
    ASSERT_EQ('d', b->getCell('d','3')->getCol());
    ASSERT_EQ('w', b->getCell('d','3')->getColor());
    //testing up right
    b->getCell('d','3')->move('e','4');
    ASSERT_EQ('K', b->getCell('e','4')->getPiece());
    ASSERT_EQ('4', b->getCell('e','4')->getRow());
    ASSERT_EQ('e', b->getCell('e','4')->getCol());
    ASSERT_EQ('w', b->getCell('e','4')->getColor());
    //testing down right
    b->getCell('e','4')->move('f','3');
    ASSERT_EQ('K', b->getCell('f','3')->getPiece());
    ASSERT_EQ('3', b->getCell('f','3')->getRow());
    ASSERT_EQ('f', b->getCell('f','3')->getCol());
    ASSERT_EQ('w', b->getCell('f','3')->getColor());
    //testing up right
    b->getCell('f','3')->move('e','4');
    ASSERT_EQ('K', b->getCell('e','4')->getPiece());
    ASSERT_EQ('4', b->getCell('e','4')->getRow());
    ASSERT_EQ('e', b->getCell('e','4')->getCol());
    ASSERT_EQ('w', b->getCell('e','4')->getColor());

    //testing king moving off the board
    b->addPiece(new King('a','1','b','k',b));
    ASSERT_EQ(false, b->getCell('a','1')->move('a','0'));
    ASSERT_EQ(false, b->getCell('a','1')->move('b','0'));
    ASSERT_EQ(false, b->getCell('a','1')->move('a','0'));
    ASSERT_EQ(false, b->getCell('a','1')->move('/','0'));

    //testing if king can move into check
    b->addPiece(new Rook('a','2','w','R',b));
    ASSERT_EQ(false, b->getCell('a','1')->move('b','2'));
    ASSERT_EQ(true, b->getCell('a','1')->move('b','1'));
    ASSERT_EQ(true, b->getCell('b','1')->move('a','2'));

    delete b;
}

TEST(TestTest, createBoard) {
    BoardFactory* fact = new ClassicBoardFactory();
    Board* b = fact->createBoard();
    EXPECT_EQ(true, true);

    delete b;
    delete fact;
}

#endif //PIECE_TEST_HPP