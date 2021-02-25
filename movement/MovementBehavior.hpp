#ifndef __MOVEMENT_HPP__
#define __MOVEMENT_HPP__

class Movement : public Piece {
private:
	bool wasValid;
public:
	virtual bool move(char, char, char, char) = 0;
}




#endif
