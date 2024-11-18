#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <thread>

#define UP      72
#define DOWN    80 
#define LEFT    75 
#define RIGHT   77

#define W		12
#define H		24

inline void gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
