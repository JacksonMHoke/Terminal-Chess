#ifndef __QUEEN_HPP__
#define __QUEEN_HPP__

#include "piece.hpp"

class Queen : public Piece {
    public:
        Queen(char l, char n, char c, char p, MovementBehavior* move=nullptr, Board* b=nullptr) : Piece(l, n, c, p, move, b) {}
        //TODO move function
        virtual bool move(const char l, const char n) { return true; }
        virtual void set_behavior(Board* b) {
            //moveB.push_back(new Diagonal(b));
            //moveB.push_back(new VerticalMovement(b));
            //moveB.push)back(new HorizontalMovement(b));
        }
};

#endif //__QUEEN_HPP__