#pragma once 

#include "Board.h"
#include "pingpang.h"

class Window
{
private:
	int column , row;
	Board b ;
	pingpang ping;
public:
	Window();
	Window(Board& board , pingpang& p);
	int getColumn(){return column;}
	int getRow(){return row;}
	void drawWindow();
	void drawBoard();
	void start();
	void playPingpang(pingpang& pin ,Board& board);
	~Window();
};