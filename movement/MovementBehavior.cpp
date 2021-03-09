#include "MovementBehavior.hpp"

bool MovementBehavior::isCheck(char c) {
    //finds the king that we are validating
    Piece* k=findKing(c);
    if (!k) return false;
    char kR=k->getRow();
    char kC=k->getCol();
    
    return knightCheck(kR, kC, c) || diagCheck(kR, kC, c) || straightCheck(kR, kC, c);
}

bool MovementBehavior::knightCheck(char kR, char kC, char c) {
    //will turn capital to lowercase
    int offset=0;
    //if pieces to check are capital increase offset to 32 to turn to lowercase
    if (c=='b') offset+=32;

    //vector of all possible combinations where knight can be in relation to king to be in check
    vector<pair<char, char>> knightPos{ pair<char, char>{kR+2, kC+1},
                                        pair<char, char>{kR+2, kC-1},
                                        pair<char, char>{kR-2, kC+1},
                                        pair<char, char>{kR-2, kC-1},
                                        pair<char, char>{kR+1, kC+2},
                                        pair<char, char>{kR-1, kC+2},
                                        pair<char, char>{kR+1, kC-2},
                                        pair<char, char>{kR-1, kC-2} };
    //looking for knights at positions where king could be in check
    for (int i=0; i<knightPos.size(); ++i) {
        if (board->getCell(knightPos[i].second, knightPos[i].first) && board->getCell(knightPos[i].second, knightPos[i].first)->getPiece()+offset == 'n') {
            return true;
        }
    }
    return false;
}

bool MovementBehavior::diagCheck(char kR, char kC, char c) {
    //will turn capital to lowercase
    int offset=0;
    //if pieces to check are capital increase offset to 32 to turn to lowercase
    if (c=='b') offset+=32;

    //checking for pawns that could check
    int pawnOffset=1;
    if (c=='b') pawnOffset=-1;
    if (board->getCell(kC+1, kR+pawnOffset) && board->getCell(kC+1, kR+pawnOffset)->getPiece()+offset=='p') return true;
    if (board->getCell(kC-1, kR+pawnOffset) && board->getCell(kC-1, kR+pawnOffset)->getPiece()+offset=='p') return true;

    //checking for bishop and queen diagonals
    //if not opposing color bishop/queen found on one diagonal, there cannot exist a check past that point
    for (int i=1; i+kR<='8' && i+kC<='h'; ++i) {
        if (board->getCell(kC+i, kR+i)) {
            if (board->getCell(kC+i, kR+i)->getPiece()+offset!='q' && board->getCell(kC+i, kR+i)->getPiece()+offset!='b') break;
            return true;
        }
    }

    for (int i=1; kR-i>='1' && i+kC<='h'; ++i) {
        if (board->getCell(kC+i, kR-i)) {
            if (board->getCell(kC+i, kR-i)->getPiece()+offset!='q' && board->getCell(kC+i, kR-i)->getPiece()+offset!='b') break;
            return true;
        }
    }

    for (int i=1; kR-i>='1' && kC-i>='a'; ++i) {
        if (board->getCell(kC-i, kR-i)) {
            if (board->getCell(kC-i, kR-i)->getPiece()+offset!='q' && board->getCell(kC-i, kR-i)->getPiece()+offset!='b') break;
            return true;
        }
    }

    for (int i=1; kR+i<='8' && kC-i>='a'; ++i) {
        if (board->getCell(kC-i, kR+i)) {
            if (board->getCell(kC-i, kR+i)->getPiece()+offset!='q' && board->getCell(kC-i, kR+i)->getPiece()+offset!='b') break;
            return true;
        }
    }

    return false;
}

bool MovementBehavior::straightCheck(char kR, char kC, char c) {
    //will turn capital to lowercase
    int offset=0;
    //if pieces to check are capital increase offset to 32 to turn to lowercase
    if (c=='b') offset+=32;

    //checks area above white king or below black king
    for (int i=kR+1; i<board->getHeight()+'1'; ++i) {
        if (board->getCell(kC, i)) {
            if (board->getCell(kC, i)->getPiece()+offset != 'q' && board->getCell(kC, i)->getPiece()+offset != 'r') break;
            return true;
        }
    }
    //checks area below white king or above black king
    for (int i=kR-1; i>='1'; --i) {
        if (board->getCell(kC, i)) {
            if (board->getCell(kC, i)->getPiece()+offset != 'q' && board->getCell(kC, i)->getPiece()+offset != 'r') break;
            return true;
        }
    }
    //checks area to the right of the white king or to the left of the black king
    for (int i=kC+1; i<board->getWidth()+'a'; ++i) {
        if (board->getCell(i, kR)) {
            if (board->getCell(i, kR)->getPiece()+offset != 'q' && board->getCell(i, kR)->getPiece()+offset != 'r') break;
            return true;
        }
    }
    //checks area to the right of the black king or to the left of the white king
    for (int i=kC-1; i>='a'; --i) {
        if (board->getCell(i, kR)) {
            if (board->getCell(i, kR)->getPiece()+offset != 'q' && board->getCell(i, kR)->getPiece()+offset != 'r') break;
            return true;
        }
    }
    return false;
}

Piece* MovementBehavior::findKing(char c) {
    //find where king is
    for (int i=0; i<board->getHeight(); ++i) {
        for (int j=0; j<board->getWidth(); ++j) {
            //if piece is the correct king
            if (board->getCell(i+'a', j+'1')!=nullptr && board->getCell(i+'a', j+'1')->getColor()==c && (board->getCell(i+'a', j+'1')->getPiece()=='k' || board->getCell(i+'a', j+'1')->getPiece()=='K')) {
                return board->getCell(i+'a', j+'1');
            }
        }
    }
    return nullptr;
}