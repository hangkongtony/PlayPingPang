// playPingPang.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include "pingpang.h"
#include "Window.h"
#include "Board.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Board board;
	pingpang p;
	Window win(board , p );
	win.start();
	return 0;
}


