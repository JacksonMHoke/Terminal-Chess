#ifndef __QUEEN_HPP__
#define __QUEEN_HPP__

#include "piece.hpp"
#include "../movement/DiagonalMovement.hpp"
#include "../movement/VerticalMovement.hpp"
#include "../movement/HorizontalMovement.hpp"

class Queen : public Piece {
    public:
        Queen(char l, char n, char c, char p, Board& b) : Piece(l, n, c, p) {}
        
        //tries to move to (l,n) for all movement behaviors
        //returns true if the move is valid, false if invalid
        virtual bool move(char l, char n) {
            if (moveB.size()==0) throw logic_error("Tried to move without movement behavior");
            //tries all movement behavior to see if one works
            //returns true if one works, false if all fail
            for (int i=0; i<moveB.size(); ++i) {
                if (moveB[i]->move(letter, number, l, n)) return true;
            }
            return false;
        }

        //sets movement behavior for queen
        virtual void set_behavior(Board& b) {
            moveB.push_back(new DiagonalMovement(&b));
            moveB.push_back(new VerticalMovement(&b));
            moveB.push_back(new HorizontalMovement(&b));
        }
};

#endif //__QUEEN_HPP__