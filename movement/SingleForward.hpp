#ifndef __SINGLEFORWARD_HPP__
#define __SINGLEFORWARD_HPP__

#include "MovementBehavior.hpp"

class SingleForward : public MovementBehavior {
private:

public:
	SingleForward(Board* b) : MovementBehavior(b) {}
	virtual bool move(char l1, char n1, char l2, char n2) {
        if(l2 <= 'h' && l2 >= 'a' && n2 <= '8' && n2 >= '1') {
			if(board->getCell(l1,n1)->getColor() == 'b') {
				if(((l1 - l2) == 0) && ((n1 - n2) == 1) && board->getCell(l2,n2)==nullptr) {
					//move to destination, if check revert
					Piece* temp=nullptr;
					if (board->getCell(l2,n2)!=nullptr) temp=board->getCell(l2,n2);
					board->setCellNull(l2,n2); //to avoid deleting piece at that place
					board->move(l1, n1, l2, n2);
					if (isCheck(board->getCell(l1, n1)->getColor())) {
						board->move(l2,n2,l1,n1);
						board->addPiece(temp);
						return false;
					} else delete temp;
					return true;
				}
				else { return false; }
			}
			else {
                if(((l1 - l2) == 0) && ((n1 - n2) == -1) && board->getCell(l2,n2)==nullptr) {
					//move to destination, if check revert
					Piece* temp=nullptr;
					if (board->getCell(l2,n2)!=nullptr) temp=board->getCell(l2,n2);
					board->setCellNull(l2,n2); //to avoid deleting piece at that place
					board->move(l1, n1, l2, n2);

					if (isCheck(board->getCell(l2,n2)->getColor())) {
						board->move(l2,n2,l1,n1);
						board->addPiece(temp);
						return false;
					} else {
						delete temp;
					}
					return true;
                } else { return false; }
			}
		}
		else { return false; }
    }
};

#endif
