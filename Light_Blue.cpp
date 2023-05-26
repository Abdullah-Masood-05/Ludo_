#include"Light_Blue.h"
Light_Blue::Light_Blue(Position p, P_col c, Board* b) :
    Piece(p, c, b)
{

}
void Light_Blue::board_dis(sf::RenderWindow& w, int x, int y, int daba, float scale) {
    sf::Texture tex;
    if (!tex.loadFromFile("images/light_blue_piece.png")) {
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
P_col Light_Blue::GetColor()
{
    return LIGHT_BLUE;
}
bool Light_Blue::legalmove(Position p, int val) {
    Position m, q, r, s; m.ri = 1, m.ci = 1, q.ri = 1, q.ci = 4, r.ri = 4, r.ci = 1, s.ri = 4, s.ci = 4;
    if (p == m || p == q || p == r || p == s)
    {
        return val == 6;
    }

    if (p.ri == 7) {
        switch (p.ci)
        {
        case(1):
            return val <= 5;
        case(2):
            return val <= 4;
        case(3):
            return val <= 3;
        case(4):
            return val <= 2;
        case(5):
            return val <= 1;
        case(6):
            return false;
        default:
            return true;
        }
    }
    return true;

}