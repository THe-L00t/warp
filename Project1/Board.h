#pragma once
#include <iostream>

//#include "Block.h"
//#include "Tetris.h"

#define W		12
#define H		24

class Block;

enum BoardType {
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
	void Set(Block* block);
	void CopyBuffer();

};

