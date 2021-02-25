#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

#include "piece.hpp"

class Knight : public Piece {
    public:
        //TODO constructor
        Knight() {}
        //TODO move function
        virtual bool move(const char l, const char n) { return true; }
};

#endif //__KNIGHT_HPP__