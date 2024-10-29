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
			if (i == 0 || i == H - 1) board[i][j] = BoardType::WALL;	//��� �׵θ� & �ϴ� �׵θ�
			else if (j == 0) board[i][j] = BoardType::WALL;			//���� �׵θ�
			else if (j == W - 1) board[i][j] = BoardType::WALL;		//���� �׵θ�
			else board[i][j] = BoardType::SPACE;						//�� ����
		}
	}
}

void Board::PrintBoard()
{
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (board[i][j] == BoardType::WALL) {
				std::cout << "�Ƣ�";
			}
			else if (board[i][j] == BoardType::SPACE) {
				std::cout << "  ";
			}
			else if (board[i][j] == BoardType::BLOCK) {
				std::cout << "��";
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
				board[i + x][j + y] = B[i][j];
			}
		}
	}
}

void Board::CopyBuffer()
{
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			backbuffer[i][j] = board[i][j];
		}
	}
}
