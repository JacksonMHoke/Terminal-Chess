#ifndef __ROOK_HPP__
#define __ROOK_HPP__

#include "piece.hpp"

class Rook : public Piece {
    public:
        //TODO constructor
        Rook() {}
        //TODO move function
        virtual bool move(const char l, const char n) { return true; }
};

#endif //__ROOK_HPP__