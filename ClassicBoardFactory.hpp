#ifndef CLASSICBOARDFACTORY_HPP
#define CLASSICBOARDFACTORY_HPP

#include <iostream>
#include "BoardFactory.hpp"
#include "Board.hpp"
#include "pieces/pawn.hpp"
#include "pieces/bishop.hpp"
#include "pieces/king.hpp"
#include "pieces/knight.hpp"
#include "pieces/queen.hpp"
#include "pieces/rook.hpp"
class ClassicBoardFactory : public BoardFactory {
	public:
		ClassicBoardFactory() : BoardFactory() {}
		virtual Board createBoard(){
			Board board;
			board.addPiece(new Rook  ('a', '1', 'w', 'R', board));
			board.addPiece(new Knight('b', '1', 'w', 'N', board));
			board.addPiece(new Bishop('c', '1', 'w', 'B', board));
			board.addPiece(new Queen ('d', '1', 'w', 'Q', board));
			board.addPiece(new King  ('e', '1', 'w', 'K', board));
			board.addPiece(new Bishop('f', '1', 'w', 'B', board));
			board.addPiece(new Knight('g', '1', 'w', 'N', board));
			board.addPiece(new Rook  ('h', '1', 'w', 'R', board));
			board.addPiece(new Pawn  ('a', '2', 'w', 'P', board));
			board.addPiece(new Pawn  ('b', '2', 'w', 'P', board));
			board.addPiece(new Pawn  ('c', '2', 'w', 'P', board));
			board.addPiece(new Pawn  ('d', '2', 'w', 'P', board));
			board.addPiece(new Pawn  ('e', '2', 'w', 'P', board));
			board.addPiece(new Pawn  ('f', '2', 'w', 'P', board));
			board.addPiece(new Pawn  ('g', '2', 'w', 'P', board));
			board.addPiece(new Pawn  ('h', '2', 'w', 'P', board));
			board.addPiece(new Pawn  ('a', '7', 'b', 'p', board));
			board.addPiece(new Pawn  ('b', '7', 'b', 'p', board));
			board.addPiece(new Pawn  ('c', '7', 'b', 'p', board));
			board.addPiece(new Pawn  ('d', '7', 'b', 'p', board));
			board.addPiece(new Pawn  ('e', '7', 'b', 'p', board));
			board.addPiece(new Pawn  ('f', '7', 'b', 'p', board));
			board.addPiece(new Pawn  ('g', '7', 'b', 'p', board));
			board.addPiece(new Pawn  ('h', '7', 'b', 'p', board));
			board.addPiece(new Rook  ('a', '8', 'b', 'r', board));
			board.addPiece(new Knight('b', '8', 'b', 'n', board));
			board.addPiece(new Bishop('c', '8', 'b', 'b', board));
			board.addPiece(new Queen ('d', '8', 'b', 'q', board));
			board.addPiece(new King  ('e', '8', 'b', 'k', board));
			board.addPiece(new Bishop('f', '8', 'b', 'b', board));
			board.addPiece(new Knight('g', '8', 'b', 'n', board));
			board.addPiece(new Rook  ('h', '8', 'b', 'r', board));
			return board;
		}
};

#endif
