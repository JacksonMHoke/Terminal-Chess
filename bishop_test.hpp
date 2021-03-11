#ifndef BISHOP_TEST_HPP
#define BISHOP_TEST_HPP

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


//moves SE
TEST(BISHOP, BMOVESE){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('g','7')->move('g','6');
	board->getCell('f','8')->move('h','6');
	EXPECT_EQ(board->getCell('h','6')->getPiece(),'b');
	EXPECT_EQ(board->getCell('h','6')->getColor(),'b');
	delete board;
	delete fact;
}

//movesSW
TEST(BISHOP, BMOVESW){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('g','7')->move('g','6');
	board->getCell('f','8')->move('h','6');
	board->getCell('h','6')->move('f','4');
	EXPECT_EQ(board->getCell('f','4')->getPiece(),'b');
	EXPECT_EQ(board->getCell('f','4')->getColor(),'b');
	delete board;
	delete fact;
}

//movesNE
TEST(BISHOP, BMOVENE){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('g','7')->move('g','6');
	board->getCell('f','8')->move('h','6');
	board->getCell('h','6')->move('f','4');
	board->getCell('f','4')->move('h','6');
	EXPECT_EQ(board->getCell('h','6')->getPiece(),'b');
	EXPECT_EQ(board->getCell('h','6')->getColor(),'b');
	delete board;
	delete fact;
}

//movesNW
TEST(BISHOP, BMOVENW){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('g','7')->move('g','6');
	board->getCell('f','8')->move('h','6');
	board->getCell('h','6')->move('f','8');
	EXPECT_EQ(board->getCell('f','8')->getPiece(),'b');
	EXPECT_EQ(board->getCell('f','8')->getColor(),'b');
	delete board;
	delete fact;
}

//if same piece return false
TEST(BISHOP, BMoveToSameColorSpot){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	EXPECT_EQ(board->getCell('f','8')->move('g','7'),false);
	delete board;
	delete fact;
}

//if opponent piece take
TEST(BISHOP, BTakeOPPiece){
	Board* board = new Board();
	BoardFactory* fact = new ClassicBoardFactory();
	board=fact->createBoard();
	board->getCell('g','7')->move('g','6');
	board->getCell('f','8')->move('h','6');
	board->getCell('h','6')->move('d','2');
	EXPECT_EQ(board->getCell('d','2')->getPiece(),'b');
	EXPECT_EQ(board->getCell('d','2')->getColor(),'b');
	delete board;
	delete fact;
}

//check
TEST(BISHOP, BCheck){
	Board* board = new Board();
	board->addPiece(new Bishop('g', '7', 'b', 'b',   board));
	board->addPiece(new King  ('e', '7', 'w', 'K',   board));
	EXPECT_EQ(board->getCell('e','7')->move('f','6'),false);
	delete board;
}
#endif
