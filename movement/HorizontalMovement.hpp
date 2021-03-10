#ifndef __HORIZONTALMOVEMENT_HPP__
#define __HORIZONTALMOVEMENT_HPP__

#include "MovementBehavior.hpp"

class HorizontalMovement : public MovementBehavior {
private:

public:
        HorizontalMovement(Board* b) : MovementBehavior(b) {}
        virtual bool move(char l1, char n1, char l2, char n2) {
                //if there is same color piece at end coords
		if (board->getCell(l2,n2)!=nullptr && board->getCell(l1, n1)->getColor()==board->getCell(l2, n2)->getColor()) return false;
                // if in boundary
		if((l2 <= 'h' && l2 >= 'a') && (n2 <= '8' && n2 >= '1')) {
                        // leftwards movement
			if(((l1 - l2) > 0) && ((n1 - n2) == 0)){
                                // check if anything interferes
				for(int i = 1; i < abs(l1 - l2)-1; ++i) {
                                        if(board->getCell(l1 - i, n1) != nullptr) { return false; }
                                }
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
                        // rightwards movement
			else if(((l1 - l2) < 0) && ((n1 - n2) == 0)){
                                // check if anything interferes
                                for(int i = 1; i < abs(l1 - l2)-1; ++i) {
                                        if(board->getCell(l1 + i, n1) != nullptr) { return false; }
                                }
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
                }
                return false;
	}
};

#endif