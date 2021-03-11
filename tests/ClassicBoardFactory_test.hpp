#ifndef CLASSICBOARDFACTORY_TEST
#define CLASSICBOARDFACTORY_TEST

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

TEST(CLASSICBOARD, ClassicWhite){
    Board* b;
    BoardFactory* fact = new ClassicBoardFactory();
    std::stringstream ss;
    b = fact->createBoard();
    b->drawBoard(ss, 'w');
    EXPECT_EQ(ss.str(),"rnbqkbnr\npppppppp\n********\n********\n********\n********\nPPPPPPPP\nRNBQKBNR\n");
    delete b;
	delete fact;
}

//TEST(CLASSICBOARD, ClassicBlack){
//	Board* b;
//	BoardFactory* fact = new ClassicBoardFactory();
//	std::stringstream ss;
//   b = fact->createBoard();
//    b->drawBoard(ss, 'b');
//	EXPECT_EQ(ss.str(),"RNBQKBNR\nPPPPPPPP\n********\n********\n********\n********\nrnbqkbnr\npppppppp\n");
//	delete b;
//	delete fact;
//}
#endif