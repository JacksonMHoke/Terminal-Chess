#ifndef __MOVEMENTBEHAVIOR_HPP__
#define __MOVEMENTBEHAVIOR_HPP__

#include "board.hpp"
#include "Piece.hpp"
#include <stdlib.h>

class MovementBehavior : public Piece {
public:
	Board *board;
	MovementBehavior(Board* b) { board = b; }
	virtual bool move(char, char, char, char) = 0;
}




#endif
