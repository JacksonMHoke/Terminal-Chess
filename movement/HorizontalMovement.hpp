#ifndef __HORIZONTALMOVEMENT_HPP__
#define __HORIZONTALMOVEMENT_HPP__

#include "MovementBehavior.hpp"

class HorizontalMovement : public MovementBehavior {
private:

public:
        virtual bool move(char x1, char y1, char x2, char y2) {
                // if in boundary
		if((x2 <= 8 && x2 >= 1) && (y2 <= 'h' && y2 >= 'a')) {
                        // leftwards movement
			if(((x1 - x2) > 0) && ((y1 - y2) == 0)){
                                // check if anything interferes
				for(int i = 0; i < (x1 - x2); ++i) {
                                        if(board->getCell(x1 - i, y1) != nullptr) { return false; }
                                }
                                Piece::setCol(x2);
                                Piece::setRow(y2);
                                return true;
                        }
                        // rightwards movement
			else if(((x1 - x2) < 0) && ((y1 - y2) == 0)){
                                // check if anything interferes
                                for(int i = 0; i < abs(x1 - x2); ++i) {
                                        if(board->getCell(x1 + i, y1) != nullptr) { return false; }
                                }
                                Piece::setCol(x2);
                                Piece::setRow(y2);
                                return true;
                        }
		}
		else { return false; }
	}
}




#endif
