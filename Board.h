#pragma once
class Piece;
#include"utility.h"
class Board
{
public:
	Piece*** ps;
	Board();
	void load4();
	void load2();

	Board(int);
	Piece* getPieceat(Position& p)const;
	Piece*& Move(Position &S_P, Position &D_P,Board &B,bool);
	void SetPiece(Position &P, Piece* p);
};

