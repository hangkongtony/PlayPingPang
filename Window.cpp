#include "stdafx.h"
#include "Window.h"
#include "Board.h"
#include "pingpang.h"

#include <iostream>
#include <windows.h>
#include <mutex>
#include <conio.h>

using namespace std;

mutex mute;	//������											    global area
HANDLE  consoleOut = GetStdHandle(STD_OUTPUT_HANDLE);			// ����̨������
COORD POS = {14 , 18};											// board start pointer (x , y)

Window::Window()
{
}

Window::Window(Board& board , pingpang& p)
{
	column = 40;		//40��
	row = 20;			//20��
	b = board;
	ping = p;
}


void Window::start()
{
	drawWindow();
	drawBoard();									//begin another thread
	while(1)
	{
		{
			//lock_guard<mutex> lockk(mute);
			mute.lock();
			playPingpang(ping ,b);
			mute.unlock();
		}	
		Sleep(200);
		if(ping.isGameOver())
			break;
	}
	cout<<"Game Over!"<<endl;
	getchar();
}

	
DWORD WINAPI drawInOtherThread(LPVOID obj)
{
	
	Board* ob = (Board*)obj;
	//POS = {14 , 18};
	POS.X = 14;
	POS.Y = 18;
	ob->drawBoard();
	while(1)
	{
		if(_kbhit())						//�м�������
		{
			//lock_guard<mutex> lockk(mute);
			mute.lock();
			ob->cleanBoard();
			ob->drawNewBoard();
			mute.unlock();
		}	
	//	Sleep(10);   ���������Ѷ�ϵ��
	}
}

void Window::drawBoard()
{
	DWORD threadId;
	HANDLE handle = CreateThread(NULL,0,drawInOtherThread,&b,0,&threadId);			//begin another thread
}


void Window::playPingpang(pingpang& pin ,Board& board)
{
	int nextOri = pin.getNextOritation(board);//�ص�
	//pin.setOrination(nextOri);
	pin.printBall();
}

void Window::drawWindow()
{
	int column = getColumn();
	int row = getRow();
	char win[21][41];
	for(int  i = 1;i<=row;i++)		//row : y
	{
		for(int j  = 1;j<=column;j++)	//column :x
		{
			if(i == 1||i == row||j == 1||j == column)
			{
				win[i][j] = '=';
			}else
			{
				win[i][j] = ' ';
			}
		}
	}
	for(int  i = 1;i<=row;i++)		//row : y
	{
		for(int j  = 1;j<=column;j++)	//column :x
		{
			cout<<win[i][j];
		}
		cout<<endl;
	}
}

Window::~Window(){}