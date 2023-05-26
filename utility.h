#pragma once
#include<iostream>
using namespace std;
enum P_col { LIGHT_BLUE, RED, GREEN, YELLOW, BLUE, PURPLE};
struct Position {
	int ri, ci;
	Position() { this->ri = 0; this->ci = 0; }
	Position(int r, int c) { ri = r, ci = c; }
	Position(const Position& other)
	{
		this->ri = other.ri;
		this->ci = other.ci;
	}
	bool operator==(Position& B)
	{
		if (B.ri == ri && B.ci == ci)
		{
			return true;
		}
		else
			return false;
	}
};