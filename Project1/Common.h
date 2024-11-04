#pragma once
#include <iostream>
#include <Windows.h>

#define W		12
#define H		24

inline void gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
