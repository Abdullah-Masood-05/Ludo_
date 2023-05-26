#pragma once
#include "Piece.h"
#include<SFML/Graphics.hpp>
class Green :
    public Piece
{
public:
    Green(Position p, P_col c, Board* b);
    void board_dis(sf::RenderWindow& w, int x, int y, int squareSize, float scale);
    P_col GetColor();
   virtual bool legalmove(Position, int) ;
};

