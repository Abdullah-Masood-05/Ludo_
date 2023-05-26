#include "Game.h"
#include<iostream>
#include<string>
#include"Player.h"
#include"Board.h"
#include<SFML/Audio.hpp>
#include<array>
using namespace sf;
#include<SFML/Graphics.hpp>
#include<fstream>
using namespace std;
Ludo::Ludo()
{
    Ps[0] = new Player("Hasseb", LIGHT_BLUE);
    Ps[1] = new Player("Rehman", RED);
    Ps[2] = new Player("Abdullah", GREEN);
    Ps[3] = new Player("ALI", YELLOW);
    Ps[4] = new Player("Ahmed", BLUE);
    Ps[5] = new Player("Bazil", PURPLE);
    B = new Board();
    DB = new Board(0);
    P.ri = 0; P.ci = 0;
    dice_val = 0;
    // srand(time(0));
    turn = 0;
}
void Ludo::DisplayTurnChange(sf::RenderWindow& w, Player* p)
{
    sf::Font font;
    if (!font.loadFromFile("phantomstorm.ttf")) {
        cout << "Failed to load font" << endl;
    }

    sf::Text t1("Green's Turn", font, 25);
    t1.setPosition(1175, 50);
    t1.setFillColor(sf::Color::White);
    sf::Text t2("Red's Turn", font, 25);
    t2.setPosition(1175, 100);
    t2.setFillColor(sf::Color::White);
   // sf::Text text("--->", font, 25);

    sf::Text t3("Orange's Turn", font, 25);
    t3.setPosition(1175, 150);
    t3.setFillColor(sf::Color::White);
    sf::Text t4("Purple's Turn", font, 25);
    t4.setPosition(1175, 200);
    t4.setFillColor(sf::Color::White);

    sf::Text t5("Blue's Turn", font, 25);
    t5.setPosition(1175, 250);
    t5.setFillColor(sf::Color::White);
    sf::Text t6("Yellow's Turn", font, 25);
    t6.setPosition(1175, 300);
    t6.setFillColor(sf::Color::White);
    switch (turn)
    {
    case(0):
        t1.setPosition(1175, 50);
        t1.setFillColor(sf::Color::Green); break;
    case(1):
        t2.setPosition(1175, 100);
        t2.setFillColor(sf::Color::Red); break;
    case(2):
        t3.setPosition(1175, 150);
        t3.setFillColor(sf::Color::Cyan); break;
    case(3):
        t4.setPosition(1175, 200);
        t4.setFillColor(sf::Color::Magenta); break;
    case(4):
        t5.setPosition(1175, 250);
        t5.setFillColor(sf::Color::Blue); break;
    case(5):
        t6.setPosition(1175, 300);
        t6.setFillColor(sf::Color::Yellow); break;

    }
    
     w.draw(t1); w.draw(t2); w.draw(t3), w.draw(t4), w.draw(t5), w.draw(t6);
}
void Ludo::DisplayTurnChange4(sf::RenderWindow& w, Player* p)
{
    sf::Font font;
    if (!font.loadFromFile("phantomstorm.ttf")) {
        cout << "Failed to load font" << endl;
    }

    sf::Text t1("Green's Turn", font, 25);
    t1.setPosition(1175, 50);
    t1.setFillColor(sf::Color::White);
    sf::Text t2("Orange's Turn", font, 25);
    t2.setPosition(1175, 100);
    t2.setFillColor(sf::Color::White);
    // sf::Text text("--->", font, 25);

    sf::Text t3("Purple's Turn", font, 25);
    t3.setPosition(1175, 150);
    t3.setFillColor(sf::Color::White);
    sf::Text t4("Yellow's Turn", font, 25);
    t4.setPosition(1175, 200);
    t4.setFillColor(sf::Color::White);

   
    switch (turn)
    {
    case(0):
        t1.setPosition(1175, 50);
        t1.setFillColor(sf::Color::Green); break;
    case(2):
        t2.setPosition(1175, 100);
        t2.setFillColor(sf::Color::Cyan); break;
    case(3):
        t3.setPosition(1175, 150);
        t3.setFillColor(sf::Color::Magenta); break;
    case(5):
        t4.setPosition(1175, 200);
        t4.setFillColor(sf::Color::Yellow); break;
    }

    w.draw(t1); w.draw(t2); w.draw(t3), w.draw(t4);
}
void Ludo::DisplayTurnChange2(sf::RenderWindow& w, Player* p)
{
    sf::Font font;
    if (!font.loadFromFile("phantomstorm.ttf")) {
        cout << "Failed to load font" << endl;
    }

    sf::Text t1("Green's Turn", font, 25);
    t1.setPosition(1175, 50);
    t1.setFillColor(sf::Color::White);
    sf::Text t4("Purple's Turn", font, 25);
    t4.setPosition(1175, 200);
    t4.setFillColor(sf::Color::White);

    
    switch (turn)
    {
    case(0):
        t1.setPosition(1175, 50);
        t1.setFillColor(sf::Color::Green); break;
   
    case(3):
        t4.setPosition(1175, 200);
        t4.setFillColor(sf::Color::Magenta); break;

    }

    w.draw(t1); w.draw(t4);
}
Position Ludo::getRowColbyLeftClick(sf::RenderWindow& W)
{
    sf::Event ev;
    while (1)
    {
        while (W.pollEvent(ev))
        {
            if (ev.type == ev.Closed)
                W.close();
            if (ev.type == ev.MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                auto po = sf::Mouse::getPosition(W);
                Position P;
                P.ri = po.y, P.ci = po.x;
                return P;
            }
        }
    }
}
Position Ludo::selectpiece(sf::RenderWindow& window)
{
    Position P;
    P = getRowColbyLeftClick(window);

    //int br = 69, bc = 69;
    P.ri = P.ri / 47;
    P.ci = P.ci / 47;
    return P;
}
bool Ludo::islegalSource(Player* AP, Position S_P)
{
    if (S_P.ri < 0 || S_P.ri >= 15 || S_P.ci < 0 || S_P.ci >= 24)
        return false;
    Piece* p = B->getPieceat(S_P);
    Piece* p2 = DB->getPieceat(S_P);
    if (p == nullptr && p2 == nullptr)
    {
        return false;
    }
    else if (p != nullptr && p2 == nullptr)
    {
        return (p->GetColor() == AP->GetColor());
    }
    else
    {
        if (p->GetColor() == AP->GetColor())
        {
            return true;
        }
        else if (p2->GetColor() == AP->GetColor())
        {
            DB->SetPiece(S_P, p);
            B->SetPiece(S_P, p2);
            return true;
        }
        
        return false;
    }
    
}
void Ludo::turnChange()
{
    turn = (turn + 1) % 6;
}
void Ludo::draw_board_pieces(sf::RenderWindow& w) {
    load_board(w);
    int daba = 47;
    float scale = 1;
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 15; j++) {
            Position P;
            P.ri = j; P.ci = i;
            Piece* current_piece = B->getPieceat(P);
            if (current_piece != nullptr) {
                current_piece->board_dis(w, i, j, daba, scale);
            }
        }
    }
}
bool Ludo::h_pressed(Position P)
{
    if (((P.ri == 1 && P.ci == 1) || (P.ri == 1 && P.ci == 4) || (P.ri == 4 && P.ci == 1) || (P.ri == 4 && P.ci == 4)))
    {
        return true;
    }
    //   RED0
    else if (((P.ri == 1 && P.ci == 10) || (P.ri == 1 && P.ci == 13) || (P.ri == 4 && P.ci == 10) || (P.ri == 4 && P.ci == 13)))
    {
        return 1;
    }
    // Purple
    else if (((P.ri == 1 && P.ci == 19) || (P.ri == 1 && P.ci == 22) || (P.ri == 4 && P.ci == 19) || (P.ri == 4 && P.ci == 22)))
    {
        return 1;
    }
    //   Blue
    else if (((P.ri == 10 && P.ci == 19) || (P.ri == 10 && P.ci == 22) || (P.ri == 13 && P.ci == 19) || (P.ri == 13 && P.ci == 22)))
    {
        return 1;
    }
    //		Light_Blue
    else if (((P.ri == 10 && P.ci == 10) || (P.ri == 10 && P.ci == 13) || (P.ri == 13 && P.ci == 10) || (P.ri == 13 && P.ci == 13)))
    {
        return 1;
    }
    //	RED
    else if (((P.ri == 10 && P.ci == 1) || (P.ri == 10 && P.ci == 4) || (P.ri == 13 && P.ci == 1) || (P.ri == 13 && P.ci == 4)))
    {
        return 1;
    }
    else
        return false;
}
bool Ludo::light_blue_home_p(Position P, P_col C)
{
    if (C == LIGHT_BLUE)
        if ((P.ri == 7 && P.ci == 0) || (P.ri == 7 && P.ci == 1) || (P.ri == 7 && P.ci == 2) || (P.ri == 7 && P.ci == 3) || (P.ri == 7 && P.ci == 4) || (P.ri == 7 && P.ci == 5) || 
            (P.ri == 8 && P.ci == 0) || (P.ri == 8 && P.ci == 1) || (P.ri == 8 && P.ci == 2) || (P.ri == 8 && P.ci == 3) || (P.ri == 8 && P.ci == 4) || (P.ri == 8 && P.ci == 5))
            return true;
    return false;

}
Position& Ludo::light_blue_special_move(int n)
{
    Position P;
    switch (n)
    {
    case 82:
        P.ri = 8;
        P.ci = 5;
        return P;
    case 83:
        P.ri = 8;
        P.ci = 4;
        return P;
    case 84:
        P.ri = 8;
        P.ci = 3;
        return P;
    case 85:
        P.ri = 8;
        P.ci = 2;
        return P;
    case 86:
        P.ri = 8;
        P.ci = 1;
        return P;
    case 87:
        P.ri = 8;
        P.ci = 0;
        return P;
    case 88:
        P.ri = 7;
        P.ci = 0;
        return P;
    case 0:
        P.ri = 7;
        P.ci = 1;
        return P;
    case 1:
        P.ri = 7;
        P.ci = 2;
        return P;
    case 2:
        P.ri = 7;
        P.ci = 3;
        return P;
    case  3:
        P.ri = 7;
        P.ci = 4;
        return P;
    case 4:
        P.ri = 7;
        P.ci = 5;
        return P;
    case 5:
        P.ri = 7;
        P.ci = 6;
        return P;
    case 6:
        P.ri = 7, P.ci = 6; return P;
    }
    
    if (n >= 89)
    {
        n = n % 89; return light_blue_special_move(n);
    }
}
bool Ludo::red_home_p(Position p, P_col C)
{
    if (C == RED)
        if ((p.ri == 0 && p.ci == 7)||(p.ri == 1 && p.ci == 7) || (p.ri == 2 && p.ci == 7) || (p.ri == 3 && p.ci == 7) || (p.ri == 4 && p.ci == 7) || (p.ri == 5 && p.ci == 7) || 
            (p.ri == 0 && p.ci == 6) || (p.ri == 1 && p.ci == 6) || (p.ri == 2 && p.ci == 6) || (p.ri == 3 && p.ci == 6) || (p.ri == 4 && p.ci == 6) || (p.ri == 5 && p.ci == 6))
            return true;
    return false;
}
Position& Ludo::red_special_move(int n)
{
    Position P;
    switch (n)
    {

    case 5:
        P.ri = 5;
        P.ci = 6;
        return P;
    case 6:
        P.ri = 4;
        P.ci = 6;
        return P;
    case 7:
        P.ri = 3;
        P.ci = 6;
        return P;
    case 8:
        P.ri = 2;
        P.ci = 6;
        return P;
    case 9:
        P.ri = 1;
        P.ci = 6;
        return P;
    case 10:
        P.ri = 0;
        P.ci = 6;
        return P;
    case 11:
        P.ri = 0;
        P.ci = 7;
        return P;
    case 12:
        P.ri = 1; P.ci = 7;
        return P;
    case 13:
        P.ri = 2; P.ci = 7;
        return P;
    case 14:
        P.ri = 3; P.ci = 7;
        return P;
    case 15:
        P.ri = 4; P.ci = 7;

    case 16:
        P.ri = 5; P.ci = 7;
        return P;
    case 17:
        P.ri = 6; P.ci = 7;
        return P;
    }
}
bool Ludo::green_home_p(Position p, P_col C)
{
    if (C == GREEN)
        if ((p.ri == 0 && p.ci == 16) || (p.ri == 1 && p.ci == 16) || (p.ri == 2 && p.ci == 16) || (p.ri == 3 && p.ci == 16) || (p.ri == 4 && p.ci == 16) || (p.ri == 5 && p.ci == 16)||
            (p.ri == 0 && p.ci == 15) || (p.ri == 1 && p.ci == 15) || (p.ri == 2 && p.ci == 15) || (p.ri == 3 && p.ci == 15) || (p.ri == 4 && p.ci == 15) || (p.ri == 5 && p.ci == 15))
            return true;
    return false;
}
Position& Ludo::green_special_move(int n)
{
    Position P;
    switch (n)
    {
    case 24:
        P.ri = 5;
        P.ci = 15;
        return P;
    case 25:
        P.ri = 4;
        P.ci = 15;
        return P;
    case 26:
        P.ri = 3;
        P.ci = 15;
        return P;
    case 27:
        P.ri = 2;
        P.ci = 15;
        return P;
    case 28:
        P.ri = 1;
        P.ci = 15;
        return P;
    case 29:
        P.ri = 0;
        P.ci = 15;
        return P;
    case 30:
        P.ri = 0;
        P.ci = 16;
        return P;
    case 31:
        P.ri = 1; P.ci = 16;
        return P;
    case 32:
        P.ri = 2; P.ci = 16;
        return P;
    case 33:
        P.ri = 3; P.ci = 16;
        return P;
    case 34:
        P.ri = 4; P.ci = 16;
        return P;
    case 35:
        P.ri = 5; P.ci = 16;
        return P;
    case(36):P.ri = 6, P.ci = 16; return P;
    }
}
bool Ludo::yellow_home_p(Position p, P_col C)
{
    if (C == YELLOW)
        if ((p.ri == 7 && p.ci == 23) || (p.ri == 7 && p.ci == 22) || (p.ri == 7 && p.ci == 21) || (p.ri == 7 && p.ci == 20) || (p.ri == 7 && p.ci == 19) || (p.ri == 7 && p.ci == 18)||
            (p.ri == 6 && p.ci == 23) || (p.ri == 6 && p.ci == 22) || (p.ri == 6 && p.ci == 21) || (p.ri == 6 && p.ci == 20) || (p.ri == 6 && p.ci == 19) || (p.ri == 6 && p.ci == 18))
            return true;
    return false;
}
Position& Ludo::yellow_special_move(int n)
{
    Position P;
    switch (n)
    {
    case 37:
        P.ri = 6;
        P.ci = 18;
        return P;
    case 38:
        P.ri = 6;
        P.ci = 19;
        return P;
    case 39:
        P.ri = 6;
        P.ci = 20;
        return P;
    case 40:
        P.ri = 6;
        P.ci = 21;
        return P;
    case 41:
        P.ri = 6;
        P.ci = 22;
        return P;
    case 42:
        P.ri = 6;
        P.ci = 23;
        return P;
    case 43:
        P.ri = 7;
        P.ci = 23;
        return P;

    case 44:
        P.ri = 7; P.ci = 22;
        return P;
    case 45:
        P.ri = 7; P.ci = 21;
        return P;
    case 46:
        P.ri = 7; P.ci = 20;
        return P;
    case 47:
        P.ri = 7; P.ci = 19;
        return P;
    case 48:
        P.ri = 7; P.ci = 18;
        return P;
    }
}
bool Ludo::blue_home_p(Position p, P_col C)
{
    if (C == BLUE)
        if ((p.ri == 14 && p.ci == 16) || (p.ri == 13 && p.ci == 16) || (p.ri == 12 && p.ci == 16) || (p.ri == 11 && p.ci == 16) || (p.ri == 10 && p.ci == 16) || (p.ri == 9 && p.ci == 16)||
            (p.ri == 14 && p.ci == 17) || (p.ri == 13 && p.ci == 17) || (p.ri == 12 && p.ci == 17) || (p.ri == 11 && p.ci == 17) || (p.ri == 10 && p.ci == 17) || (p.ri == 9 && p.ci == 17))
            return true;
    return false;
}
Position& Ludo::blue_special_move(int n)
{
    switch (n)
    {
    case 50:
        P.ri = 9;
        P.ci = 17;
        return P;
    case 51:
        P.ri = 10;
        P.ci = 17;
        return P;
    case 52:
        P.ri = 11;
        P.ci = 17;
        return P;
    case 53:
        P.ri = 12;
        P.ci = 17;
        return P;
    case 54:
        P.ri = 13;
        P.ci = 17;
        return P;
    case 55:
        P.ri = 14;
        P.ci = 17;
        return P;
    case 56:
        P.ri = 14;
        P.ci = 16;
        return P;
    case 57:
        P.ri = 13; P.ci = 16;
        return P;
    case 58:
        P.ri = 12; P.ci = 16;
        return P;
    case 59:
        P.ri = 11; P.ci = 16;
    case 60:
        P.ri = 10; P.ci = 16;
        return P;
    case 61:
        P.ri = 9; P.ci = 16;
        return P;
    }
}
bool Ludo::purple_home_p(Position p, P_col C)
{
    if (C == PURPLE)
        if ((p.ri == 14 && p.ci == 7) || (p.ri == 13 && p.ci == 7) || (p.ri == 12 && p.ci == 7) || (p.ri == 11 && p.ci == 7) || (p.ri == 10 && p.ci == 7) || (p.ri == 9 && p.ci == 7)||
            (p.ri == 14 && p.ci == 8) || (p.ri == 13 && p.ci == 8) || (p.ri == 12 && p.ci == 8) || (p.ri == 11 && p.ci == 8) || (p.ri == 10 && p.ci == 8) || (p.ri == 9 && p.ci == 8))
            return true;
    return false;
}
Position& Ludo::purple_special_move(int n)
{
    switch (n)
    {
    case 69:
        P.ri = 9;
        P.ci = 8;
        return P;
    case 70:
        P.ri = 10;
        P.ci = 8;
        return P;
    case 71:
        P.ri = 11;
        P.ci = 8;
        return P;
    case 72:
        P.ri = 12;
        P.ci = 8;
        return P;
    case 73:
        P.ri = 13;
        P.ci = 8;
        return P;
    case 74:
        P.ri = 14;
        P.ci = 8;
        return P;
    case 75:
        P.ri = 14;
        P.ci = 7;
        return P;
    case 76:
        P.ri = 13; P.ci = 7;
        return P;
    case 77:
        P.ri = 12; P.ci = 7;
        return P;
    case 78:
        P.ri = 11; P.ci = 7;
        return P;
    case 79:
        P.ri = 10; P.ci = 7;
        return P;
    case 80:
        P.ri = 9; P.ci = 7;
        return P;
    }
}
void Ludo::load_board(sf::RenderWindow& window)
{
    sf::Texture tex;
    if (!tex.loadFromFile("images/ludo_board_piece.png")) {
        cout << "Texture failed to load!" << endl;
        return;
    }
    sf::Sprite sp(tex);
    sp.setScale(1, 1);
    //sf::FloatRect bounds = sp.getLocalBounds();
    //sp.setOrigin(bounds.width / 2, bounds.height / 2);
    window.draw(sp);
}
int Ludo::dice_roll(RenderWindow&w)
{
    srand(time(0));
     dice_val= (rand() % 6 + 1);
     animation_dice(w, 1175, 517);
     display_dice(w, dice_val, 1175, 517);
     return dice_val;
}
void Ludo::set_pos(Piece* &m,Position & b)
{
    if (m == nullptr)return;
    else if (m->GetColor() == LIGHT_BLUE)
    {
        if (turn == LIGHT_BLUE) { DB->ps[b.ri][b.ci]=m; return; }
        Position p, q, r, s; p.ri = 1, p.ci = 1, q.ri = 1, q.ci = 4, r.ri = 4, r.ci = 1, s.ri = 4, s.ci = 4;
        int count = 0;
        if (B->getPieceat(p) == nullptr) { B->ps[1][1] = m; return; }
        if (B->getPieceat(q) == nullptr) { B->ps[1][4] = m; return; }
        if (B->getPieceat(r) == nullptr) { B->ps[4][1] = m; return; }
        if (B->getPieceat(s) == nullptr) { B->ps[4][4] = m; return; }
    }
    else if (m->GetColor() == RED)
    {
        if (turn == 1) { DB->SetPiece(b, m) ; return; }
        Position p, q, r, s; p.ri = 1, p.ci = 10, q.ri = 1, q.ci = 13, r.ri = 4, r.ci = 10, s.ri = 4, s.ci = 13;
        int count = 0;
        if (B->getPieceat(p) == nullptr) { B->ps[1][10] = m; return; }
        if (B->getPieceat(q) == nullptr) { B->ps[1][13] = m; return; }
        if (B->getPieceat(r) == nullptr) { B->ps[4][10] = m; return; }
        if (B->getPieceat(s) == nullptr) { B->ps[4][13] = m; return; }
    }
    else if (m->GetColor() == GREEN)
    {
        if (turn == GREEN) { DB->SetPiece(b, m); return; }
        Position p, q, r, s; p.ri = 1, p.ci = 19, q.ri = 1, q.ci = 22, r.ri = 4, r.ci = 19, s.ri = 4, s.ci = 22;
        int count = 0;
        if (B->getPieceat(p) == nullptr) { B->ps[1][19] = m; return; }
        if (B->getPieceat(q) == nullptr) { B->ps[1][22] = m; return; }
        if (B->getPieceat(r) == nullptr) { B->ps[4][19] = m; return; }
        if (B->getPieceat(s) == nullptr) { B->ps[4][22] = m; return; }
    }
    else if (m->GetColor() == YELLOW)
    {
        if (turn == YELLOW) { DB->SetPiece(b, m); return; }
        Position p, q, r, s; p.ri = 10, p.ci = 19, q.ri = 10, q.ci = 22, r.ri = 13, r.ci = 19, s.ri = 13, s.ci = 22;
        int count = 0;
        if (B->getPieceat(p) == nullptr) { B->ps[10][19] = m; return; }
        if (B->getPieceat(q) == nullptr) { B->ps[10][22] = m; return; }
        if (B->getPieceat(r) == nullptr) { B->ps[13][19] = m; return; }
        if (B->getPieceat(s) == nullptr) { B->ps[13][22] = m; return; }
    }
    else if (m->GetColor() == BLUE)
    {
        if (turn == BLUE) { DB->SetPiece(b, m); return; }
        Position p, q, r, s; p.ri = 10, p.ci = 10, q.ri = 10, q.ci = 13, r.ri = 13, r.ci = 10, s.ri = 13, s.ci = 13;
        int count = 0;
        if (B->getPieceat(p) == nullptr) { B->ps[10][10] = m; return; }
        if (B->getPieceat(q) == nullptr) { B->ps[10][13] = m; return; }
        if (B->getPieceat(r) == nullptr) { B->ps[13][10] = m; return; }
        if (B->getPieceat(s) == nullptr) { B->ps[13][13] = m; return; }
    }
    else if (m->GetColor() == PURPLE)
    {
        if (turn == PURPLE) { DB->SetPiece(b, m); return; }
        Position p, q, r, s; p.ri = 10, p.ci = 1, q.ri = 10, q.ci = 4, r.ri = 13, r.ci = 1, s.ri = 13, s.ci = 4;
        int count = 0;
        if (B->getPieceat(p) == nullptr) { B->ps[10][1] = m; return; }
        if (B->getPieceat(q) == nullptr) { B->ps[10][4] = m; return; }
        if (B->getPieceat(r) == nullptr) { B->ps[13][1] = m; return; }
        if (B->getPieceat(s) == nullptr) { B->ps[13][14] = m; return; }
    }
}
int Ludo::light_blue_all_h()
{
    Position p,q,r,s; p.ri = 1, p.ci = 1,q.ri=1,q.ci=4,r.ri=4,r.ci=1,s.ri=4,s.ci=4;
    int count = 0;
    ((B->getPieceat(p) == nullptr) ? count : count++);
    ((B->getPieceat(q) == nullptr) ? count : count++);
    ((B->getPieceat(r) == nullptr) ? count : count++);
    ((B->getPieceat(s) == nullptr) ? count : count++);
    return count;
}
int Ludo::red_all_h()
{
    Position p, q, r, s; p.ri = 1, p.ci = 10, q.ri = 1, q.ci = 13, r.ri = 4, r.ci = 10, s.ri = 4, s.ci = 13;
    int count = 0;
    ((B->getPieceat(p) == nullptr) ? count : count++);
    ((B->getPieceat(q) == nullptr) ? count : count++);
    ((B->getPieceat(r) == nullptr) ? count : count++);
    ((B->getPieceat(s) == nullptr) ? count : count++);
    return count;
}
int Ludo::green_all_h()
{
    Position p, q, r, s; p.ri = 1, p.ci = 19, q.ri = 1, q.ci = 22, r.ri = 4, r.ci = 19, s.ri = 4, s.ci = 22;
    int count = 0;
    ((B->getPieceat(p) == nullptr) ? count : count++);
    ((B->getPieceat(q) == nullptr) ? count : count++);
    ((B->getPieceat(r) == nullptr) ? count : count++);
    ((B->getPieceat(s) == nullptr) ? count : count++);
    return count;
}
int Ludo::yellow_all_h()
{
    Position p, q, r, s; p.ri = 10, p.ci = 19, q.ri = 10, q.ci = 22, r.ri = 13, r.ci = 19, s.ri = 13, s.ci = 22;
    int count = 0;
    ((B->getPieceat(p) == nullptr) ? count : count++);
    ((B->getPieceat(q) == nullptr) ? count : count++);
    ((B->getPieceat(r) == nullptr) ? count : count++);
    ((B->getPieceat(s) == nullptr) ? count : count++);
    return count;
}
int Ludo::blue_all_h()
{
    Position p, q, r, s; p.ri = 10, p.ci = 10, q.ri = 10, q.ci = 13, r.ri = 13, r.ci = 10, s.ri = 13, s.ci = 13;
    int count = 0;
    ((B->getPieceat(p) == nullptr) ? count : count++);
    ((B->getPieceat(q) == nullptr) ? count : count++);
    ((B->getPieceat(r) == nullptr) ? count : count++);
    ((B->getPieceat(s) == nullptr) ? count : count++);
    return count;
}
int Ludo::purple_all_h()
{
    Position p, q, r, s; p.ri = 10, p.ci = 1, q.ri = 10, q.ci = 4, r.ri = 13, r.ci = 1, s.ri = 13, s.ci = 4;
    int count = 0;
    ((B->getPieceat(p) == nullptr) ? count : count++);
    ((B->getPieceat(q) == nullptr) ? count : count++);
    ((B->getPieceat(r) == nullptr) ? count : count++);
    ((B->getPieceat(s) == nullptr) ? count : count++);
    return count;
}
Position& Ludo::actualpos_val(int des)
{
    if (turn == 0)
    {
        if (light_blue_home_p(P, Ps[0]->GetColor()))
        {
            return light_blue_special_move(des);
        }
        else
            return Pos_val(des);
    }
    else if (turn == 1)
    {
        if (red_home_p(P, Ps[1]->GetColor()))
        {
            return red_special_move(des);
        }
        else
            return Pos_val(des);
    }
    else if (turn == 2)
    {
        if (green_home_p(P, Ps[2]->GetColor()))
        {
            return green_special_move(des);
        }
        else
            return Pos_val(des);
    }
    else if (turn == 3)
    {
        if (yellow_home_p(P, Ps[3]->GetColor()))
        {
            return yellow_special_move(des);
        }
        else
            return Pos_val(des);
    }
    else if (turn == 4)
    {
        if (blue_home_p(P, Ps[4]->GetColor()))
        {
            return blue_special_move(des);
        }
        else
            return Pos_val(des);
    }
    else if (turn == 5)
    {
        if (purple_home_p(P, Ps[5]->GetColor()))
        {
            return purple_special_move(des);
        }
        else
            return Pos_val(des);
    }

}
//void Ludo::Play(sf::RenderWindow& window) {
//    sf::Texture tex;
//    draw_board_pieces(window);
//    window.display();
//    Position S;
//    while (true) {
//         getRowColbyLeftClick(window);
//        S = selectpiece(window);
//        cout << S.ri << "     " << S.ci << "       INT VAL : " << index_val(S) << endl;
//    }
//}
void Ludo::animation_dice(sf::RenderWindow& w, int r, int c) {

    sf::Texture t1, t2, t3, t4;
    if (!t1.loadFromFile("images/roll1.png") || !t2.loadFromFile("images/roll2.png") || !t3.loadFromFile("images/roll3.png") ||
        !t4.loadFromFile("images/roll4.png")) {
        std::cout << "Failed to load texture!" << std::endl;
        return;
    }
    array<Texture, 4> txt = { t1, t2, t3, t4 };
    array<Sprite, 4> sp;
    sf::Music music;
    if (!music.openFromFile("Di.wav")) {
        std::cout << "Failed to load music!" << std::endl;
    }
    music.play();
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            sp[j].setTexture(txt[j]);
            //sp[j].setPosition(1150, 580);
            sp[j].setPosition(r, c);
            w.draw(sp[j]);
            w.display();
            sleep(sf::seconds(0.1));
        }
    }

    music.stop();
}
void Ludo::display_dice(RenderWindow& w, int value, int r, int c){
    Texture t;
    string s;
    if (value == 1) {
        s = "DICE/dice1.png";
    }
    else if (value == 2) {
        s = "DICE/dice2.png";
    }
    else if (value == 3) {
        s = "DICE/dice3.png";
    }
    else if (value == 4) {
        s = "DICE/dice4.png";
    }
    else if (value == 5) {
        s = "DICE/dice5.png";
    }
    else {// (value == 6) {
        s = "DICE/dice6.png";
    }
    if (!t.loadFromFile(s)) {
        cout << "Failed to load texture!" << endl;
        return;
    }
    Sprite sp(t);
    sp.setPosition(r, c);
    //sp.setPosition(1150, 580);
    w.draw(sp);
}
int Ludo::pieces_in_h()
{
    if (turn == 0)return light_blue_all_h();
    else if (turn == 1)return red_all_h();
    else if (turn == 2)return green_all_h();
    else if (turn == 3)return yellow_all_h();
    else if (turn == 4)return blue_all_h();
    else return purple_all_h();
}
bool Ludo::home_pressed()
{
    switch (turn)
    {
    case 0:
    {
        Position p, q, r, s; p.ri = 1, p.ci = 1, q.ri = 1, q.ci = 4, r.ri = 4, r.ci = 1, s.ri = 4, s.ci = 4;
        if (P == p || P == q || P == r || P == s)
        {
            return true;
        }
        return false;
    }
    case 1:
    {  Position p, q, r, s; p.ri = 1, p.ci = 10, q.ri = 1, q.ci = 13, r.ri = 4, r.ci = 10, s.ri = 4, s.ci = 13;
    if (P == p || P == q || P == r || P == s)
    {
        return true;
    }
    return false; }
    case 2:
    {     Position p, q, r, s; p.ri = 1, p.ci = 19, q.ri = 1, q.ci = 22, r.ri = 4, r.ci = 19, s.ri = 4, s.ci = 22;
    if (P == p || P == q || P == r || P == s)
    {
        return true;
    }
    return false; }
    case 3:
    {     Position p, q, r, s; p.ri = 10, p.ci = 19, q.ri = 10, q.ci = 22, r.ri = 13, r.ci = 19, s.ri = 13, s.ci = 22;
    if (P == p || P == q || P == r || P == s)
    {
        return true;
    }
    return false; }
    case 4:
    {     Position p, q, r, s; p.ri = 10, p.ci = 10, q.ri = 10, q.ci = 13, r.ri = 13, r.ci = 10, s.ri = 13, s.ci = 13;
    if (P == p || P == q || P == r || P == s)
    {
        return true;
    }
    return false; }
    case 5:
    {     Position p, q, r, s; p.ri = 10, p.ci = 1, q.ri = 10, q.ci = 4, r.ri = 13, r.ci = 1, s.ri = 13, s.ci = 4;
    if (P == p || P == q || P == r || P == s)
    {
        return true;
    }
    return false; }
    }
}
bool Ludo::isstop_pos(Position p)
{
    if (p.ri == 6 && p.ci == 1) return true;
    else if (p.ri == 2 && p.ci == 6)return true;
    else if (p.ri == 1 && p.ci == 8)return true;
    else if (p.ri == 2 && p.ci == 15)return true;
    else if (p.ri == 1 && p.ci == 17)return true;
    else if (p.ri == 6 && p.ci == 21)return true;
    else if (p.ri == 8 && p.ci == 22)return true;
    else if (p.ri == 12 && p.ci == 17)return true;
    else if (p.ri == 13 && p.ci == 15)return true;
    else if (p.ri == 12 && p.ci == 8)return true;
    else if (p.ri == 13 && p.ci == 6)return true;
    else if (p.ri == 8 && p.ci ==2)return true;
    else return false;
}
void Ludo::Play2(sf::RenderWindow& window) {
    sf::Texture tex;
    B->load2();
    draw_board_pieces(window);
    DisplayTurnChange2(window, Ps[turn]);
    window.display();
    // Position S;
    bool check;
    while (true)
    {
        cout << (dice_val = dice_roll(window));
       

        do {
            do {
                P = selectpiece(window);
            } while (!islegalSource(Ps[turn], P));
            check = B->getPieceat(P)->legalmove(P, dice_val);
            if (!check && pieces_in_h() == 4)
            {
                cout << (dice_val = dice_roll(window));
                turnChange();
                if (turn == 1 || turn ==4) {
                    turnChange(); turnChange();
                        
                }
               
               
            }
        } while (!check);//(B->getPieceat(P).);
        if (home_pressed() == 1)
        {
            dice_val = 0;
        }
        int des = (index_val(P) + dice_val) % 89;
        DisplayTurnChange2(window, Ps[turn]);
        Position D = actualpos_val(des);
        set_pos(B->Move(P, D, *DB, isstop_pos(D)), D);
        if (dice_val != 0 && dice_val != 6) {
            turnChange();
            if (turn == 1 || turn == 4) {
                turnChange(); turnChange();
            }
        }
        draw_board_pieces(window);
        DisplayTurnChange2(window, Ps[turn]);
        window.display();
    }
}
void Ludo::Play4(sf::RenderWindow& window) {
    sf::Texture tex;
    B->load4();
    draw_board_pieces(window);
    DisplayTurnChange4(window, Ps[turn]);
    window.display();
    // Position S;
    bool check;
    while (true)
    {
        cout << (dice_val = dice_roll(window));

        do {
            do {
                P = selectpiece(window);
            } while (!islegalSource(Ps[turn], P));
            check = B->getPieceat(P)->legalmove(P, dice_val);
            if (!check && pieces_in_h() == 4)
            {
                cout << (dice_val = dice_roll(window));
                turnChange();
                if (turn == 1 || turn == 4) {
                    turnChange();
                }
                draw_board_pieces(window);
                DisplayTurnChange4(window, Ps[turn]);
                window.display();
            }
        } while (!check);//(B->getPieceat(P).);
        if (home_pressed() == 1)
        {
            dice_val = 0;
        }
        int des = (index_val(P) + dice_val) % 89;
        DisplayTurnChange4(window, Ps[turn]);
        Position D = actualpos_val(des);
        set_pos(B->Move(P, D, *DB, isstop_pos(D)), D);
        if (dice_val != 0 && dice_val != 6) {
            turnChange();
            if (turn == 1 || turn == 4) {
                turnChange();
            }
        }
        draw_board_pieces(window);
        DisplayTurnChange4(window, Ps[turn]);
        window.display();
    }
}

