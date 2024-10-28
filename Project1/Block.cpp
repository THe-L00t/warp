#include "Block.h"
#include "Tetris.h"

std::random_device rd{};
std::default_random_engine dre{rd()};
std::uniform_int_distribution RW{ 1,11 };
std::uniform_int_distribution RB{ 1,7 };

Block::Block()
{
	SelectBlock = new short* [4];
	for (int i = 0; i < 4; ++i) {
		SelectBlock[i] = new short[4];
	}
	SetRandomBlock();
	SetBlockXY(0,0);
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
	int R = RB(rd);
	if (R == 1) {
		SelectBlock[0] = blockT1[0];
		SelectBlock[1] = blockT1[1];
		SelectBlock[2] = blockT1[2];
		SelectBlock[3] = blockT1[3];
	}
	else if (R == 2) {
		SelectBlock[0] = blockT2[0];
		SelectBlock[1] = blockT2[1];
		SelectBlock[2] = blockT2[2];
		SelectBlock[3] = blockT2[3];
	}
	else if (R == 3) {
		SelectBlock[0] = blockT3[0];
		SelectBlock[1] = blockT3[1];
		SelectBlock[2] = blockT3[2];
		SelectBlock[3] = blockT3[3];
	}
	else if (R == 4) {
		SelectBlock[0] = blockT4[0];
		SelectBlock[1] = blockT4[1];
		SelectBlock[2] = blockT4[2];
		SelectBlock[3] = blockT4[3];
	}
	else if (R == 5) {
		SelectBlock[0] = blockT5[0];
		SelectBlock[1] = blockT5[1];
		SelectBlock[2] = blockT5[2];
		SelectBlock[3] = blockT5[3];
	}
	else if (R == 6) {
		SelectBlock[0] = blockT6[0];
		SelectBlock[1] = blockT6[1];
		SelectBlock[2] = blockT6[2];
		SelectBlock[3] = blockT6[3];
	}
	else if (R == 7) {
		SelectBlock[0] = blockT7[0];
		SelectBlock[1] = blockT7[1];
		SelectBlock[2] = blockT7[2];
		SelectBlock[3] = blockT7[3];
	}
}

void Block::SetBlockXY(int x, int y)	//위치변화
{
	Y = 5 + y;
	X = 0 + x;
}

short Block::GetX()
{
	return this->X;
}

short Block::GetY()
{
	return this->Y;
}

short** Block::PutBlock()
{
	return this->SelectBlock;
}

