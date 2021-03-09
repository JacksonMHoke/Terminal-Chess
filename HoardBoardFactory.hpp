#ifndef HOARDBOARDFACTORY_HPP
#define HOARDBOARDFACTORY_HPP
#include "Board.hpp"
#include "pieces/pawn.hpp"
#include "pieces/bishop.hpp"
#include "pieces/king.hpp"
#include "pieces/knight.hpp"
#include "pieces/queen.hpp"
#include "pieces/rook.hpp"
#include "BoardFactory.hpp"

class HoardBoardFactory : public BoardFactory {
	public:
		HoardBoardFactory() : BoardFactory() {}
		virtual Board* createBoard(){
			Board* board = new Board();
			board->addPiece(new Pawn  ('a', '1', 'w', 'P', board));
			board->addPiece(new Pawn  ('b', '1', 'w', 'P', board));
			board->addPiece(new Pawn  ('c', '1', 'w', 'P', board));
			board->addPiece(new Pawn  ('d', '1', 'w', 'P', board));
			board->addPiece(new Pawn  ('e', '1', 'w', 'P', board));
			board->addPiece(new Pawn  ('f', '1', 'w', 'P', board));
			board->addPiece(new Pawn  ('g', '1', 'w', 'P', board));
			board->addPiece(new Pawn  ('h', '1', 'w', 'P', board));

			board->addPiece(new Pawn  ('a', '2', 'w', 'P', board));
			board->addPiece(new Pawn  ('b', '2', 'w', 'P', board));
			board->addPiece(new Pawn  ('c', '2', 'w', 'P', board));
			board->addPiece(new Pawn  ('d', '2', 'w', 'P', board));
			board->addPiece(new Pawn  ('e', '2', 'w', 'P', board));
			board->addPiece(new Pawn  ('f', '2', 'w', 'P', board));
			board->addPiece(new Pawn  ('g', '2', 'w', 'P', board));
			board->addPiece(new Pawn  ('h', '2', 'w', 'P', board));	

			board->addPiece(new Pawn  ('a', '3', 'w', 'P', board));
			board->addPiece(new Pawn  ('b', '3', 'w', 'P', board));
			board->addPiece(new Pawn  ('c', '3', 'w', 'P', board));
			board->addPiece(new Pawn  ('d', '3', 'w', 'P', board));
			board->addPiece(new Pawn  ('e', '3', 'w', 'P', board));
			board->addPiece(new Pawn  ('f', '3', 'w', 'P', board));
			board->addPiece(new Pawn  ('g', '3', 'w', 'P', board));
			board->addPiece(new Pawn  ('h', '3', 'w', 'P', board));

			board->addPiece(new Pawn  ('a', '4', 'w', 'P', board));
			board->addPiece(new Pawn  ('b', '4', 'w', 'P', board));
			board->addPiece(new Pawn  ('c', '4', 'w', 'P', board));
			board->addPiece(new Pawn  ('d', '4', 'w', 'P', board));
			board->addPiece(new Pawn  ('e', '4', 'w', 'P', board));
			board->addPiece(new Pawn  ('f', '4', 'w', 'P', board));
			board->addPiece(new Pawn  ('g', '4', 'w', 'P', board));
			board->addPiece(new Pawn  ('h', '4', 'w', 'P', board));

			board->addPiece(new Pawn  ('a', '7', 'b', 'p', board));
			board->addPiece(new Pawn  ('b', '7', 'b', 'p', board));
			board->addPiece(new Pawn  ('c', '7', 'b', 'p', board));
			board->addPiece(new Pawn  ('d', '7', 'b', 'p', board));
			board->addPiece(new Pawn  ('e', '7', 'b', 'p', board));
			board->addPiece(new Pawn  ('f', '7', 'b', 'p', board));
			board->addPiece(new Pawn  ('g', '7', 'b', 'p', board));
			board->addPiece(new Pawn  ('h', '7', 'b', 'p', board));

			board->addPiece(new Rook  ('a', '8', 'b', 'r', board));
			board->addPiece(new Knight('b', '8', 'b', 'n', board));
			board->addPiece(new Bishop('c', '8', 'b', 'b', board));
			board->addPiece(new Queen ('d', '8', 'b', 'q', board));
			board->addPiece(new King  ('e', '8', 'b', 'k', board));
			board->addPiece(new Bishop('f', '8', 'b', 'b', board));
			board->addPiece(new Knight('g', '8', 'b', 'n', board));
			board->addPiece(new Rook  ('h', '8', 'b', 'r', board));
			return board;
		}
};

#endif
