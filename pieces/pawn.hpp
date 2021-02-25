#ifndef __PAWN_HPP__
#define __PAWN_HPP__

#include "piece.hpp"

class Pawn : public Piece {
    public:
        //TODO constructor
        Pawn() {}
        //TODO move function
        virtual bool move(const char l, const char n) { return true; }
};

#endif //__PAWN_HPP__