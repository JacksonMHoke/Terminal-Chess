#ifndef __SINGLEFORWARD_HPP__
#define __SINGLEFORWARD_HPP__

#include "MovementBehavior.hpp"

class SingleForward : public MovementBehavior {
private:

public:
	virtual bool move(char x1, char y1, char x2, char y2) {
                if(((x1 - x2) == (y1 - y2)) && (x2 <= 8 && x2 >= 1) && (y2 <= 'h' && y2 >= 'a')) {
			if(Piece::getColor() == 'b') {
				if(((x1 - x2) == 0) && ((y1 - y2) == 1)) {
					Piece::setCol(x2)
					Piece::setRow(y2);
					return true;
				}
				else { return false; }
			}
			else {
                                if(((x1 - x2) == 0) && ((y1 - y2) == -1)) {
					Piece::setCol(x2);
					Piece::setRow(y2);
					return true;			
                                }
				else { return false; }
			}
		}
		else { return false; }
        }
}




#endif
