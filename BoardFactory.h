#ifndef BOARDFACTORY_HPP
#define BOARDFACTORY_HPP
#include "Board.h"

class BoardFactory : Game{
	public:
		BoardFactory();
		virtual Board createBoard()=0;
};

#endif
