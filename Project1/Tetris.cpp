#include "Tetris.h"
#include "Block.h"


Tetris::Tetris() {
	BoardInit();
	CopyBuffer();
}



void Tetris::BoardInit()
{
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (i == 0 || i == H - 1) board[i][j] = TetrisType::WALL;	//상단 테두리 & 하단 테두리
			else if (j == 0) board[i][j] = TetrisType::WALL;			//좌측 테두리
			else if (j == W - 1) board[i][j] = TetrisType::WALL;		//우측 테두리
			else board[i][j] = TetrisType::SPACE;						//빈 공간
		}
	}
}

void Tetris::PrintBoard()
{
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (board[i][j] == TetrisType::WALL) {
				std::cout << "▒▒";
			}
			else if (board[i][j] == TetrisType::SPACE) {
				std::cout << "  ";
			}
			else if (board[i][j] == TetrisType::BLOCK) {
				std::cout << "ㅁ";
			}
			
		}
		std::cout << std::endl;
	}
}

void Tetris::Set(auto block) {
	int x = block->GetX();
	int y = block->GetY();
	short** B = block->PutBlock();
	for (int i = 0; i <  4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (i + x != 0) {
				board[i + x][j + y] = B[i][j];
			}
		}
	}

}

void Tetris::CopyBuffer()
{
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			backbuffer[i][j] = board[i][j];
		}
	}
}

void Tetris::mainloop() {
	Block* b = new Block;
	while (true) {
		system("cls");
		PrintBoard();
		Set(b);
		//블럭이 내려옴
		//한 줄을 판단함
		//처리
		system("cls");
		PrintBoard();
	}
	delete b;
}
