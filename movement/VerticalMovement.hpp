#ifndef __VERTICALMOVEMENT_HPP__
#define __VERTICALMOVEMENT_HPP__

#include "MovementBehavior.hpp"

class VerticalMovement : public MovementBehavior {
private:

public:
	VerticalMovement(Board* b) : MovementBehavior(b) {}
	virtual bool move(char x1, char y1, char x2, char y2) {
		//if there is same color piece at end coords
		if (board->getCell(x2,y2)!=nullptr && board->getCell(x1, y1)->getColor()==board->getCell(x2, y2)->getColor()) return false;
		// if in boundary
		if((x2<='h' && x2>='a') && (y2 <= '8' && y2 >= '1')) {
			// downwards movement
			if(((x1 - x2) == 0) && ((y1 - y2) > 0)){
				// check if anything interferes
				for(int i = 0; i < (y1 - y2); ++i) {
					if(board->getCell(x1, y1 - i) != nullptr) { return false; }
				}
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
			// upwards movement
			else if (((x1 - x2) == 0) && ((y1 - y2) < 0)) {
				// check if anything interferes
				for(int i = 0; i < abs(y1 - y2); ++i) {
					if(board->getCell(x1, y1 + i) != nullptr) { return false; }
				}
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
		else { return false; }
	}
};

#endif
