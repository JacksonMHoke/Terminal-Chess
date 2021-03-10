#ifndef __VICINITYMOVEMENT_HPP__
#define __VICINITYMOVEMENT_HPP__

#include "MovementBehavior.hpp"

class VicinityMovement : public MovementBehavior {
private:

public:
	VicinityMovement(Board* b) : MovementBehavior(b) {}

	virtual bool move(char l1, char n1, char l2, char n2) {
		//if movement is out of bounds
		if (abs(l1-l2)>1 || abs(n1-n2)>1) return false;

		if (l2>='a' && l2<='h' && n2>='1' && n2<='8') {
			//if destination has a piece with same color
			if (board->getCell(l2,n2)!=nullptr && board->getCell(l2,n2)->getColor()==board->getCell(l1,n1)->getColor()) return false;

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
		return false;
	}
};

#endif