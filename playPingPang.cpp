// playPingPang.cpp : �������̨Ӧ�ó������ڵ㡣

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


