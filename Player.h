#pragma once
#include<string>
#include"utility.h"
using namespace std;
class Player
{
protected:
	string name;
	P_col c;
public:
	Player(string n, P_col _c);
	string getname();
	P_col GetColor();
};