void Ludo::Play(sf::RenderWindow& window) {
    sf::Texture tex;
   int g=0,r=0,o=0,m=0,b=0,y=0;
    draw_board_pieces(window);
    DisplayTurnChange(window, Ps[turn]);
    window.display();
   // Position S;
    bool check;
    while (true)
    {
        cout << (dice_val =  dice_roll(window));     
        do {
            do {
                P = selectpiece(window);
 
            } while (!islegalSource(Ps[turn], P));
             check = B->getPieceat(P)->legalmove(P, dice_val);
             if (!check && (pieces_in_h() == 4||g==4||r==4||o==4||m==4||b==4||y==4))
             {
                 cout << (dice_val = dice_roll(window));                 
                 turnChange();
                 draw_board_pieces(window);
                 DisplayTurnChange(window, Ps[turn]);
                 window.display();
             }
        } while (!check);//(B->getPieceat(P).);
        if (home_pressed()==1)
        {
            dice_val = 0;
        }
        int des = (index_val(P) + dice_val) % 89;
        DisplayTurnChange(window, Ps[turn]);
        Position D = actualpos_val(des);
        if(D.ri==7 && D.ci==6)g++;else if(D.ri==6 && D.ci==7)r++;
        else if(D.ri==6 && D.ci==16)o++;else if(D.ri==7 && D.ci==17)m++;
        else if(D.ri==8 && D.ci==16)b++;else if(D.ri==8 && D.ci==7)y++;
        set_pos(B->Move(P, D,*DB,isstop_pos(D)), D);
       if(dice_val!=0 && dice_val!=6)
          turnChange();
       draw_board_pieces(window);
       DisplayTurnChange(window, Ps[turn]);
       window.display();
    }
}



