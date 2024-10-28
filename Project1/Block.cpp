#include "Block.h"
#include "Tetris.h"

std::random_device rd{};
std::default_random_engine dre;
std::uniform_int_distribution RW{ 1,11 };
std::uniform_int_distribution RB{ 1,6 };

Block::Block()
{
	SetRandomBlock();
	SetBlockXY();
}

void Block::SetRandomBlock()
{
	SelectBlock = RB(dre);

}

void Block::SetBlockXY()
{
	Y = RW(dre);
	X = 1;
}

short* Block::PutBlock()
{
	short* arr{};
	for (int i = 0; i < 7; ++i) {
		if(SelectBlock == i) arr = 
	}
	return nullptr;
}

