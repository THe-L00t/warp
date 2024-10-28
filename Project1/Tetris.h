#pragma once
#include <iostream>

#include "Block.h"

#define W		12
#define H		24
//#define WALL	"¢Æ¢Æ"
//#define SPACE	"  "
//#define BLOCK	"¤±"

enum TetrisType {
	WALL = 0,
	SPACE = 1,
	BLOCK = 2
};

class Tetris
{
private:
	short board[H][W];
	//std::string map[H][W];

public:
	Tetris();

	void BoardInit();
	void PrintBoard();
	void display();
	void set(Block&& block);
	void mainloop();
	void randomblock();

};

