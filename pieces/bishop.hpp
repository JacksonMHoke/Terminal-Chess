#ifndef __BISHOP_HPP__
#define __BISHOP_HPP__

#include "piece.hpp"

class Bishop : public Piece {
    public:
        Bishop(char l, char n, char c, MovementBehavior* move=nullptr, Board* b=nullptr) : Piece(l, n, c, move, b) {}
        //TODO move function
        virtual bool move(const char l, const char n) { return true; }
        virtual void set_behavior(Board* b) {
            //moveB.push_back(new Diagonal(b));
        }
};

#endif //__BISHOP_HPP__