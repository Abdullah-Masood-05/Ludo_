#pragma once
#include "Piece.h"
#include<SFML/Graphics.hpp>

class Red :
    public Piece
{
public:
    Red(Position p, P_col c, Board* b);
    P_col GetColor();

    void board_dis(sf::RenderWindow& w, int x, int y, int squareSize, float scale);
    virtual bool legalmove(Position, int);

};