int Ludo::index_val(Position P)
{
    if (((P.ri == 1 && P.ci == 1) || (P.ri == 1 && P.ci == 4) || (P.ri == 4 && P.ci == 1) || (P.ri == 4 && P.ci == 4)))
        return 0;
    //   RED0
    else if (((P.ri == 1 && P.ci == 10) || (P.ri == 1 && P.ci == 13) || (P.ri == 4 && P.ci == 10) || (P.ri == 4 && P.ci == 13)))
        return 13;
    // Purple
    else if (((P.ri == 1 && P.ci == 19) || (P.ri == 1 && P.ci == 22) || (P.ri == 4 && P.ci == 19) || (P.ri == 4 && P.ci == 22)))
        return 32;
    //   Blue
    else if (((P.ri == 10 && P.ci == 19) || (P.ri == 10 && P.ci == 22) || (P.ri == 13 && P.ci == 19) || (P.ri == 13 && P.ci == 22)))
        return 45;
    //		Light_Blue
    else if (((P.ri == 10 && P.ci == 10) || (P.ri == 10 && P.ci == 13) || (P.ri == 13 && P.ci == 10) || (P.ri == 13 && P.ci == 13)))
        return 58;
    //	RED
    else if (((P.ri == 10 && P.ci == 1) || (P.ri == 10 && P.ci == 4) || (P.ri == 13 && P.ci == 1) || (P.ri == 13 && P.ci == 4)))
        return 77;
    if (P.ri == 6 && P.ci == 1)return 0;
    else if (P.ri == 6 && P.ci == 2) return 1;
    else if (P.ri == 6 && P.ci == 3) return 2;
    else if (P.ri == 6 && P.ci == 4) return 3;
    else if (P.ri == 6 && P.ci == 5) return 4;
    else if (P.ri == 5 && P.ci == 6) return 5;
    else if (P.ri == 4 && P.ci == 6) return 6;
    else if (P.ri == 3 && P.ci == 6) return 7;
    else if (P.ri == 2 && P.ci == 6) return 8;
    else if (P.ri == 1 && P.ci == 6)  return 9;
    else if (P.ri == 0 && P.ci == 6) return 10;
    else if (P.ri == 0 && P.ci == 7) return 11;
    else if (P.ri == 0 && P.ci == 8) return 12;
    else if (P.ri == 1 && P.ci == 8)return 13;
    else if (P.ri == 2 && P.ci == 8)return 14;
    else if (P.ri == 3 && P.ci == 8)return 15;
    else if (P.ri == 4 && P.ci == 8)return 16;
    else if (P.ri == 5 && P.ci == 8)return 17;
    else if (P.ri == 6 && P.ci == 9)return 18;
    else if (P.ri == 6 && P.ci == 10)return 19;
    else if (P.ri == 6 && P.ci == 11)return 20;
    else if (P.ri == 6 && P.ci == 12)return 21;
    else if (P.ri == 6 && P.ci == 13)return 22;
    else if (P.ri == 6 && P.ci == 14)return 23;
    else if (P.ri == 5 && P.ci == 15) return 24;
    else if (P.ri == 4 && P.ci == 15) return 25;
    else if (P.ri == 3 && P.ci == 15) return 26;
    else if (P.ri == 2 && P.ci == 15)return 27;
    else if (P.ri == 1 && P.ci == 15) return 28;
    else if (P.ri == 0 && P.ci == 15)return 29;
    else if (P.ri == 0 && P.ci == 16) return 30;
    else if (P.ri == 0 && P.ci == 17) return 31;
    else if (P.ri == 1 && P.ci == 17) return 32;
    else if (P.ri == 2 && P.ci == 17) return 33;
    else if (P.ri == 3 && P.ci == 17) return 34;
    else if (P.ri == 4 && P.ci == 17) return 35; 
    else if (P.ri == 5 && P.ci == 17) return 36;
    else if (P.ri == 6 && P.ci == 18) return 37;
    else if (P.ri == 6 && P.ci == 19) return 38;
    else if (P.ri == 6 && P.ci == 20) return 39;
    else if (P.ri == 6 && P.ci == 21) return 40;
    else if (P.ri == 6 && P.ci == 22) return 41;
    else if (P.ri == 6 && P.ci == 23) return 42;
    else if (P.ri == 7 && P.ci == 23) return 43;
    else if (P.ri == 8 && P.ci == 23) return 44;
    else if (P.ri == 8 && P.ci == 22) return 45;
    else if (P.ri == 8 && P.ci == 21) return 46;
    else if (P.ri == 8 && P.ci == 19) return 48;
    else if (P.ri == 8 && P.ci == 18) return 49;
    else if (P.ri == 9 && P.ci == 17) return 50;
    else if (P.ri == 10 && P.ci == 17) return 51;
    else if (P.ri == 11 && P.ci == 17) return 52;
    else if (P.ri == 12 && P.ci == 17) return 53;
    else if (P.ri == 13 && P.ci == 17) return 54;
    else if (P.ri == 14 && P.ci == 17) return 55;
    else if (P.ri == 14 && P.ci == 16) return 56;
    else if (P.ri == 14 && P.ci == 15) return 57;
    else if (P.ri == 13 && P.ci == 15) return 58;
    else if (P.ri == 12 && P.ci == 15)return 59;
    else if (P.ri == 11 && P.ci == 15) return 60;
    else if (P.ri == 10 && P.ci == 15)return 61;
    else if (P.ri == 9 && P.ci == 15)return 62;
    else if (P.ri == 8 && P.ci == 14)return 63;
    else if (P.ri == 8 && P.ci == 13) return 64;
    else if (P.ri == 8 && P.ci == 12)return 65;
    else if (P.ri == 8 && P.ci == 11) return 66;
    else if (P.ri == 8 && P.ci == 10) return 67;
    else if (P.ri == 8 && P.ci == 9) return 68;
    else if (P.ri == 9 && P.ci == 8) return 69;
    else if (P.ri == 10 && P.ci == 8)return 70;
    else if (P.ri == 11 && P.ci == 8) return 71;
    else if (P.ri == 12 && P.ci == 8)return 72;
    else if (P.ri == 13 && P.ci == 8) return 73;
    else if (P.ri == 14 && P.ci == 8)return 74;
    else if (P.ri == 14 && P.ci == 7)return 75;
    else if (P.ri == 14 && P.ci == 6) return 76;
    else if (P.ri == 13 && P.ci == 6) return 77;
    else if (P.ri == 12 && P.ci == 6) return 78;
    else if (P.ri == 11 && P.ci == 6) return 79;
    else if (P.ri == 10 && P.ci == 6) return 80;
    else if (P.ri == 9 && P.ci == 6) return 81;
    else if (P.ri == 8 && P.ci == 5)return 82;
    else if (P.ri == 8 && P.ci == 4) return 83;
    else if (P.ri == 8 && P.ci == 3)return 84;
    else if (P.ri == 8 && P.ci == 2) return 85;
    else if (P.ri == 8 && P.ci == 1) return 86;
    else if (P.ri == 8 && P.ci == 0)return 87;
    else if (P.ri == 7 && P.ci == 0)return 88;
    else if (P.ri == 6 && P.ci == 0)return 89;
    //Light_blue_special_move
    else if (P.ri == 7 && P.ci == 1) { return 0; }
    else if (P.ri == 7 && P.ci == 2) { return 1; }
    else if (P.ri == 7 && P.ci == 3) { return 2; }
    else if (P.ri == 7 && P.ci == 4) { return 3; }
    else if (P.ri == 7 && P.ci == 5) { return 4; }
    else if (P.ri == 7 && P.ci == 6) { return 5; }
    //
    //Red_special_move
    else if (P.ri == 0 && P.ci == 7) { return 11; }
    else if (P.ri == 1 && P.ci == 7) { return 12; }
    else if (P.ri == 2 && P.ci == 7) { return 13; }
    else if (P.ri == 3 && P.ci == 7) { return 14; }
    else if (P.ri == 4 && P.ci == 7) { return 15; }
    else if (P.ri == 5 && P.ci == 7) { return 16; }
    else if (P.ri == 6 && P.ci == 7) { return 17; }
    //
    //Green_special_move
    else if (P.ci == 16 && P.ri <= 6)
    {
        switch (P.ri)
        {
        case(0):return 30;
        case(1):return 31;
        case(2):return 32;
        case(3):return 33;
        case(4):return 34;
        case(5):return 35;
        case(6):return 36;
        }
        }
    /*else if (P.ri == 0 && P.ci == 16) { return 30; }
    else if (P.ri == 1 && P.ci == 16) { return 31; }
    else if (P.ri == 2 && P.ci == 16) { return 32; }
    else if (P.ri == 3 && P.ci == 16) { return 33; }
    else if (P.ri == 4 && P.ci == 16) { return 34; }
    else if (P.ri == 5 && P.ci == 16) { return 35; }
    else if (P.ri == 6 && P.ci == 16) { return 36; }*/
    //Purple_special_move
    else if (P.ri == 14 && P.ci == 7) { return 75; }
    else if (P.ri == 13 && P.ci == 7) { return 76; }
    else if (P.ri == 12 && P.ci == 7) { return 77; }
    else if (P.ri == 11 && P.ci == 7) { return 78; }
    else if (P.ri == 10 && P.ci == 7) { return 79; }
    else if (P.ri == 9 && P.ci == 7) { return 80; }
    else if (P.ri == 8 && P.ci == 7) { return 81; }

    //
   // Yellow_special_move
    else if (P.ri == 7)
    {
        switch (P.ci)
        {
        case(23):return 43;
        case(22):return 44;
        case(21):return 45;
        case(20):return 46;
        case(19):return 47;
        case(18):return 48;
        case(17):return 49;
        }
    }
    /* else if (P.ri == 7 && P.ci == 23) { return 43; }
     else if (P.ri == 7 && P.ci == 22) { return 44; }
     else if (P.ri == 7 && P.ci == 21) { return 45; }
     else if (P.ri == 7 && P.ci == 20) { return 46; }
     else if (P.ri == 7 && P.ci == 19) { return 47; }
     else if (P.ri == 7 && P.ci == 18) { return 48; }*/
     //
     //blue special move 
    else if (P.ci == 16)
    {
        switch (P.ri)
        {
        case(14):return 56;
        case(13):return 57;
        case(12):return 58;
        case(11):return 59;
        case(10):return 60;
        case(9):return 61;
        case(8):return 62;
        }
    }
    /* else if (P.ri == 14 && P.ci == 16) { return 56; }
     else if (P.ri == 13 && P.ci == 16) { return 57; }
     else if (P.ri == 12 && P.ci == 16) { return 58; }
     else if (P.ri == 11 && P.ci == 16) { return 59; }
     else if (P.ri == 10 && P.ci == 16) { return 60; }
     else if (P.ri == 9 && P.ci == 16) { return 61; }*/
     //


}


