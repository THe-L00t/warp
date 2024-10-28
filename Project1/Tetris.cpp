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
			if (i == 0 || i == H - 1) board[i][j] = TetrisType::WALL;	//��� �׵θ� & �ϴ� �׵θ�
			else if (j == 0) board[i][j] = TetrisType::WALL;			//���� �׵θ�
			else if (j == W - 1) board[i][j] = TetrisType::WALL;		//���� �׵θ�
			else board[i][j] = TetrisType::SPACE;						//�� ����
		}
	}
}

void Tetris::PrintBoard()
{
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (board[i][j] == TetrisType::WALL) {
				std::cout << "�Ƣ�";
			}
			else if (board[i][j] == TetrisType::SPACE) {
				std::cout << "  ";
			}
			else if (board[i][j] == TetrisType::BLOCK) {
				std::cout << "��";
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
		//���� ������
		//�� ���� �Ǵ���
		//ó��
		system("cls");
		PrintBoard();
	}
	delete b;
}
