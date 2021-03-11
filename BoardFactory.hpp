#ifndef BOARDFACTORY_HPP
#define BOARDFACTORY_HPP
#include "board.hpp"

class BoardFactory {
	public:
		BoardFactory() {}
		virtual Board* createBoard()=0;
};

#endif
