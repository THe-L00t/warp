#pragma once
#include <iostream>

#include "Block.h"

enum TetrisType {
	WALL = 0,
	SPACE = 1,
	BLOCK = 2
};

class Board
{
private:
	short board[H][W];
	short backbuffer[H][W];

public:
	Board();

	void BoardInit();
	void PrintBoard();
	void Set(auto block);
	void CopyBuffer();

};

