#pragma once
#include <iostream>
#include <random>

#include "Tetris.h"

class Block
{
private:
	short X , Y ;
	short** SelectBlock{};
	short blockT1[4][4] = { { 1, 1, 1, 1},
							{ 1, 2, 2, 1},
							{ 1, 2, 2, 1},
							{ 1, 1, 1, 1} };

	short blockT2[4][4] = { { 1, 1, 1, 1},
							{ 1, 1, 2, 2},
							{ 1, 2, 2, 1},
							{ 1, 1, 1, 1} };

	short blockT3[4][4] = { { 1, 1, 1, 1},
							{ 1, 2, 2, 1},
							{ 1, 1, 2, 2},
							{ 1, 1, 1, 1} };

	short blockT4[4][4] = { { 1, 1, 1, 1},
							{ 1, 1, 1, 2},
							{ 1, 2, 2, 2},
							{ 1, 1, 1, 1} };

	short blockT5[4][4] = { { 1, 1, 1, 1},
							{ 1, 2, 2, 2},
							{ 1, 1, 1, 2},
							{ 1, 1, 1, 1} };

	short blockT6[4][4] = { { 1, 1, 2, 1},
							{ 1, 1, 2, 1},
							{ 1, 1, 2, 1},
							{ 1, 1, 2, 1} };

	short blockT7[4][4] = { { 1, 1, 1, 1},
							{ 1, 1, 2, 1},
							{ 1, 2, 2, 2},
							{ 1, 1, 1, 1} };


public:
	
	Block();
	~Block();
	
	void SetRandomBlock();
	void SetBlockXY(int, int);
	short GetX();
	short GetY();
	short** PutBlock();

};
