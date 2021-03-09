#ifndef __PAWNDIAGONAL_HPP__
#define __PAWNDIAGONAL_HPP__

#include "MovementBehavior.hpp"

class PawnDiagonal : public MovementBehavior {
private:

public:
	PawnDiagonal(Board* b) : MovementBehavior(b) {}
	virtual bool move(char l1, char n1, char l2, char n2) {
		board->getCell(l1,n1);

		//if there is same color piece at end coords
		if (board->getCell(l2,n2)!=nullptr && board->getCell(l1, n1)->getColor()==board->getCell(l2, n2)->getColor()) return false;

		if(board->getCell(l1, n1)->getColor() == 'b') {
			if(board->getCell(l2, n2) == nullptr) { return false; }
			if(abs(l1 - l2) == 1 && n1 - n2 == 1) {
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
		else {
			cout << "pawn diag w" << endl;
			if(board->getCell(l2, n2) == nullptr) { return false; }
			if((abs(l1 - l2) == 1) && ((n1 - n2) == -1)) {
				cout << "is valid" << endl;
				//move to destination, if check revert
				Piece* temp=nullptr;
				if (board->getCell(l2,n2)!=nullptr) temp=board->getCell(l2,n2);
				board->setCellNull(l2,n2); //to avoid deleting piece at that place
				board->move(l1, n1, l2, n2);
				if (isCheck(board->getCell(l2, n2)->getColor())) {
					cout << "is check" << endl;
					board->move(l2,n2,l1,n1);
					board->addPiece(temp);
					return false;
				} else {
					cout << "not in check" << endl;
					delete temp;
				}
				return true;
			}
			else { return false; }
		}
	}
};




#endif
