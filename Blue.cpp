#include"Blue.h"
Blue::Blue(Position p, P_col c, Board* b) :
    Piece(p, c, b)
{

}
void Blue::board_dis(sf::RenderWindow& w, int x, int y, int daba, float scale) {
    sf::Texture tex;
    if (!tex.loadFromFile("images/blue_piece.png")) {
        cout << "Failed to load texture!" << endl;
        return;
    }
    sf::Sprite sp(tex);
    float centerX = x * daba * scale + daba * scale / 2.0;
    float centerY = y * daba * scale + daba * scale / 2.0;
    sp.setPosition(centerX, centerY);
    sp.setScale(scale, scale);
    sp.setOrigin(sp.getLocalBounds().width / 2.0, sp.getLocalBounds().height / 2.0);
    w.draw(sp);
}
P_col Blue::GetColor()
{
    return BLUE;
}
bool Blue::legalmove(Position p, int val)
{
    Position m, q, r, s; m.ri = 10, m.ci = 10, q.ri = 10, q.ci = 13, r.ri = 13, r.ci = 10, s.ri = 13, s.ci = 13;
    if (p == m || p == q || p == r || p == s)
    {
        return val == 6;
    }
    if (p.ci == 16) {
        switch (p.ri)
        {
        case(13):
            return val <= 5;
        case(12):
            return val <= 4;
        case(11):
            return val <= 3;
        case(10):
            return val <= 2;
        case(9):
            return val <= 1;
        case(8):
            return false;
        default:
            return true;
        }
    }
    
    return true;

}

