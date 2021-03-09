#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

#include "piece.hpp"
#include "../movement/LMovement.hpp"

class Knight : public Piece {
    public:
        Knight(char l, char n, char c, char p, Board& b) : Piece(l, n, c, p) {
            set_behavior(b);
        }
        
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

        //sets movement behavior for knight
        virtual void set_behavior(Board& b) {
            moveB.push_back(new LMovement(&b));
        }
};

#endif //__KNIGHT_HPP__