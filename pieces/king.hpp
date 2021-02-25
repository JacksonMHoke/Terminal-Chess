#ifndef __KING_HPP__
#define __KING_HPP__

#include "piece.hpp"

class King : public Piece {
    public:
        King(char l, char n, char c, MovementBehavior* move=nullptr, Board* b=nullptr) : Piece(l, n, c, move, b) {}
        //TODO move function
        virtual bool move(const char l, const char n) { return true; }
        virtual void set_behavior(Board* b) {
            //moveB.push_back(new VicinityMovement(b));
        }
};

#endif //__KING_HPP__