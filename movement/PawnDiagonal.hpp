#ifndef __PAWNDIAGONAL_HPP__
#define __PAWNDIAGONAL_HPP__

#include "MovementBehavior.hpp"

class PawnDiagonal : public MovementBehavior {
private:

public:
	virtual bool move(char x1, char y1, char x2, char y2) {
		if(Piece::getColor(x1, y1) == 'b') {
			if(board->getCell(x2, y2) == nullptr) { return false; }
			if((abs(x1 - x2) == 1) && ((y1 - y2) == 1)) {
				Piece::setCol(x2);
				Piece::setRow(y2);
				return true;
			}
			else { return false; }
		}
		else {
			if(board->getCell(x2, y2) == nullptr) { return false; }
                        if((abs(x1 - x2) == 1) && ((y1 - y2) == -1)) {
                                Piece::setCol(x2);
                                Piece::setRow(y2);
                                return true;
                        }
                        else { return false; }
		}
	}
}




#endif
