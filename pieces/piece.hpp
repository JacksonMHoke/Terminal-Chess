#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include <stdexcept>
#include <vector>

using std::vector;
using std::logic_error;

class Board;
class MovementBehavior;

class Piece {
    protected:
        vector<MovementBehavior*> moveB;
        char letter;
        char number;
        char color;
        char piece;
    public:
        Piece(char l, char n, char c, char p) {
            piece=p;
            letter=l;
            number=n;
            color=c;
        }

        virtual ~Piece();

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
        vector<MovementBehavior*> getMovement() { return moveB; }
};

#endif //__PIECE_HPP__