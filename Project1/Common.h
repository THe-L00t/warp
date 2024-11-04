#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

inline void GoToXY(int x, int y)
{
	COORD cur;
	cur.X = x;
	cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}