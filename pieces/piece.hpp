#ifndef __PIECE_HPP__
#define __PIECE_HPP__

class Piece {
    private:
        //MovementBehavior* moveB;
        char letter;
        char number;
        char color;
    public:
        virtual bool move(const char l, const char n) = 0;
};

#endif //__PIECE_HPP__