#ifndef KNIGHT_TEST_HPP
#define KNIGHT_TEST_HPP

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

//upleft
TEST(KNIGHT, NMoveUpLeft){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('b','1')->move('a','3');
	EXPECT_EQ(board->getCell('a','3')->getPiece(),'N');
	EXPECT_EQ(board->getCell('a','3')->getColor(),'w');
	delete board;
	delete fact;
}

//upright
TEST(KNIGHT, NMoveUpRight){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('b','1')->move('c','3');
	EXPECT_EQ(board->getCell('c','3')->getPiece(),'N');
	EXPECT_EQ(board->getCell('c','3')->getColor(),'w');
	delete board;
	delete fact;
}

//rightup
TEST(KNIGHT, NMoveRightUp){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('b','1')->move('c','3');
	board->getCell('c','3')->move('e','4');
	EXPECT_EQ(board->getCell('e','4')->getPiece(),'N');
	EXPECT_EQ(board->getCell('e','4')->getColor(),'w');
	delete board;
	delete fact;
}

//rightdown
TEST(KNIGHT, NMoveRightDown){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('b','1')->move('c','3');
	board->getCell('c','3')->move('e','4');
	board->getCell('e','4')->move('g','3');
	EXPECT_EQ(board->getCell('g','3')->getPiece(),'N');
	EXPECT_EQ(board->getCell('g','3')->getColor(),'w');
	delete board;
	delete fact;
}

//downright
TEST(KNIGHT, NMoveDownRight){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('b','1')->move('c','3');
	board->getCell('c','3')->move('e','4');
	board->getCell('f','2')->move('f','3');
	board->getCell('e','4')->move('f','2');
	EXPECT_EQ(board->getCell('f','2')->getPiece(),'N');
	EXPECT_EQ(board->getCell('f','2')->getColor(),'w');
	delete board;
	delete fact;
}


//downleft
TEST(KNIGHT, NMoveDownLeft){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('b','1')->move('c','3');
	board->getCell('c','3')->move('e','4');
	board->getCell('d','2')->move('d','3');
	board->getCell('e','4')->move('d','2');
	EXPECT_EQ(board->getCell('d','2')->getPiece(),'N');
	EXPECT_EQ(board->getCell('d','2')->getColor(),'w');
	delete board;
	delete fact;
}

//leftdown
TEST(KNIGHT, NMoveLeftDown){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('b','1')->move('c','3');
	board->getCell('c','3')->move('e','4');
	board->getCell('e','4')->move('c','3');
	EXPECT_EQ(board->getCell('c','3')->getPiece(),'N');
	EXPECT_EQ(board->getCell('c','3')->getColor(),'w');
	delete board;
	delete fact;
}

//leftup
TEST(KNIGHT, NMoveLeftUp){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('b','1')->move('c','3');
	board->getCell('c','3')->move('e','4');
	board->getCell('e','4')->move('c','5');
	EXPECT_EQ(board->getCell('c','5')->getPiece(),'N');
	EXPECT_EQ(board->getCell('c','5')->getColor(),'w');
	delete board;
	delete fact;
}

//same color
TEST(KNIGHT, NSameColor){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	EXPECT_EQ(board->getCell('b','1')->move('d','2'),false);
	delete board;
	delete fact;
}

//take op piece
TEST(KNIGHT, NTakeOpPiece){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('b','1')->move('c','3');
	board->getCell('c','3')->move('e','4');
	board->getCell('e','4')->move('f','6');
	board->getCell('f','6')->move('d','7');
	EXPECT_EQ(board->getCell('d','7')->getPiece(),'N');
	EXPECT_EQ(board->getCell('d','7')->getColor(),'w');
	delete board;
	delete fact;
}
TEST(KNIGHT, NCheck){
	Board* board = new Board();
	board->addPiece(new Knight('e', '4', 'b', 'n',   board));
	board->addPiece(new King  ('e', '6', 'w', 'K',   board));
	EXPECT_EQ(board->getCell('e','6')->move('f','6'),false);
	delete board;
}

#endif