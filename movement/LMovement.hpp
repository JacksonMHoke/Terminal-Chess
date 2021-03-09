#ifndef __LMOVEMENT_HPP__
#define __LMOVEMENT_HPP__

#include "MovementBehavior.hpp"

class LMovement : public MovementBehavior {
private:

public:
	LMovement(Board* b) : MovementBehavior(b) {}
    virtual bool move(char l1, char n1, char l2, char n2) {
		//if there is same color piece at end coords
		if (board->getCell(l2,n2)!=nullptr && board->getCell(l1, n1)->getColor()==board->getCell(l2, n2)->getColor()) return false;

		// Check if the movement is an L
		if(((abs(l1 - l2) == 2) && (abs(n1 - n2) == 1)) || (((abs(l1 - l2) == 1) && (abs(n1 - n2) == 2)))) {
			if((l2 <= 'h' && l2 >= 'a') && (n2 <= '8' && n2 >= '1')) {
				//move to destination, if check revert
				Piece* temp=nullptr;
				if (board->getCell(l2,n2)!=nullptr) temp=board->getCell(l2,n2);
				board->setCellNull(l2,n2); //to avoid deleting piece at that place
				board->move(l1, n1, l2, n2);
				if (isCheck(board->getCell(l2, n2)->getColor())) {
					board->move(l2,n2,l1,n1);
					board->addPiece(temp);
					return false;
				} else delete temp;
				return true;
			}
			else { return false; }
		}
		else { return false; }
	}
};

#endif
