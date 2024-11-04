#include "Board.h"
#include "Block.h"
//#include "Tetris.h"


Board::Board()
{
	BoardInit();
}

void Board::BoardInit()
{
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (i == 0 || i == H - 1) backBufferBoard[i][j] = BoardType::WALL;	//상단 테두리 & 하단 테두리
			else if (j == 0) backBufferBoard[i][j] = BoardType::WALL;			//좌측 테두리
			else if (j == W - 1) backBufferBoard[i][j] = BoardType::WALL;		//우측 테두리
			else backBufferBoard[i][j] = BoardType::SPACE;						//빈 공간
		}
	}
}

void Board::PrintBoard()
{
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (board[i][j] == BoardType::WALL) {
				std::cout << "▒▒";
			}
			else if (board[i][j] == BoardType::SPACE) {
				std::cout << "  ";
			}
			else if (board[i][j] == BoardType::BLOCK) {
				std::cout << "ㅁ";
			}

		}
		std::cout << std::endl;
	}
}

void Board::Set(Block* block)
{
	int x = block->GetX();
	int y = block->GetY();
	short** B = block->PutBlock();
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (i + x != 0) {
				backBufferBoard[i + x][j + y] = B[i][j];
			}
		}
	}
}

void Board::CopyBuffer()
{
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			board[i][j] = backBufferBoard[i][j];
		}
	}
}
