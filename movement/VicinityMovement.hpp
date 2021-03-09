#ifndef __VICINITYMOVEMENT_HPP__
#define __VICINITYMOVEMENT_HPP__

#include "MovementBehavior.hpp"

class VicinityMovement : public MovementBehavior {
private:

public:
	VicinityMovement(Board* b) : MovementBehavior(b) {}

	virtual bool move(char x1, char y1, char x2, char y2) {
		//if movement is out of bounds
		if (abs(x1-x2)>1 || abs(y1-y2)>1) return false;

		if (x2>='a' && x2<='h' && y2>='1' && y2<='8') {
			//if destination has a piece with same color
			if (board->getCell(x2,y2)!=nullptr && board->getCell(x2,y2)->getColor()==board->getCell(x1,y1)->getColor()) return false;

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
	}
}

#endif
