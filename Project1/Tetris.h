#pragma once
#include <iostream>

//#include "Board.h"
//#include "Block.h"

//#define W		12
//#define H		24
//#define WALL	"¢Æ¢Æ"
//#define SPACE	"  "
//#define BLOCK	"¤±"

//enum TetrisType {
//	WALL = 0,
//	SPACE = 1,
//	BLOCK = 2
//};

class Tetris
{
private:
	/*short backBufferBoard[H][W];
	short board[H][W];*/
	//std::string map[H][W];

public:
	Tetris();

	//void PrintBoard();
	//void Set(auto block);
	//void CopyBuffer();
	void mainloop();
	

};

