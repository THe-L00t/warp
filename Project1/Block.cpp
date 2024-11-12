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

void Block::SetBlockXY(int x, int y)	//위치변화
{
	Y = Y + y;
	X = X + x;
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

void Block::RotateL()
{
	short tempB[4][4]{};
	CopyBlock(tempB);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			SelectBlock[i][j] = tempB[j][3 - i];
		}
	}
}

void Block::RotateR()
{
	short tempB[4][4]{};
	CopyBlock(tempB);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			SelectBlock[i][j] = tempB[j][i];
		}
	}
}

void Block::MoveBlock()
{
	int input{0};
	input = _getch();
	if (input == 224) {
		input = _getch();
	}
	if (input == UP) {
		Block::RotateL();
	}
	else if (input == DOWN) {
		//Block::
	}
	else if (input == LEFT) {
		SetBlockXY(0, -1);
	}
	else if (input == RIGHT) {
		SetBlockXY(0, 1);
	}
}



