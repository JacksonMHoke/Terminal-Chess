#ifndef CLASSICBOARDFACTORY_HPP
#define CLASSICBOARDFACTORY_HPP

#include <iostream>
#include "BoardFactory.h"
#include "Board.h"
class ClassicBoardFactory extends BoardFactory{
	private:
		pieces[][];
	public:
		ClassicBoardFactory();
		virtual Board createBoard(){
			Board* board = new Board();
			board->addPiece(new Rook  ('a', '1', 'w', 'R', nullptr, board));
			board->addPiece(new Knight('b', '1', 'w', 'N', nullptr, board));
			board->addPiece(new Bishop('c', '1', 'w', 'B', nullptr, board));
			board->addPiece(new Queen ('d', '1', 'w', 'Q', nullptr, board));
			board->addPiece(new King  ('e', '1', 'w', 'K', nullptr, board));
			board->addPiece(new Bishop('f', '1', 'w', 'B', nullptr, board));
			board->addPiece(new Knight('g', '1', 'w', 'N', nullptr, board));
			board->addPiece(new Rook  ('h', '1', 'w', 'R', nullptr, board));
			board->addPiece(new Pawn  ('a', '2', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('b', '2', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('c', '2', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('d', '2', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('e', '2', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('f', '2', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('g', '2', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('h', '2', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('a', '7', 'b', 'p', nullptr, board));
			board->addPiece(new Pawn  ('b', '7', 'b', 'p', nullptr, board));
			board->addPiece(new Pawn  ('c', '7', 'b', 'p', nullptr, board));
			board->addPiece(new Pawn  ('d', '7', 'b', 'p', nullptr, board));
			board->addPiece(new Pawn  ('e', '7', 'b', 'p', nullptr, board));
			board->addPiece(new Pawn  ('f', '7', 'b', 'p', nullptr, board));
			board->addPiece(new Pawn  ('g', '7', 'b', 'p', nullptr, board));
			board->addPiece(new Pawn  ('h', '7', 'b', 'p', nullptr, board));
			board->addPiece(new Rook  ('a', '8', 'b', 'r', nullptr, board));
			board->addPiece(new Knight('b', '8', 'b', 'n', nullptr, board));
			board->addPiece(new Bishop('c', '8', 'b', 'b', nullptr, board));
			board->addPiece(new Queen ('d', '8', 'b', 'q', nullptr, board));
			board->addPiece(new King  ('e', '8', 'b', 'k', nullptr, board));
			board->addPiece(new Bishop('f', '8', 'b', 'r', nullptr, board));
			board->addPiece(new Knight('g', '8', 'b', 'n', nullptr, board));
			board->addPiece(new Rook  ('h', '8', 'b', 'b', nullptr, board));
			return board;
		}
};

#endif
