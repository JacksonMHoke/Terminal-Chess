#ifndef BOARDFACTORY_HPP
#define BOARDFACTORY_HPP
#include "Board.hpp"

class BoardFactory : Game{
	public:
		BoardFactory();
		virtual Board createBoard()=0;
};

#endif
