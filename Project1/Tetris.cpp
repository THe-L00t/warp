#include "Tetris.h"
#include "Block.h"


Tetris::Tetris() {
	Tetris::BoardInit();
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

void Tetris::display() {
	//for (int i = 0; i < H; ++i) {
	//	for (int j = 0; j < W; ++j) {
	//		std::cout << map[i][j];
	//	}
	//	std::cout << std::endl;
	//}
	
}

void Tetris::set(Block&& block) {
	


}

void Tetris::mainloop() {
	while (true) {
		system("cls");
		PrintBoard();
		//���� ������
		//���� ������
		//�� ���� �Ǵ���
		//ó��
		system("cls");
		PrintBoard();
	}
}

void Tetris::randomblock() {

}