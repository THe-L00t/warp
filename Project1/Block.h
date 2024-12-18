#pragma once
#include <iostream>
#include <random>

//#include "Tetris.h"
namespace BlockType
{
	inline short blockT1[4][4] = { { 0, 0, 0, 0},
							{ 0, 2, 2, 0},
							{ 0, 2, 2, 0},
							{ 0, 0, 0, 0} };

	inline short blockT2[4][4] = { { 0, 0, 0, 0},
							{ 0, 0, 2, 2},
							{ 0, 2, 2, 0},
							{ 0, 0, 0, 0} };

	inline short blockT3[4][4] = { { 0, 0, 0, 0},
							{ 0, 2, 2, 0},
							{ 0, 0, 2, 2},
							{ 0, 0, 0, 0} };

	inline short blockT4[4][4] = { { 0, 0, 0, 0},
							{ 0, 0, 0, 2},
							{ 0, 2, 2, 2},
							{ 0, 0, 0, 0} };

	inline short blockT5[4][4] = { { 0, 0, 0, 0},
							{ 0, 2, 2, 2},
							{ 0, 0, 0, 2},
							{ 0, 0, 0, 0} };

	inline short blockT6[4][4] = { { 0, 0, 2, 0},
							{ 0, 0, 2, 0},
							{ 0, 0, 2, 0},
							{ 0, 0, 2, 0} };

	inline short blockT7[4][4] = { { 0, 0, 0, 0},
							{ 0, 0, 2, 0},
							{ 0, 2, 2, 2},
							{ 0, 0, 0, 0} };
}

class Block
{
private:
	float X{ 0 }, Y{ 4 };
	short** SelectBlock{};



public:
	
	Block();
	~Block();
	
	void SetRandomBlock();
	void SetBlockXY(float, float);
	void CopyBlock(short bl[4][4]);

	float GetX();
	float GetY();
	short** PutBlock();
	void RotateL();
	void RotateR();


};
