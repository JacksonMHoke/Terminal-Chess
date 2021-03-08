#ifndef __MOVEMENTBEHAVIOR_HPP__
#define __MOVEMENTBEHAVIOR_HPP__


#include "../board.hpp"
#include "../pieces/piece.hpp"
#include <vector>
#include <pair>
#include <cctype>
#include <stdlib.h>

using std::vector;
using std::pair;

class MovementBehavior {
	protected:
		Board* board;

		//if king is in check return true, otherwise return false
		bool isCheck(char c) {
			//finds the king that we are validating
			Piece* k=findKing(c);
			char kR=k->getRow();
			char kC=k->getCol();
			
			return knightCheck(kR, kC, c) || diagCheck(kR, kC, c) || straightCheck(kR, kC, c);
		}

		//checks all L's to see if king is in check
		bool knightCheck(char kR, char kC, char c) {
			//will turn capital to lowercase
			int offset=0;
			//if pieces to check are capital increase offset to 32 to turn to lowercase
			if (c=='b') offset+=32;

			//vector of all possible combinations where knight can be in relation to king to be in check
			vector<pair<char, char>> knightPos{ pair<char, char>{kR+2, kC+1},
												pair<char, char>{kR+2, kC-1},
												pair<char, char>{kR-2, kC+1},
												pair<char, char>{kR-2, kC-1},
												pair<char, char>{kR+1, kC+2},
												pair<char, char>{kR-1, kC+2},
												pair<char, char>{kR+1, kC-2},
												pair<char, char>{kR-1, kC-2} };
			//looking for knights at positions where king could be in check
			for (int i=0; i<knightPos.size(); ++i) {
				if (board->getCell(knightPos[i].first, knightPos[i].second) && board->getCell(knightPos[i].first, knightPos[i].second)->getPiece()+offset == 'n') {
					return true;
				}
			}
		}

		//checks all diagonals to see if king could be in check
		bool diagCheck(char kR, char kC, char c) {
			//will turn capital to lowercase
			int offset=0;
			//if pieces to check are capital increase offset to 32 to turn to lowercase
			if (c=='b') offset+=32;

			//checking for pawns that could check
			int pawnOffset=1;
			if (c=='b') pawnOffset=-1;
			if (board->getCell(kR+pawnOffset, kC+1) && board->getCell(kR+pawnOffset, kC+1)->getPiece()+offset=='p') return true;
			if (board->getCell(kR+pawnOffset, kC-1) && board->getCell(kR+pawnOffset, kC-1)->getPiece()+offset=='p') return true;

			//checking for bishop and queen diagonals
			//if not opposing color bishop/queen found on one diagonal, there cannot exist a check past that point
			for (int i=1; i+kR<='8' && i+kC<='h'; ++i) {
				if (board->getCell(kR+i, kC+i)) {
					if (board->getCell(kR+i, kC+i)->getPiece()+offset!='q' && board->getCell(kR+i, kC+i)->getPiece()+offset!='b') break;
					return true;
				}
			}

			for (int i=1; kR-i>='1' && i+kC<='h'; ++i) {
				if (board->getCell(kR-i, kC+i)) {
					if (board->getCell(kR-i, kC+i)->getPiece()+offset!='q' && board->getCell(kR-i, kC+i)->getPiece()+offset!='b') break;
					return true;
				}
			}

			for (int i=1; kR-i>='1' && kC-i>='a'; ++i) {
				if (board->getCell(kR-i, kC-i)) {
					if (board->getCell(kR-i, kC-i)->getPiece()+offset!='q' && board->getCell(kR-i, kC-i)->getPiece()+offset!='b') break;
					return true;
				}
			}

			for (int i=1; kR+i<='8' && kC-i>='a'; ++i) {
				if (board->getCell(kR+i, kC-i)) {
					if (board->getCell(kR+i, kC-i)->getPiece()+offset!='q' && board->getCell(kR+i, kC-i)->getPiece()+offset!='b') break;
					return true;
				}
			}

			return false;
		}

		//checks for horizontal or vertical checks
		bool straightCheck(char kR, char kC, char c) {
			//will turn capital to lowercase
			int offset=0;
			//if pieces to check are capital increase offset to 32 to turn to lowercase
			if (c=='b') offset+=32;

			//checks area above white king or below black king
			for (int i=kR+1; i<board->getHeight()+'1'; ++i) {
				if (board->getCell(i, kC)) {
					if (board->getCell(i, kC)->getPiece()+offset != 'q' && board->getCell(i, kC) && board->getCell(i, kC)->getPiece()+offset != 'r') break;
					return true;
				}
			}
			//checks area below white king or above black king
			for (int i=kR-1; i>='1'; --i) {
				if (board->getCell(i, kC)) {
					if (board->getCell(i, kC)->getPiece()+offset != 'q' && board->getCell(i, kC) && board->getCell(i, kC)->getPiece()+offset != 'r') break;
					return true;
				}
			}
			//checks area to the right of the white king or to the left of the black king
			for (int i=kC+1; i<board->getWidth()+'a'; ++i) {
				if (board->getCell(kR, i)) {
					if (board->getCell(kR, i)->getPiece()+offset != 'q' && board->getCell(kR, i) && board->getCell(kR, i)->getPiece()+offset != 'r') break;
					return true;
				}
			}
			//checks area to the right of the black king or to the left of the white king
			for (int i=kC-1; i>='a'; --i) {
				if (board->getCell(kR, i)) {
					if (board->getCell(kR, i)->getPiece()+offset != 'q' && board->getCell(kR, i) && board->getCell(kR, i)->getPiece()+offset != 'r') break;
					return true;
				}
			}
			return false;
		}

		//function that returns a pointer to the king corresponding to color c
		Piece* findKing(char c) {
			//find where king is
			for (int i=0; i<board->getHeight(); ++i) {
				for (int j=0; j<board->getWidth(); ++j) {
					//if piece is the correct king
					if (board->getCell(i+'1', j+'a')->getColor()==c && (board->getCell(i+'1', j+'a')->getPiece()=='k' || board->getCell(i+'1', j+'a')->getPiece()=='K')) {
						return board->getCell(i+'1', j+'a');
					}
				}
			}
			return nullptr;
		}
	public:
		MovementBehavior(Board* b) { board=b; }
		virtual bool move(char, char, char, char) = 0;
};

#endif
