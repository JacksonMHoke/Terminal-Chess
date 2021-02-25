#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

#include "piece.hpp"

class Knight : public Piece {
    public:
        Knight(char l, char n, char c, char p, MovementBehavior* move=nullptr, Board* b=nullptr) : Piece(l, n, c, p, move, b) {}
        //TODO move function
        virtual bool move(const char l, const char n) { return true; }
        virtual void set_behavior(Board* b) {
            //moveB.push_back(new LMovement(b));
        }
};

#endif //__KNIGHT_HPP__