#include "Common.h"

#include "Block.h"

std::random_device rd{};
std::default_random_engine dre{rd()};
std::uniform_int_distribution RW{ 1,11 };
std::uniform_int_distribution RB{ 1,7 };

class Board;

Block::Block()
{
	SelectBlock = new short* [4];
	for (int i = 0; i < 4; ++i) {
		SelectBlock[i] = new short[4];
	}
	SetRandomBlock();
	SetBlockXY(0,4);
}

Block::~Block()
{
	for (int i = 0; i < 4; ++i) {
		delete[] SelectBlock[i];
	}
	delete[] SelectBlock;
}

void Block::SetRandomBlock()	//블럭 랜덤 고르기
{
	int R = 1;//RB(rd);
	if (R == 1) {
		CopyBlock(BlockType::blockT1);
	}
	else if (R == 2) {
		CopyBlock(BlockType::blockT2);

	}
	else if (R == 3) {
		CopyBlock(BlockType::blockT3);

	}
	else if (R == 4) {
		CopyBlock(BlockType::blockT4);

	}
	else if (R == 5) {
		CopyBlock(BlockType::blockT5);
	
	}
	else if (R == 6) {
		CopyBlock(BlockType::blockT6);
	
	}
	else if (R == 7) {
		CopyBlock(BlockType::blockT7);

	}
}

void Block::SetBlockXY(float x, float y)	//위치변화
{
	Y = y;
	X = x;
}

void Block::CopyBlock(short bl[4][4])
{
	for (int i = 0; i < 4; ++i) {
		
		memcpy(SelectBlock[i], bl[i], 4 * sizeof(short)); 
		/*for (int j = 0; j < 4; ++j) {
			SelectBlock[i][j] = bl[i][j];
		}*/
	}
}

float Block::GetX()
{
	return this->X;
}

float Block::GetY()
{
	return this->Y;
}

short** Block::PutBlock()
{
	return this->SelectBlock;
}

void Block::RotateL()
{
	short tempB[4][4]{};
	for (int i = 0; i < 4; ++i) {
		memcpy(tempB[i], SelectBlock[i], 4 * sizeof(short));
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			SelectBlock[i][j] = tempB[j][3 - i];
		}
	}
}

void Block::RotateR()
{
	short tempB[4][4]{};
	for (int i = 0; i < 4; ++i) {
		memcpy(tempB[i], SelectBlock[i], 4 * sizeof(short));
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			SelectBlock[i][3 - j] = tempB[j][i];
		}
	}
}





