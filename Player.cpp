#include"Player.h"
Player::Player(string n, P_col _c)
{
	name = n; c = _c;
}
P_col Player::GetColor()
{
	return c;
}
string Player::getname()
{
	return this->name;
}