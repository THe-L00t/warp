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
	short ruleBoard[H][W];
	short rememBoard[H][W];

public:
	Board();

	void BoardInit();
	void RuleInit();
	void PrintBoard();
	void Remove(Block* block);
	void Set(Block* block);
	void CopyBuffer();
	void MakeBuffer();
	bool IsCollision(Block* block);
	void RememberBlock(Block* block);
	bool FullBlock();
	void DownBlock();


};

//캡슐화 가이드 라인

//class
// 상위 클래스 상속을 통해 의존성 없애기 
/*
public:
	생성자()
	생성자(i)
	Get
	Set
	Print
	Remember
	IsCollision


private:
	board
 
 */