#ifndef BOARDFACTORY_HPP
#define BOARDFACTORY_HPP
#include "Board.h"

class BoardFactory : Game{
	private:
		pieces[][];
	public:
		BoardFactory();
		virtual Board createBoard()=0;
		void drawBoard(){
			for (int i=0;i<pieces.length();i++)
				for (int k=0;k<pieces.at(i).length(0);k++){
					if (pieces.at(i).at(k)==nullptr)
						cout << "* ";
					cout << pieces.at(i).at(k).getPiece() << " ";
				}
				cout << endl;
		}
		//TODO
		char getYLocation();
		void setYlocation();
		char getXLocation();
		void setYlocation();
		char getPiece();
		bool isOccupied();
};

#endif
