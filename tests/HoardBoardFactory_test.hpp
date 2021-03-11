#ifndef HOARDBOARDFACTORY_TEST
#define HOARDBOARDFACTORY_TEST

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

TEST(HOARDBOARD, HoardWhite){
	Board* b = new Board();
	BoardFactory* fact= new HoardBoardFactory();
	std::stringstream ss;
    b = fact->createBoard();
    b->drawBoard(ss, 'w');
	EXPECT_EQ(ss.str(),"rnbqkbnr\npppppppp\n********\n********\nPPPPPPPP\nPPPPPPPP\nPPPPPPPP\nPPPPPPPP\n");
	delete b;
	delete fact;
}

//TEST(HOARDBOARD, HoardBlack){
//	Board* b = new Board();
//	BoardFactory* fact = new HoardBoardFactory;
//	std::stringstream ss;
//   b = fact->createBoard();
//    b->drawBoard(ss, 'b');
//	EXPECT_EQ(ss.str(),"PPPPPPPP\nPPPPPPPP\nPPPPPPPP\nPPPPPPPP\n********\n********\npppppppp\nrnbqkbnr\n");
//	delete b;
//	delete fact;
//}
#endif