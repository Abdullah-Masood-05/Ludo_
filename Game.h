#pragma once
#include"Piece.h"
#include"Board.h"
class Player;
#include<SFML/Graphics.hpp>
#include<vector>
class Ludo
{
	Position P;
	int turn;
	Player* Ps[6];
	Board* B;
	Board* DB;
	int dice_val;
public:
	Ludo();
	void Play(sf::RenderWindow&);
	void Play2(sf::RenderWindow&);
	void Play4(sf::RenderWindow&);

	void DisplayTurnChange(sf::RenderWindow& w, Player* p);
	void DisplayTurnChange2(sf::RenderWindow& w, Player* p);
	void DisplayTurnChange4(sf::RenderWindow& w, Player* p);
	void animation_dice(sf::RenderWindow& w, int r, int c);
	void display_dice(sf::RenderWindow& w, int value, int r, int c);

	Position selectpiece(sf::RenderWindow& window);
	bool islegalSource(Player* AP, Position S_P);
	void turnChange();
	void load_board(sf::RenderWindow& window);
	Position getRowColbyLeftClick(sf::RenderWindow& W);
	void draw_board_pieces(sf::RenderWindow&);
	int index_val(Position P);
	Position& Pos_val(int a);
	int dice_roll(sf::RenderWindow&);
	bool h_pressed(Position P);
	bool light_blue_home_p(Position, P_col);
	Position& light_blue_special_move(int);
	bool red_home_p(Position, P_col);
	Position& red_special_move(int);
	bool green_home_p(Position, P_col);
	Position& green_special_move(int);
	bool yellow_home_p(Position, P_col);
	Position& yellow_special_move(int);
	bool blue_home_p(Position, P_col);
	Position& blue_special_move(int);
	bool purple_home_p(Position, P_col);
	Position& purple_special_move(int);

	// Home Checking
	int light_blue_all_h();
	int red_all_h();
	int green_all_h();
	int yellow_all_h();
	int blue_all_h();
	int purple_all_h();

	Position& actualpos_val(int);
	int pieces_in_h();
	bool home_pressed();
	bool isstop_pos(Position);

	void set_pos(Piece* &p,Position& );
};