Position& Ludo::Pos_val(int a)
{
    Position P;
    switch (a)
    {
    case 0:
        P.ri = 6;
        P.ci = 1;
        return P;
    case 1:
        P.ri = 6;
        P.ci = 2;
        return P;
    case 2:
        P.ri = 6;
        P.ci = 3;
        return P;
    case 3:
        P.ri = 6;
        P.ci = 4;
        return P;
    case 4:
        P.ri = 6;
        P.ci = 5;
        return P;
    case 5:
        P.ri = 5;
        P.ci = 6;
        return P;
    case 6:
        P.ri = 4;
        P.ci = 6;
        return P;
    case 7:
        P.ri = 3;
        P.ci = 6;
        return P;
    case 8:
        P.ri = 2;
        P.ci = 6;
        return P;
    case 9:
        P.ri = 1;
        P.ci = 6;
        return P;
    case 10:
        P.ri = 0;
        P.ci = 6;
        return P;
    case 11:
        P.ri = 0;
        P.ci = 7;
        return P;
    case 12:
        P.ri = 0;
        P.ci = 8;
        return P;
    case 13:
        P.ri = 1;
        P.ci = 8;
        return P;
    case 14:
        P.ri = 2;
        P.ci = 8;
        return P;
    case 15:
        P.ri = 3;
        P.ci = 8;
        return P;
    case 16:
        P.ri = 4;
        P.ci = 8;
        return P;
    case 17:
        P.ri = 5;
        P.ci = 8;
        return P;
    case 18:
        P.ri = 6;
        P.ci = 9;
        return P;
    case 19:
        P.ri = 6;
        P.ci = 10;
        return P;
    case 20:
        P.ri = 6;
        P.ci = 11;
        return P;
    case 21:
        P.ri = 6;
        P.ci = 12;
        return P;
    case 22:
        P.ri = 6;
        P.ci = 13;
        return P;
    case 23:
        P.ri = 6;
        P.ci = 14;
        return P;
    case 24:
        P.ri = 5;
        P.ci = 15;
        return P;
    case 25:
        P.ri = 4;
        P.ci = 15;
        return P;
    case 26:
        P.ri = 3;
        P.ci = 15;
        return P;
    case 27:
        P.ri = 2;
        P.ci = 15;
        return P;
    case 28:
        P.ri = 1;
        P.ci = 15;
        return P;
    case 29:
        P.ri = 0;
        P.ci = 15;
        return P;
    case 30:
        P.ri = 0;
        P.ci = 16;
        return P;
    case 31:
        P.ri = 0;
        P.ci = 17;
        return P;
    case 32:
        P.ri = 1;
        P.ci = 17;
        return P;
    case 33:
        P.ri = 2;
        P.ci = 17;
        return P;
    case 34:
        P.ri = 3;
        P.ci = 17;
        return P;
    case 35:
        P.ri = 4;
        P.ci = 17;
        return P;
    case 36:
        P.ri = 5;
        P.ci = 17;
        return P;
    case 37:
        P.ri = 6;
        P.ci = 18;
        return P;
    case 38:
        P.ri = 6;
        P.ci = 19;
        return P;
    case 39:
        P.ri = 6;
        P.ci = 20;
        return P;
    case 40:
        P.ri = 6;
        P.ci = 21;
        return P;
    case 41:
        P.ri = 6;
        P.ci = 22;
        return P;
    case 42:
        P.ri = 6;
        P.ci = 23;
        return P;
    case 43:
        P.ri = 7;
        P.ci = 23;
        return P;
    case 44:
        P.ri = 8;
        P.ci = 23;
        return P;
    case 45:
        P.ri = 8;
        P.ci = 22;
        return P;
    case 46:
        P.ri = 8;
        P.ci = 21;
        return P;
    case 47:
        P.ri = 8;
        P.ci = 20;
        return P;
    case 48:
        P.ri = 8;
        P.ci = 19;
        return P;
    case 49:
        P.ri = 8;
        P.ci = 18;
        return P;
    case 50:
        P.ri = 9;
        P.ci = 17;
        return P;
    case 51:
        P.ri = 10;
        P.ci = 17;
        return P;
    case 52:
        P.ri = 11;
        P.ci = 17;
        return P;
    case 53:
        P.ri = 12;
        P.ci = 17;
        return P;
    case 54:
        P.ri = 13;
        P.ci = 17;
        return P;
    case 55:
        P.ri = 14;
        P.ci = 17;
        return P;
    case 56:
        P.ri = 14;
        P.ci = 16;
        return P;
    case 57:
        P.ri = 14;
        P.ci = 15;
        return P;
    case 58:
        P.ri = 13;
        P.ci = 15;
        return P;
    case 59:
        P.ri = 12;
        P.ci = 15;
        return P;
    case 60:
        P.ri = 11;
        P.ci = 15;
        return P;
    case 61:
        P.ri = 10;
        P.ci = 15;
        return P;
    case 62:
        P.ri = 9;
        P.ci = 15;
        return P;
    case 63:
        P.ri = 8;
        P.ci = 14;
        return P;
    case 64:
        P.ri = 8;
        P.ci = 13;
        return P;
    case 65:
        P.ri = 8;
        P.ci = 12;
        return P;
    case 66:
        P.ri = 8;
        P.ci = 11;
        return P;
    case 67:
        P.ri = 8;
        P.ci = 10;
        return P;
    case 68:
        P.ri = 8;
        P.ci = 9;
        return P;
    case 69:
        P.ri = 9;
        P.ci = 8;
        return P;
    case 70:
        P.ri = 10;
        P.ci = 8;
        return P;
    case 71:
        P.ri = 11;
        P.ci = 8;
        return P;
    case 72:
        P.ri = 12;
        P.ci = 8;
        return P;
    case 73:
        P.ri = 13;
        P.ci = 8;
        return P;
    case 74:
        P.ri = 14;
        P.ci = 8;
        return P;
    case 75:
        P.ri = 14;
        P.ci = 7;
        return P;
    case 76:
        P.ri = 14;
        P.ci = 6;
        return P;
    case 77:
        P.ri = 13;
        P.ci = 6;
        return P;
    case 78:
        P.ri = 12;
        P.ci = 6;
        return P;
    case 79:
        P.ri = 11;
        P.ci = 6;
        return P;
    case 80:
        P.ri = 10;
        P.ci = 6;
        return P;
    case 81:
        P.ri = 9;
        P.ci = 6;
        return P;
    case 82:
        P.ri = 8;
        P.ci = 5;
        return P;
    case 83:
        P.ri = 8;
        P.ci = 4;
        return P;
    case 84:
        P.ri = 8;
        P.ci = 3;
        return P;
    case 85:
        P.ri = 8;
        P.ci = 2;
        return P;
    case 86:
        P.ri = 8;
        P.ci = 1;
        return P;
    case 87:
        P.ri = 8;
        P.ci = 0;
        return P;
    case 88:
        P.ri = 7;
        P.ci = 0;
        return P;
    case 89:
        P.ri = 6;
        P.ci = 0;
        return P;
    }
    if (a > 89)
    {
        a = a % 89;
        return Pos_val(a);
    }

}
