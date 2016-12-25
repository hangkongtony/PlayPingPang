#include "stdafx.h"
#include "pingpang.h"
#include "Board.h"

#include <windows.h>
#include <iostream>
using namespace std;

extern HANDLE  consoleOut;

pingpang::pingpang(void)
{
	x = 16;											// 游戏开始球出发的列
	y = 17;											//游戏开始球出发的层 ， 倒数第三层
	orination = LEFT_UP;							// 出发方向： right up 45
	GameOver = false;
}

int pingpang::getNextOritation(Board& board)
{
	int nowX , nowY ,orination;
	nowX = this->getX();
	nowY = getY();
	orination = getOrination();

	if(orination == RIGHT_DOWN)										//right down 45'
	{
		if(nowY>=17)
		{
			if(nowX>=board.getBeginX()&&nowX<=board.getBeginX()+10)
			{
				setOrination(RIGHT_UP);
				return RIGHT_UP;
			}else
			{
				setGameOver(true);
			}
		}
		else if(nowX>=xMax-1)										 // to left down 45'
		{
			setOrination(LEFT_DOWN);
		}
	}
	else if(orination == RIGHT_UP)									 //rigth up
	{
		if(nowY<=1)													 // to right down 45'
		{
			setOrination(RIGHT_DOWN);
		}else if(nowX>=xMax-1)										 // to left up 45'
		{
			setOrination(LEFT_UP);
		}
	}else if(orination == LEFT_DOWN)								//left down
	{
		if(nowY>=17)
		{
			if(nowX>=board.getBeginX()&&nowX<=board.getBeginX()+10)
			{
				setOrination(LEFT_UP);
				return LEFT_UP;
			}else
			{
				setGameOver(true);
				return 0;
			}
		}
		else if(nowX<=1)										// to right down 45'
		{
			setOrination(RIGHT_DOWN);
		}
	}else if(orination == LEFT_UP)								 // left up
	{
		if(nowY<=1)												// to left down 45'
		{
			setOrination(LEFT_DOWN);
		}else if(nowX<=1)										// to right up 45'
		{
			setOrination(RIGHT_UP);
		}
	}else                                                       // error orination
	{
		cout<<"error!!!!!!!!!!";
		getchar();
		exit(EXIT_FAILURE);
	}
	return getOrination();
}
void pingpang::printBall(void)
{
	int ori = getOrination();
	int x = getX();
	int y = getY();
	COORD POS = {x , y};//x , y
	SetConsoleCursorPosition(consoleOut , POS);
	cout<<' ';											//clean befor ball

	switch(ori)
	{
	case RIGHT_DOWN:setX(x+1);setY(y+1);break;			//right down
	case RIGHT_UP:setX(x+1);setY(y-1);break;			// right up 
	case LEFT_DOWN:setX(x-1);setY(y+1);break;			 // left down
	case LEFT_UP:setX(x-1);setY(y-1);break;				// left up
	default:break;
	}
	x = getX();
	y = getY();
	POS.X = x;
	POS.Y = y;
	SetConsoleCursorPosition(consoleOut , POS);
	cout<<'@';
}
pingpang::~pingpang(void)
{
}
