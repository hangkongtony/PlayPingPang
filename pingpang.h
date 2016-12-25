#pragma once				// 头文件只被编译一次

#include "Board.h"

class pingpang
{
private:
	int x,y;
	int orination;// -2 ,-1 , 1 , 2
	bool GameOver;
public:
	static const int xMax = 39;
	static const int yMax = 19;
	static const int RIGHT_DOWN = 1;
	static const int RIGHT_UP = -1;
	static const int LEFT_UP = -2;
	static const int LEFT_DOWN = 2;
	char arr[xMax+1][yMax+1];

	pingpang(void);
	void setGameOver(bool state){GameOver = state;}
	bool isGameOver(){return GameOver;}
	int getX() const{return x;}
	int getY() const{return y;}
	int getOrination() const{return orination;}
	int setX(int x)
	{
		this->x = x;
		return x;
	}
	int setY(int y)
	{
		this->y = y;
		return y;
	}
	int setOrination(int orination)
	{
		this->orination = orination;
		return orination;
	}
	void printBall(void);
	int getNextOritation(Board& board);
	~pingpang(void);
};

