#ifndef __DIAGONALMOVEMENT_HPP__
#define __DIAGONALMOVEMENT_HPP__

#include "MovementBehavior.hpp"

class DiagonalMovement : public MovementBehavior {
private:

public:
	DiagonalMovement(Board* b) : MovementBehavior(b) {}
	virtual bool move(char l1, char n1, char l2, char n2) {
		//if there is same color piece at end coords
		if (board->getCell(l2,n2)!=nullptr && board->getCell(l1, n1)->getColor()==board->getCell(l2, n2)->getColor()) return false;

		cout << "after color checker" << endl;

		//accounts for direction piece is moving in
		bool l=false;
		bool r=false;
		bool u=false;
		bool d=false;
		if (l1>l2) l=true;
		if (l1<l2) r=true;
		if (n1<n2) u=true;
		if (n1>n2) d=true;

		// if the coordinates given are a diagonal and are within the bounds
		if((abs(l1 - l2) == abs(n1 - n2)) && (l2 <= 'h' && l2 >= 'a') && (n2 <= '8' && n2 >= '1')) {
			// check if there is anything in the way of the diagonal move
			for(int i = 1; i <= abs(l1 - l2)-1; ++i) {
				if(u && r && board->getCell(l1 + i, n1 + i) != nullptr) { return false; }
				if(u && l && board->getCell(l1 - i, n1 + i) != nullptr) { return false; }
				if(d && l && board->getCell(l1 - i, n1 - i) != nullptr) { return false; }
				if(d && r && board->getCell(l1 + i, n1 - i) != nullptr) { return false; }
			}

			// checked if anything is in the way, now move
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
