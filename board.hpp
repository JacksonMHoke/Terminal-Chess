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
        vector<vector<Piece>> board;
    public:
        Board() {
            for (int i=0; i<board.size(); ++i) {
                for (int j=0; j<board[0].size(); ++j) {
                    board[i][j]=nullptr;
                }
            }
        }

        //adds the piece into the board
            //uses info inside piece such as position
        void addPiece(Piece* p) {
            board[p->getRow()-'1'][p->getCol()-'a']=*p;
        }

        //return the piece at cell (l, n)
        //if l or n are out of bounds returns nullptr
        Piece* getCell(char l, char n) {
            if (l>'h' || n>'8') return nullptr;
            return &board[n-'1'][l-'a'];
        }

        int getHeight() { return board[0].size(); }
        int getWidth() { return board.size(); }

        void move(char startL, char startN, char endL, char endN) {
            //turn char coords into 0-8 index coords
            int startRow=startN-'1';
            int startCol=startL-'a';
            int endRow=endN-'1';
            int endCol=endL-'a';
            //if there is a piece at (endL, endN) delete it to avoid memory leaks
            if (board[endRow][endCol]) delete board[endRow][endCol];

            //change piece coords
            board[startRow][startCol].setRow(endN);
            board[startRow][startCol].setCol(endL);
            //update board position
            board[endRow][endCol]=board[startRow][startCol];
            board[startRow][startCol]=nullptr;
        }
        //draws board according to color of player moving
        //TODO::implement colors in command line
        void drawBoard(char c) {
            for (int i=0; i<board.size(); ++i) {
                for (int j=0; j<board[0].size(); ++j) {
                    //if white is moving next
                    if (c=='w') {
                        if (!board[board.size()-1-i][j]) cout << "*";
                        else cout << board[board.size()-1-i][j].getPiece();
                    } else { //if black is moving next
                        if (!board[i][board[0].size()-1-j]) cout << "*";
                        else cout << board[i][board[0].size()-1-i].getPiece();
                    }
                }
                cout << endl;
            }
        }
};

#endif //__BOARD_H_
