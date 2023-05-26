#pragma once
class Board;
#include"utility.h"
#include<SFML/Graphics.hpp>
class Piece
{
protected:
	Position pos;
	P_col c;
	Board* B;
	

public:
	Piece();
	Piece(Position p, P_col T, Board* b);
	virtual P_col GetColor() = 0;
	virtual void board_dis(sf::RenderWindow& w, int x, int y, int squareSize, float scale) = 0;
	void move(Position p);
	virtual bool legalmove(Position, int)=0;
	
};

