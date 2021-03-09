#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include "../movement/MovementBehavior.hpp"
#include "../board.hpp"
#include <stdexcept>

using std::vector;
using std::logic_error;

class Piece {
    protected:
        vector<MovementBehavior> moveB;
        char letter;
        char number;
        char color;
        char piece;
    public:
        Piece(char l, char n, char c, char p, MovementBehavior move=nullptr, Board* b=nullptr) {
            piece=p;
            letter=l;
            number=n;
            color=c;
            if(b) set_behavior(b);
        }

        Piece(Piece* p) {
            piece=p->getPiece();
            color=p->getColor();
            number=p->getRow();
            letter=p->getCol();
            moveB=p->getMovement();
        }

        //adds the corresponding movement behaviors to the moveB vector
        virtual void set_behavior(Board* b)=0;

        //calls all movement behaviors in the moveB vector, if one works return true, otherwise return false
        virtual bool move(char l, char n) = 0;

        //getters and setters
        char getRow() { return number; }
        char getCol() { return letter; }
        void setRow(char n) { number=n; }
        void setCol(char l) { letter=l; }
        char getColor() { return color; }
        char getPiece() { return piece; } //returns char that will represent piece when displaying
        vector<MovementBehavior> getMovement() { return moveB; }
};

//import all the other piece classes here so the only include needed will be piece when using
//any of the piece classes
#include "pawn.hpp"
#include "rook.hpp"
#include "king.hpp"
#include "queen.hpp"
#include "knight.hpp"
#include "bishop.hpp"

#endif //__PIECE_HPP__