#ifndef __PAWN_HPP__
#define __PAWN_HPP__

#include "piece.hpp"

class Pawn : public Piece {
    public:
        Pawn(char l, char n, char c, MovementBehavior* move=nullptr, Board* b=nullptr) : Piece(l, n, c, move, b) {}
        //TODO move function
        virtual bool move(const char l, const char n) { return true; }
        virtual void set_behavior(Board* b) {
            //moveB.push_back(new PawnDiagonal(b));
            //moveB.push_back(new SingleForward(b));
        }
};

#endif //__PAWN_HPP__