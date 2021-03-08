#ifndef HOARDBOARDFACTORY_HPP
#define HOARDBOARDFACTORY_HPP
#include "Board.hpp"
#include "BoardFactory.hpp"

class HoardBoardFactory : BoardFactory{
	public:
		HoardBoardFactory();
		virtual Board createBoard(){
			Board* board = new Board();
			board->addPiece(new Pawn  ('a', '1', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('b', '1', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('c', '1', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('d', '1', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('e', '1', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('f', '1', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('g', '1', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('h', '1', 'w', 'P', nullptr, board));

			board->addPiece(new Pawn  ('a', '2', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('b', '2', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('c', '2', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('d', '2', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('e', '2', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('f', '2', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('g', '2', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('h', '2', 'w', 'P', nullptr, board));	

			board->addPiece(new Pawn  ('a', '3', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('b', '3', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('c', '3', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('d', '3', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('e', '3', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('f', '3', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('g', '3', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('h', '3', 'w', 'P', nullptr, board));

			board->addPiece(new Pawn  ('a', '4', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('b', '4', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('c', '4', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('d', '4', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('e', '4', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('f', '4', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('g', '4', 'w', 'P', nullptr, board));
			board->addPiece(new Pawn  ('h', '4', 'w', 'P', nullptr, board));

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
