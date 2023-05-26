#include "Board.h"
#include<iostream>
#include<fstream>
#pragma once
#include"Light_Blue.h"
#include"Green.h"
#include"Blue.h"
#include"Purple.h"
#include"Red.h"
#include"Yellow.h"

using namespace std;


Board::Board()
{
	ps = new Piece * *[15] {};
	for (int i = 0; i < 15; i++)
	{
		ps[i] = new Piece * [24] {};
	}
	Position P;
	for (int r = 0; r < 15; r++)
	{
		for (int c = 0; c < 24; c++)
		{
								//	Purple	
			if ((r == 1 && c == 1) || (r == 1 && c == 4) || (r == 4 && c == 1) || (r == 4 && c == 4))
			{
				P.ri = r; P.ci = c;
				ps[r][c] = new Light_Blue(P, LIGHT_BLUE, this);
			}
			//   RED
			else if ((r == 1 && c == 10) || (r == 1 && c == 13) || (r == 4 && c == 10) || (r == 4 && c == 13))
			{
				P.ri = r; P.ci = c;
				ps[r][c] = new Red(P, RED, this);
			}
			// Purple
			else if ((r == 1 && c == 19) || (r == 1 && c == 22) || (r == 4 && c == 19) || (r == 4 && c == 22))
			{
				P.ri = r; P.ci = c;
				ps[r][c] = new Green(P,GREEN, this);
			}
			//   Blue
			else if ((r == 10 && c == 19) || (r == 10 && c == 22) || (r == 13 && c == 19) || (r == 13 && c == 22))
			{
				P.ri = r; P.ci = c;
				ps[r][c] = new	Yellow(P, YELLOW, this);
			}
			//		Light_Blue
			else if ((r == 10 && c == 10) || (r == 10 && c == 13) || (r == 13 && c == 10) || (r == 13 && c == 13))
			{
				P.ri = r; P.ci = c;
				ps[r][c] = new Blue(P, BLUE, this);
			}
			//	RED
			else if ((r == 10 && c == 1) || (r == 10 && c == 4) || (r == 13 && c == 1) || (r == 13 && c == 4))
			{
				P.ri = r; P.ci = c;
				ps[r][c] = new Purple(P, PURPLE, this);
			}
			else
				ps[r][c] = nullptr;

		}
	}
}
Board::Board(int)
{
	ps = new Piece * *[15] {};
	for (int i = 0; i < 15; i++)
	{
		ps[i] = new Piece * [24] {};
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			ps[i][j] = nullptr;
		}
	}
}
void Board::load4()
{
	ps = new Piece * *[15] {};
	for (int i = 0; i < 15; i++)
	{
		ps[i] = new Piece * [24] {};
	}
	Position P;
	for (int r = 0; r < 15; r++)
	{
		for (int c = 0; c < 24; c++)
		{
			//	Purple	
			if ((r == 1 && c == 1) || (r == 1 && c == 4) || (r == 4 && c == 1) || (r == 4 && c == 4))
			{
				P.ri = r; P.ci = c;
				ps[r][c] = new Light_Blue(P, LIGHT_BLUE, this);
			}
			//   RED
			
			// Purple
			else if ((r == 1 && c == 19) || (r == 1 && c == 22) || (r == 4 && c == 19) || (r == 4 && c == 22))
			{
				P.ri = r; P.ci = c;
				ps[r][c] = new Green(P, GREEN, this);
			}
			//   Blue
			else if ((r == 10 && c == 19) || (r == 10 && c == 22) || (r == 13 && c == 19) || (r == 13 && c == 22))
			{
				P.ri = r; P.ci = c;
				ps[r][c] = new	Yellow(P, YELLOW, this);
			}
			//		Light_Blue
			
			//	RED
			else if ((r == 10 && c == 1) || (r == 10 && c == 4) || (r == 13 && c == 1) || (r == 13 && c == 4))
			{
				P.ri = r; P.ci = c;
				ps[r][c] = new Purple(P, PURPLE, this);
			}
			else
				ps[r][c] = nullptr;

		}
	}
}
void Board::load2()
{
	ps = new Piece * *[15] {};
	for (int i = 0; i < 15; i++)
	{
		ps[i] = new Piece * [24] {};
	}
	Position P;
	for (int r = 0; r < 15; r++)
	{
		for (int c = 0; c < 24; c++)
		{
			//	Purple	
			if ((r == 1 && c == 1) || (r == 1 && c == 4) || (r == 4 && c == 1) || (r == 4 && c == 4))
			{
				P.ri = r; P.ci = c;
				ps[r][c] = new Light_Blue(P, LIGHT_BLUE, this);
			}
			//   RED


			else if ((r == 10 && c == 19) || (r == 10 && c == 22) || (r == 13 && c == 19) || (r == 13 && c == 22))
			{
				P.ri = r; P.ci = c;
				ps[r][c] = new	Yellow(P, YELLOW, this);
			}
			//		Light_Blue

			else
				ps[r][c] = nullptr;

		}
	}
}
Piece*& Board::Move(Position &S_P, Position &D_P,Board & B,bool home)
{
	if (home == true) {
		Piece* p = nullptr;
		B.SetPiece(D_P, this->getPieceat(D_P));
		ps[D_P.ri][D_P.ci] = ps[S_P.ri][S_P.ci];
		if (B.getPieceat(S_P) == nullptr) {
			ps[S_P.ri][S_P.ci] = nullptr;
			return p;
		}
		else
		{
			ps[S_P.ri][S_P.ci] = B.getPieceat(S_P);
			B.SetPiece(S_P, nullptr);
			return p;
		}
	}
	else
	{
		Piece* p = this->getPieceat(D_P);
		ps[D_P.ri][D_P.ci] = ps[S_P.ri][S_P.ci];
		ps[S_P.ri][S_P.ci] = B.getPieceat(S_P);
		B.SetPiece(S_P, nullptr) ;
		return p;
	}
}
Piece* Board::getPieceat(Position& p)const
{
	return ps[p.ri][p.ci];
}
void Board::SetPiece(Position& P, Piece* p)
{
	this->ps[P.ri][P.ci] = p;
}








