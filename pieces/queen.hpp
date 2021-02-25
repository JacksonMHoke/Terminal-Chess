#ifndef __QUEEN_HPP__
#define __QUEEN_HPP__

#include "piece.hpp"

class Queen : public Piece {
    public:
        //TODO constructor
        Queen() {}
        //TODO move function
        virtual bool move(const char l, const char n) { return true; }
};

#endif //__QUEEN_HPP__