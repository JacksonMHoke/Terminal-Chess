#ifndef BOARDFACTORY_HPP
#define BOARDFACTORY_HPP
#include "Board.hpp"

class BoardFactory {
	public:
		BoardFactory() {}
		virtual Board* createBoard()=0;
};

#endif
