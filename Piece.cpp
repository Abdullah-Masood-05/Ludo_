#include "Piece.h"
#include"Board.h"
#include<string>
#include"game.h"
#include<SFML/Graphics.hpp>
using namespace std;
Piece::Piece(Position p, P_col _c, Board* b)
{
	this->pos = p, c = _c, B = b;
}
P_col Piece::GetColor()
{
	return c;
}
Piece::Piece()
{
	this->B = nullptr;
	this->pos.ri = 0;
	this->pos.ci = 0;
}
void Piece::move(Position p)
{
	this->pos = p;
}

