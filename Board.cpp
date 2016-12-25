#include "stdafx.h"
#include "Board.h"

#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

extern HANDLE  consoleOut;
extern COORD POS; // (14 ,18)

Board::Board()
{
	Boardlen = 10;  // 初始板长度 可以设置难度系数
}

void Board::drawBoard()
{
	SetConsoleCursorPosition(consoleOut , POS);
	setBeginX(POS.X);
	for(int i = 0;i<Boardlen;i++)
	{
		cout<<"=";
	}
}

void Board::drawNewBoard()
{
	char ch = _getch();
	if(ch == 'A' || ch == 'a')				//remove to left
	{

		POS.X--;
		if(POS.X<=1)
		{
			POS.X = 1;
		}
	}else if(ch == 'D'|| ch == 'd')			//remove to right
	{
		POS.X++;
		if(POS.X>=29)
		{
			POS.X = 29;
		}
	}
	drawBoard();
}

bool Board::cleanBoard()
{
	COORD POS = {1 , 18};//x , y
	SetConsoleCursorPosition(consoleOut , POS);
	for(int i = 1;i<=38;i++)
	{
		cout<<" ";
	}
	return true;
}
Board::~Board(void)
{
}
