#pragma once
#include "Common.h"

//#include "Block.h"
//#include "Tetris.h"

class Block;

enum BoardType {
	SPACE,
	WALL,
	BLOCK
};

class Board
{
private:
	short backBufferBoard[H][W];
	short board[H][W];
	short wallBoard[H][W];
	short ruleBorad[H][W];

public:
	Board();

	void BoardInit();
	void RuleInit();
	void PrintBoard();
	void Set(Block* block);
	void CopyBuffer();
	void MakeBuffer();
	bool IsFloor();
	void RememberBlock(Block* block);

};

