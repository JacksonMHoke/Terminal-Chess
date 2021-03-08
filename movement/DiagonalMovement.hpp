#ifndef __DIAGONALMOVEMENT_HPP__
#define __DIAGONALMOVEMENT_HPP__

#include "MovementBehavior.hpp"

class DiagonalMovement : public MovementBehavior {
private:

public:
	virtual bool move(char x1, char y1, char x2, char y2) {
		// if the coordinates given are a diagonal and are within the bounds
		if(((x1 - x2) == (y1 - y2)) && (x2 <= 8 && x2 >= 1) && (y2 <= 'h' && y2 >= 'a')) {
			// check if there is anything in the way of the diagonal move
			for(int i = 1; i <= (x1 - x2); ++i) {
				if(board->getCell(x1 + i, y1 + i) != nullptr) { return false; }
			}
			// checked if anything is in the way, now move
			Piece::setCol(x2);
			Piece::setRow(y2);
			return true;
		}
	}
}




#endif
