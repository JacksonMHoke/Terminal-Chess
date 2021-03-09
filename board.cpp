#include "board.hpp"

//constructor
Board::Board()  {
    board.resize(8);
    for (int i=0; i<board.size(); ++i) {
        board[i].resize(8);
        for (int j=0; j<board[0].size(); ++j) {
            board[i][j]=nullptr;
        }
    }
}

void Board::addPiece(Piece* p)  {
    board[p->getRow()-'1'][p->getCol()-'a']=p;
}

Piece* Board::getCell(char l, char n)  {
    if (l>'h' || n>'8') return nullptr;
    return board[n-'1'][l-'a'];
}

void Board::setCellNull(char l, char n) {
    board[n-'1'][l-'a']=nullptr;
}

void Board::move(char startL, char startN, char endL, char endN) {
    //turn char coords into 0-8 index coords
    int startRow=startN-'1';
    int startCol=startL-'a';
    int endRow=endN-'1';
    int endCol=endL-'a';
    //if there is a piece at (endL, endN) delete it to avoid memory leaks
    if (board[endRow][endCol]!=nullptr) delete board[endRow][endCol];

    //change piece coords
    board[startRow][startCol]->setRow(endN);
    board[startRow][startCol]->setCol(endL);
    //update board position
    board[endRow][endCol]=board[startRow][startCol];
    board[startRow][startCol]=nullptr;
}

void Board::drawBoard(char c) {
    for (int i=0; i<board.size(); ++i) {
        for (int j=0; j<board[0].size(); ++j) {
            //if white is moving next
            if (c=='w') {
                if (board[board.size()-1-i][j]==nullptr) cout << "*";
                else cout << board[board.size()-1-i][j]->getPiece();
            } else { //if black is moving next
                if (board[i][board[0].size()-1-j]==nullptr) cout << "*";
                else cout << board[i][board[0].size()-1-i]->getPiece();
            }
        }
        cout << endl;
    }
}