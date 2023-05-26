#pragma once
#include "Piece.h"
#include<SFML/Graphics.hpp>
class Blue :
    public Piece
{
public:
    Blue(Position p, P_col c, Board* b);
   
    void board_dis(sf::RenderWindow& w, int x, int y, int squareSize, float scale);
    P_col GetColor();
    virtual bool legalmove(Position, int);


};

