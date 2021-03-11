#ifndef ROOK_TEST_HPP
#define ROOK_TEST_HPP

#include "gtest/gtest.h"
#include "board.hpp"
#include "movement/MovementBehavior.hpp"
#include "pieces/piece.hpp"
#include "BoardFactory.hpp"
#include "ClassicBoardFactory.hpp"
#include "HoardBoardFactory.hpp"
#include <iostream>
#include <string>
#include <vector>

TEST(ROOK, RMoveNorth){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('a','2')->move('a','3');
	board->getCell('a','3')->move('a','4');
	board->getCell('a','1')->move('a','3');
	EXPECT_EQ(board->getCell('a','3')->getPiece(),'R');
	EXPECT_EQ(board->getCell('a','3')->getColor(),'w');
	delete board;
	delete fact;
}

TEST(ROOK, RMoveEast){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('a','2')->move('a','3');
	board->getCell('a','3')->move('a','4');
	board->getCell('a','1')->move('a','3');
	board->getCell('a','3')->move('e','3');
	//EXPECT_EQ(false,board->getCell('e','3')->isCheck());
	EXPECT_EQ(board->getCell('e','3')->getPiece(),'R');
	EXPECT_EQ(board->getCell('e','3')->getColor(),'w');
	delete board;
	delete fact;
}

TEST(ROOK, RMoveWest){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('a','2')->move('a','3');
	board->getCell('a','3')->move('a','4');
	board->getCell('a','1')->move('a','3');
	board->getCell('a','3')->move('e','3');
	board->getCell('e','3')->move('e','5');
	board->getCell('e','5')->move('c','5');
	EXPECT_EQ(board->getCell('c','5')->getPiece(),'R');
	EXPECT_EQ(board->getCell('c','5')->getColor(),'w');
	delete board;
	delete fact;
}

TEST(ROOK, RMoveSouth){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('a','2')->move('a','3');
	board->getCell('a','3')->move('a','4');
	board->getCell('a','1')->move('a','3');
	board->getCell('a','3')->move('a','1');
	EXPECT_EQ(board->getCell('a','1')->getPiece(),'R');
	EXPECT_EQ(board->getCell('a','1')->getColor(),'w');
	delete board;
	delete fact;
}

TEST(ROOK, RMoveToSameColorPiece){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	EXPECT_EQ(board->getCell('a','1')->move('a','2'),false);
	delete board;
	delete fact;
}

TEST(ROOK, RTakeOpPiece){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('a','2')->move('a','3');
	board->getCell('a','3')->move('a','4');
	board->getCell('a','1')->move('a','3');
	board->getCell('a','3')->move('b','3');
	board->getCell('b','3')->move('b','7');
	EXPECT_EQ(board->getCell('b','7')->getPiece(),'R');
	EXPECT_EQ(board->getCell('b','7')->getColor(),'w');
	delete board;
	delete fact;
}

//check
TEST(ROOK, RCheck){
	Board* board = new Board();
	board->addPiece(new Rook  ('h', '8', 'b', 'r',   board));
	board->addPiece(new King  ('e', '6', 'w', 'K',   board));
	EXPECT_EQ(board->getCell('h','8')->move('h','6'),true);
}

#endif
