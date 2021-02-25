#ifndef __BISHOP_HPP__
#define __BISHOP_HPP__

#include "piece.hpp"

class Bishop : public Piece {
    public:
        //TODO constructor
        Bishop() {}
        //TODO move function
        virtual bool move(const char l, const char n) { return true; }
};

#endif //__BISHOP_HPP__