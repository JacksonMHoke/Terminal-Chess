#ifndef __PIECE_HPP__
#define __PIECE_HPP__

#include "movement_behavior.hpp"
#include "board.hpp"

using std::vector;

class Piece {
    protected:
        vector<MovementBehavior*> moveB;
        char letter;
        char number;
        char color;
    public:
        virtual bool move(const char l, const char n) = 0;
        Piece(char l, char n, char c, MovementBehavior* move=nullptr, Board* b=nullptr) {
            letter=l;
            number=n;
            color=c;

            //set move behavior if constructor passed in info for board or behavior
            if(move) moveB.push_back(move);
            if(b) set_behavior(b);
        }
        virtual void set_behavior(Board* b)=0;
};

#endif //__PIECE_HPP__