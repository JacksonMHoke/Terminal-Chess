#ifndef __BOARD_H__
#define __BOARD_H__

#include "pieces/piece.hpp"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class Board {
    private:
        vector<vector<Piece*>> board;
    public:
        Board();
        ~Board();
        //adds the piece into the board
            //uses info inside piece such as position
        void addPiece(Piece* p);

        //return the piece at cell (l, n)
        //if l or n are out of bounds returns nullptr
        Piece* getCell(char l, char n);

        void setCellNull(char l, char n);

        int getHeight() { return board[0].size(); }
        int getWidth() { return board.size(); }

        void move(char startL, char startN, char endL, char endN);
        //draws board according to color of player moving
        //TODO::implement colors in command line
        void drawBoard(char c);
};

#endif //__BOARD_H_