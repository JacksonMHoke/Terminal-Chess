#ifndef __LMOVEMENT_HPP__
#define __LMOVEMENT_HPP__

#include "MovementBehavior.hpp"

class LMovement : public MovementBehavior {
private:

public:
	LMovement(Board* b) : MovementBehavior(b) {}
    virtual bool move(char x1, char y1, char x2, char y2) {
		//if there is same color piece at end coords
		if (board->getCell(x2,y2)!=nullptr && board->getCell(x1, y1)->getColor()==board->getCell(x2, y2)->getColor()) return false;

		// Check if the movement is an L
		if(((abs(x1 - x2) == 2) && (abs(y1 - y2) == 1)) || (((abs(x1 - x2) == 1) && (abs(y1 - y2) == 2)))) {
			if((x2 <= 8 && x2 >= 1) && (y2 <= 'h' && y2 >= 'a')) {
				if (isCheck(board->getCell(x1, y1)->getColor())) return false;
				board->move(x1, y1, x2, y2);
				return true;
			}
			else { return false; }
		}
		else { return false; }
	}
};

#endif
