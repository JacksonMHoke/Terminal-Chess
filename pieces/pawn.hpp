#ifndef __PAWN_HPP__
#define __PAWN_HPP__

#include "piece.hpp"
#include "../movement/PawnDiagonal.hpp"
#include "../movement/SingleForward.hpp"

class Pawn : public Piece {
    public:
        Pawn(char l, char n, char c, char p, Board* b) : Piece(l, n, c, p) {
            set_behavior(b);
        }

        //tries to move to (l,n) for all movement behaviors
        //returns true if the move is valid, false if invalid
        virtual bool move(char l, char n) {
            if (moveB.size()==0) throw logic_error("Tried to move without movement behavior");
            //tries all movement behavior to see if one works
            //returns true if one works, false if all fail
            for (int i=0; i<moveB.size(); ++i) {
                if (moveB[i]->move(letter, number, l, n)) return true;
            }

            //if pawn wants to move 2 up or down
            if (abs(n-number)==2 && l-letter==0) {
                if (color=='b' && number=='7') {
                    char tempL=letter;
                    char tempN=number;
                    if (moveB[1]->move(letter, number, letter, number-1) && moveB[1]->move(letter, number, letter, number-1)) {
                        return true;
                    } else {
                        color='w';
                        for (int i=1; i<=tempN-number; ++i) {
                            moveB[1]->move(letter, number, letter, number+1);
                        }
                        color='b';
                    }
                } else if (color=='w' && number=='2') {
                    char tempL=letter;
                    char tempN=number;
                    if (moveB[1]->move(letter, number, letter, number+1) && moveB[1]->move(letter, number, letter, number+1)) {
                        return true;
                    } else {
                        color='b';
                        for (int i=1; i<=number-tempN; ++i) {
                            moveB[1]->move(letter, number, letter, number-1);
                        }
                        color='w';
                    }
                }
            }

            return false;
        }

        //sets movement behavior for pawn
        virtual void set_behavior(Board* b) {
            moveB.push_back(new PawnDiagonal(b));
            moveB.push_back(new SingleForward(b));
        }
};

#endif //__PAWN_HPP__