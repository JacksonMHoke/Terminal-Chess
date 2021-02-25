#ifndef __ROOK_HPP__
#define __ROOK_HPP__

#include "piece.hpp"

class Rook : public Piece {
    public:
        Rook(char l, char n, char c, char p, MovementBehavior* move=nullptr, Board* b=nullptr) : Piece(l, n, c, p, move, b) {}
        //TODO move function
        virtual bool move(const char l, const char n) { return true; }
        virtual void set_behavior(Board* b) {
            //moveB.push_back(new HorizontalMovement(b));
            //moveB.push_back(new VerticalMovement(b));
        }
};

#endif //__ROOK_HPP__