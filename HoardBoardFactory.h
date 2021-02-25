#ifndef HOARDBOARDFACTORY_HPP
#define HOARDBOARDFACTORY_HPP

class HoardBoardFactory : BoardFactory{
	private:
		pieces[][];
	public:
		HoardBoardFactory();
		virtual Board createBoard();
};

#endif
