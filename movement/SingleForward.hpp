#ifndef __SINGLEFORWARD_HPP__
#define __SINGLEFORWARD_HPP__

#include "MovementBehavior.hpp"

class SingleForward : public MovementBehavior {
private:

public:
	SingleForward(Board* b) : MovementBehavior(b) {}
	virtual bool move(char x1, char y1, char x2, char y2) {
        if(x2 <= 'h' && x2 >= 'a' && y2 <= '8' && y2 >= '1') {
			if(board->getCell(x1,y1)->getColor() == 'b') {
				if(((x1 - x2) == 0) && ((y1 - y2) == 1) && board->getCell(x2,y2)==nullptr) {
					if (isCheck(board->getCell(x1, y1)->getColor())) return false;
					board->move(x1, y1, x2, y2);
					return true;
				}
				else { return false; }
			}
			else {
                if(((x1 - x2) == 0) && ((y1 - y2) == -1) && board->getCell(x2,y2)==nullptr) {
					if (isCheck(board->getCell(x1, y1)->getColor())) return false;
					board->move(x1, y1, x2, y2);
					return true;
                } else { return false; }
			}
		}
		else { return false; }
    }
}

#endif
