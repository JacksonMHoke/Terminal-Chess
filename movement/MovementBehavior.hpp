#ifndef __MOVEMENTBEHAVIOR_HPP__
#define __MOVEMENTBEHAVIOR_HPP__


#include "../board.hpp"
#include "../pieces/piece.hpp"
#include <vector>
#include <utility>
#include <cctype>
#include <stdlib.h>

using std::vector;
using std::pair;

class MovementBehavior {
	protected:
		Board* board;

		//if king is in check return true, otherwise return false
		bool isCheck(char c);

		//checks all L's to see if king is in check
		bool knightCheck(char kR, char kC, char c);

		//checks all diagonals to see if king could be in check
		bool diagCheck(char kR, char kC, char c);

		//checks for horizontal or vertical checks
		bool straightCheck(char kR, char kC, char c);

		//function that returns a pointer to the king corresponding to color c
		Piece* findKing(char c);
	public:
		MovementBehavior(Board* b) { board=b; }
		virtual bool move(char, char, char, char) = 0;
};

#endif
