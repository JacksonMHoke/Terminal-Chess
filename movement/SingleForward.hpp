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
					//move to destination, if check revert
					Piece* temp=nullptr;
					if (board->getCell(x2,y2)!=nullptr) temp=board->getCell(x2,y2);
					board->setCellNull(x2,y2); //to avoid deleting piece at that place
					board->move(x1, y1, x2, y2);
					if (isCheck(board->getCell(x1, y1)->getColor())) {
						board->move(x2,y2,x1,y1);
						board->addPiece(temp);
						return false;
					} else delete temp;
					return true;
				}
				else { return false; }
			}
			else {
                if(((x1 - x2) == 0) && ((y1 - y2) == -1) && board->getCell(x2,y2)==nullptr) {
					//move to destination, if check revert
					Piece* temp=nullptr;
					if (board->getCell(x2,y2)!=nullptr) temp=board->getCell(x2,y2);
					board->setCellNull(x2,y2); //to avoid deleting piece at that place
					board->move(x1, y1, x2, y2);
					if (isCheck(board->getCell(x1, y1)->getColor())) {
						board->move(x2,y2,x1,y1);
						board->addPiece(temp);
						return false;
					} else delete temp;
					return true;
                } else { return false; }
			}
		}
		else { return false; }
    }
};

#endif
