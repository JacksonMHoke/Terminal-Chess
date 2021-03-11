#ifndef QUEEN_TEST_HPP
#define QUEEN_TEST_HPP

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

//north
TEST(QUEEN, QMoveNorth){
	Board* board;
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('d','2')->move('d','3');
	board->getCell('d','3')->move('d','4');
	board->getCell('d','1')->move('d','3');
	EXPECT_EQ(board->getCell('d','3')->getPiece(),'Q');
	EXPECT_EQ(board->getCell('d','3')->getColor(),'w');
	delete board;
	delete fact;
}

//NorthEast
TEST(QUEEN, QMoveNorthEast){
	Board* board;
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('d','2')->move('d','3');
	board->getCell('d','3')->move('d','4');
	board->getCell('d','1')->move('d','3');
	board->getCell('d','3')->move('f','5');
	EXPECT_EQ(board->getCell('f','5')->getPiece(),'Q');
	EXPECT_EQ(board->getCell('f','5')->getColor(),'w');
	delete board;
	delete fact;
}

//East
TEST(QUEEN, QMoveEast){
	Board* board;
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('d','2')->move('d','3');
	board->getCell('d','3')->move('d','4');
	board->getCell('d','1')->move('d','3');
	board->getCell('d','3')->move('g','3');
	EXPECT_EQ(board->getCell('g','3')->getPiece(),'Q');
	EXPECT_EQ(board->getCell('g','3')->getColor(),'w');
	delete board;
	delete fact;
}


//SouthEast
TEST(QUEEN, QMoveSouthEast){
	Board* board;
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('d','2')->move('d','3');
	board->getCell('d','3')->move('d','4');
	board->getCell('d','1')->move('d','3');
	board->getCell('d','3')->move('f','5');
	board->getCell('f','5')->move('h','3');
	EXPECT_EQ(board->getCell('h','3')->getPiece(),'Q');
	EXPECT_EQ(board->getCell('h','3')->getColor(),'w');
	delete board;
	delete fact;
}

//South
TEST(QUEEN, QMoveSouth){
	Board* board;
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('d','2')->move('d','3');
	board->getCell('d','3')->move('d','4');
	board->getCell('d','1')->move('d','3');
	board->getCell('d','3')->move('f','5');
	board->getCell('f','5')->move('f','3');
	EXPECT_EQ(board->getCell('f','3')->getPiece(),'Q');
	EXPECT_EQ(board->getCell('f','3')->getColor(),'w');
	delete board;
	delete fact;
}

//SouthWest
TEST(QUEEN, QMoveSouthWest){
	Board* board;
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('d','2')->move('d','3');
	board->getCell('d','3')->move('d','4');
	board->getCell('d','1')->move('d','3');
	board->getCell('d','3')->move('f','5');
	board->getCell('f','5')->move('d','3');
	EXPECT_EQ(board->getCell('d','3')->getPiece(),'Q');
	EXPECT_EQ(board->getCell('d','3')->getColor(),'w');
	delete board;
	delete fact;
}

//West
TEST(QUEEN, QMoveWest){
	Board* board;
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('d','2')->move('d','3');
	board->getCell('d','3')->move('d','4');
	board->getCell('d','1')->move('d','3');
	board->getCell('d','3')->move('f','5');
	board->getCell('f','5')->move('f','3');
	board->getCell('f','3')->move('d','3');
	EXPECT_EQ(board->getCell('d','3')->getPiece(),'Q');
	EXPECT_EQ(board->getCell('d','3')->getColor(),'w');
	delete board;
	delete fact;
}

//NorthWest
TEST(QUEEN, QMoveNorthWest){
	Board* board;
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('d','2')->move('d','3');
	board->getCell('d','3')->move('d','4');
	board->getCell('d','1')->move('d','3');
	board->getCell('d','3')->move('f','5');
	board->getCell('f','5')->move('f','3');
	board->getCell('f','3')->move('d','3');
	board->getCell('d','3')->move('a','6');
	EXPECT_EQ(board->getCell('a','6')->getPiece(),'Q');
	EXPECT_EQ(board->getCell('a','6')->getColor(),'w');
	delete board;
	delete fact;
}


//queen same color
TEST(QUEEN, QMoveToSameColorPiece){
	Board* board;
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	EXPECT_EQ(board->getCell('d','1')->move('e','1'),false);
	delete board;
	delete fact;
}

//op color take
TEST(QUEEN, QTakeOpPiece){
	Board* board;
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('d','2')->move('d','3');
	board->getCell('d','3')->move('d','4');
	board->getCell('d','1')->move('d','3');
	board->getCell('d','3')->move('f','5');
	board->getCell('f','5')->move('f','7');
	EXPECT_EQ(board->getCell('f','7')->getPiece(),'Q');
	EXPECT_EQ(board->getCell('f','7')->getColor(),'w');
	delete board;
	delete fact;
}

TEST(QUEEN, RCheck){
	Board* board;
	board->addPiece(new Queen ('f', '2', 'b', 'q',   board));
	board->addPiece(new King  ('e', '6', 'w', 'K',   board));
	EXPECT_EQ(board->getCell('e','6')->move('f','6'),false);
	delete board;
}
#endif