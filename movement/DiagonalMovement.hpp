#ifndef __DIAGONALMOVEMENT_HPP__
#define __DIAGONALMOVEMENT_HPP__

#include "MovementBehavior.hpp"

class DiagonalMovement : public MovementBehavior {
private:

public:
	DiagonalMovement(Board* b) : MovementBehavior(b) {}
	virtual bool move(char x1, char y1, char x2, char y2) {
		//if there is same color piece at end coords
		if (board->getCell(x2,y2)!=nullptr && board->getCell(x1, y1)->getColor()==board->getCell(x2, y2)->getColor()) return false;

		//accounts for direction piece is moving in
		bool l=false;
		bool r=false;
		bool u=false;
		bool d=false;
		if (x1>x2) l=true;
		if (x1<x2) r=true;
		if (y1<y2) u=true;
		if (y1>y2) d=true;

		// if the coordinates given are a diagonal and are within the bounds
		if(((x1 - x2) == (y1 - y2)) && (x2 <= 'h' && x2 >= 'a') && (y2 <= '8' && y2 >= '1')) {
			// check if there is anything in the way of the diagonal move
			for(int i = 1; i <= abs(x1 - x2); ++i) {
				if(u && r && board->getCell(x1 + i, y1 + i) != nullptr) { return false; }
				if(u && l && board->getCell(x1 - i, y1 + i) != nullptr) { return false; }
				if(d && l && board->getCell(x1 - i, y1 - i) != nullptr) { return false; }
				if(d && r && board->getCell(x1 + i, y1 - i) != nullptr) { return false; }
			}

			// checked if anything is in the way, now move
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
		return false;
	}
};




#endif
