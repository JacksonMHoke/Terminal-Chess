#ifndef BOARD_TEST_HPP
#define BOARD_TEST_HPP

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

using std::stringstream;

//addPiece does not take into account out of bounds, etc
//will just throw errors or create leaks if not careful
TEST(Board, addPieceAllPieces) {
    Board* b=new Board();
    b->addPiece(new Pawn('a','1','w','P', b));
    b->addPiece(new Rook('a','2','w','R', b));
    b->addPiece(new Knight('a','3','w','N', b));
    b->addPiece(new Bishop('a','4','w','B', b));
    b->addPiece(new King('a','5','w','K', b));
    b->addPiece(new Queen('a','6','w','Q', b));
    b->addPiece(new Pawn('b','1','b','p', b));
    b->addPiece(new Rook('b','2','b','r', b));
    b->addPiece(new Knight('b','3','b','n', b));
    b->addPiece(new Bishop('b','4','b','b', b));
    b->addPiece(new King('b','5','b','k', b));
    b->addPiece(new Queen('b','6','b','q', b));
    EXPECT_EQ('P', b->getCell('a','1')->getPiece());
    EXPECT_EQ('R', b->getCell('a','2')->getPiece());
    EXPECT_EQ('N', b->getCell('a','3')->getPiece());
    EXPECT_EQ('B', b->getCell('a','4')->getPiece());
    EXPECT_EQ('K', b->getCell('a','5')->getPiece());
    EXPECT_EQ('Q', b->getCell('a','6')->getPiece());
    EXPECT_EQ('p', b->getCell('b','1')->getPiece());
    EXPECT_EQ('r', b->getCell('b','2')->getPiece());
    EXPECT_EQ('n', b->getCell('b','3')->getPiece());
    EXPECT_EQ('b', b->getCell('b','4')->getPiece());
    EXPECT_EQ('k', b->getCell('b','5')->getPiece());
    EXPECT_EQ('q', b->getCell('b','6')->getPiece());
    delete b;
}

TEST(Board, getCell) {
    Board* b=new Board();
    b->addPiece(new Pawn('a','1','w','P', b));
    b->addPiece(new Rook('a','2','w','R', b));
    b->addPiece(new Knight('a','3','w','N', b));
    b->addPiece(new Bishop('a','4','w','B', b));
    b->addPiece(new King('a','5','w','K', b));
    b->addPiece(new Queen('a','6','w','Q', b));
    b->addPiece(new Pawn('b','1','b','p', b));
    b->addPiece(new Rook('b','2','b','r', b));
    b->addPiece(new Knight('b','3','b','n', b));
    b->addPiece(new Bishop('b','4','b','b', b));
    b->addPiece(new King('b','5','b','k', b));
    b->addPiece(new Queen('b','6','b','q', b));

    //testing if correct piece is gotten
    EXPECT_EQ('P', b->getCell('a','1')->getPiece());
    EXPECT_EQ('R', b->getCell('a','2')->getPiece());
    EXPECT_EQ('N', b->getCell('a','3')->getPiece());
    EXPECT_EQ('B', b->getCell('a','4')->getPiece());
    EXPECT_EQ('K', b->getCell('a','5')->getPiece());
    EXPECT_EQ('Q', b->getCell('a','6')->getPiece());
    EXPECT_EQ('p', b->getCell('b','1')->getPiece());
    EXPECT_EQ('r', b->getCell('b','2')->getPiece());
    EXPECT_EQ('n', b->getCell('b','3')->getPiece());
    EXPECT_EQ('b', b->getCell('b','4')->getPiece());
    EXPECT_EQ('k', b->getCell('b','5')->getPiece());
    EXPECT_EQ('q', b->getCell('b','6')->getPiece());

    //testing if nullptr is returned correctly
    EXPECT_EQ(nullptr, b->getCell('c', '1'));
    EXPECT_EQ(nullptr, b->getCell('/', '3'));
    EXPECT_EQ(nullptr, b->getCell('c', '{'));
    EXPECT_EQ(nullptr, b->getCell('|', '/'));
    EXPECT_EQ(nullptr, b->getCell('z', '9'));
    delete b;
}

TEST(Board, setCellNull) {
    Board* b=new Board();
    b->addPiece(new Pawn('a','1','w','P', b));
    b->addPiece(new Rook('a','2','w','R', b));
    b->addPiece(new Knight('a','3','w','N', b));
    b->addPiece(new Bishop('a','4','w','B', b));
    b->addPiece(new King('a','5','w','K', b));
    b->addPiece(new Queen('a','6','w','Q', b));
    b->addPiece(new Pawn('b','1','b','p', b));
    b->addPiece(new Rook('b','2','b','r', b));
    b->addPiece(new Knight('b','3','b','n', b));
    b->addPiece(new Bishop('b','4','b','b', b));
    b->addPiece(new King('b','5','b','k', b));
    b->addPiece(new Queen('b','6','b','q', b));

    Piece* temp;

    //testing setting existing pieces to null
        //causes memory leaks by design
    temp=b->getCell('a', '1');
    b->setCellNull('a', '1');
    EXPECT_EQ(nullptr, b->getCell('a', '1'));
    delete temp;

    temp=b->getCell('a', '2');
    b->setCellNull('a', '2');
    EXPECT_EQ(nullptr, b->getCell('a', '2'));
    delete temp;

    temp=b->getCell('a', '3');
    b->setCellNull('a', '3');
    EXPECT_EQ(nullptr, b->getCell('a', '3'));
    delete temp;

    temp=b->getCell('a', '4');
    b->setCellNull('a', '4');
    EXPECT_EQ(nullptr, b->getCell('a', '4'));
    delete temp;

    temp=b->getCell('b', '1');
    b->setCellNull('b', '1');
    EXPECT_EQ(nullptr, b->getCell('b', '1'));
    delete temp;


    //testing setCellNull on already nullptr
    b->setCellNull('a', '1');
    EXPECT_EQ(nullptr, b->getCell('a', '1'));

    delete b;
}

TEST(Board, move) {
    Board* b=new Board();

    b->addPiece(new Pawn('a', '1', 'b', 'p', b));
    b->move('a', '1', 'h', '8');
    EXPECT_EQ('p', b->getCell('h', '8')->getPiece());

    //testing replacing pawn
    b->addPiece(new Queen('b', '2', 'b', 'q', b));
    b->move('b','2','h','8');
    EXPECT_EQ('q', b->getCell('h','8')->getPiece());

    //testing if piece coords updated
    EXPECT_EQ('h', b->getCell('h','8')->getCol());
    EXPECT_EQ('8', b->getCell('h','8')->getRow());

    delete b;
}

TEST(Board, drawBoard) {
    stringstream os;
    //testing classical board
    BoardFactory* fact = new ClassicBoardFactory();
    Board* b=fact->createBoard();

    b->drawBoard2('w', os);
    EXPECT_EQ("rnbqkbnr\npppppppp\n        \n        \n        \n        \nPPPPPPPP\nRNBQKBNR\n", os.str());

    delete b;
    delete fact;
}

#endif //BOARD_TEST_HPP