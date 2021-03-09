#ifndef __PAWNDIAGONAL_HPP__
#define __PAWNDIAGONAL_HPP__

#include "MovementBehavior.hpp"

class PawnDiagonal : public MovementBehavior {
private:

public:
	PawnDiagonal(Board* b) : MovementBehavior(b) {}
	virtual bool move(char x1, char y1, char x2, char y2) {
		//if there is same color piece at end coords
		if (board->getCell(x2,y2)!=nullptr && board->getCell(x1, y1)->getColor()==board->getCell(x2, y2)->getColor()) return false;

		if(board->getCell(x1, y1)->getColor() == 'b') {
			if(board->getCell(x2, y2) == nullptr) { return false; }
			if((abs(x1 - x2) == 1) && ((y1 - y2) == 1)) {
				if (isCheck(board->getCell(x1, y1)->getColor())) return false;
				board->move(x1, y1, x2, y2);
				return true;
			}
			else { return false; }
		}
		else {
			if(board->getCell(x2, y2) == nullptr) { return false; }
			if((abs(x1 - x2) == 1) && ((y1 - y2) == -1)) {
				if (isCheck(board->getCell(x1, y1)->getColor())) return false;
				board->move(x1, y1, x2, y2);
				return true;
			}
			else { return false; }
		}
	}
};




#endif
