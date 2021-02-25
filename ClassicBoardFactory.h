#ifndef CLASSICBOARDFACTORY_HPP
#define CLASSICBOARDFACTORY_HPP

#include <iostream>
#include "BoardFactory.h"
class ClassicBoardFactory extends BoardFactory{
	private:
		pieces[][];
	public:
		ClassicBoardFactory();
		virtual Board createBoard(){
			WRook1   = new Rook  ('a', '1', 'w', nullptr, nullptr);
			WKnight1 = new Knight('b', '1', 'w', nullptr, nullptr);
			WBishop1 = new Bishop('c', '1', 'w', nullptr, nullptr);
			WQueen   = new Queen ('d', '1', 'w', nullptr, nullptr);
			WKing    = new King  ('e', '1', 'w', nullptr, nullptr);
			WRook2   = new Rook  ('f', '1', 'w', nullptr, nullptr);
			WKnight2 = new Knight('g', '1', 'w', nullptr, nullptr);
			WBishop2 = new Bishop('h', '1', 'w', nullptr, nullptr);
			WPawn1 = new Pawn('a', '2', 'w', nullptr, nullptr);
			WPawn2 = new Pawn('b', '2', 'w', nullptr, nullptr);
			WPawn3 = new Pawn('c', '2', 'w', nullptr, nullptr);
			WPawn4 = new Pawn('d', '2', 'w', nullptr, nullptr);
			WPawn5 = new Pawn('e', '2', 'w', nullptr, nullptr);
			WPawn6 = new Pawn('f', '2', 'w', nullptr, nullptr);
			WPawn7 = new Pawn('g', '2', 'w', nullptr, nullptr);
			WPawn8 = new Pawn('h', '2', 'w', nullptr, nullptr);
			BPawn1 = new Pawn('a', '7', 'b', nullptr, nullptr);
			BPawn2 = new Pawn('b', '7', 'b', nullptr, nullptr);
			BPawn3 = new Pawn('c', '7', 'b', nullptr, nullptr);
			BPawn4 = new Pawn('d', '7', 'b', nullptr, nullptr);
			BPawn5 = new Pawn('e', '7', 'b', nullptr, nullptr);
			BPawn6 = new Pawn('f', '7', 'b', nullptr, nullptr);
			BPawn7 = new Pawn('g', '7', 'b', nullptr, nullptr);
			BPawn8 = new Pawn('h', '7', 'b', nullptr, nullptr);
			BRook1   = new Rook  ('a', '8', 'b', nullptr, nullptr);
			BKnight1 = new Kinght('b', '8', 'b', nullptr, nullptr);
			BBishop1 = new Bishop('c', '8', 'b', nullptr, nullptr);
			BQueen   = new Queen ('d', '8', 'b', nullptr, nullptr);
			BKing    = new King  ('e', '8', 'b', nullptr, nullptr);
			BRook2   = new Rook  ('f', '8', 'b', nullptr, nullptr);
			BKnight2 = new Knight('g', '8', 'b', nullptr, nullptr);
			BBishop2 = new Bishop('h', '8', 'b', nullptr, nullptr);
			Pieces= new Piece[[BRook1, BKnight1, BBishop1, BQueen, BKing, BBishop2, BKnight2, BRook2],
					[BPawn1, BPawn2, BPawn3, BPawn4, BPawn5, BPawn6, BPawn7, BPawn8],
					[],
					[],
					[],
					[],
					[WPawn1, WPawn2, WPawn3, WPawn4, WPawn5, WPawn6, WPawn7, WPawn8],
					[WRook1, WKnight1, WBishop1, WQueen, WKing, WBishop2, WKnight2, WRook2 ]];
		
		}
};

#endif
