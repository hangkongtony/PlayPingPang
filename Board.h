#pragma once

class Board
{
public:
	Board();
	void drawBoard();
	void drawNewBoard();
	bool cleanBoard();
	int getLen(){return Boardlen;}
	int getBeginX(){return beginX;}
	void setBeginX(int x){beginX = x;}
	~Board(void);
private:
	int Boardlen;
	int beginX;
};

