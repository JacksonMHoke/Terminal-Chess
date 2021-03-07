#ifndef __LMOVEMENT_HPP__
#define __LMOVEMENT_HPP__

#include "MovementBehavior.hpp"

class LMovement : public MovementBehavior {
private:

public:
        virtual bool move(char x1, char y1, char x2, char y2) {
		// Check if the movement is an L
		if(((abs(x1 - x2) == 2) && (abs(y1 - y2) == 1))
	}
}




#endif
