#include "Yellow.h"
Yellow::Yellow(Position p, P_col c, Board* b) :
    Piece(p, c, b)
{

}
void Yellow::board_dis(sf::RenderWindow& w, int x, int y, int daba, float scale) {
    sf::Texture tex;
    if (!tex.loadFromFile("images/yellow_piece.png")) {
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
P_col Yellow::GetColor()
{
    return YELLOW;
}
bool Yellow::legalmove(Position p, int val) {
    Position m, q, r, s;m.ri = 10, m.ci = 19, q.ri = 10, q.ci = 22, r.ri = 13, r.ci = 19, s.ri = 13, s.ci = 22;
    if (p == m || p == q || p == r || p == s)
    {
        return val == 6;
    }

    if (p.ri == 7) {
        switch (p.ci)
        {
        case(22):
            return val <= 5;
        case(21):
            return val <= 4;
        case(20):
            return val <= 3;
        case(19):
            return val <= 2;
        case(18):
            return val <= 1;
        case(17):
            return false;
        default:
            return true;
        }
    }
    return true;

}
