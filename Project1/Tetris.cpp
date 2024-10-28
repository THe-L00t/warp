#include "Tetris.h"
#include "Block.h"


Tetris::Tetris() {
	Tetris::BoardInit();
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
		//블럭을 생성함
		//블럭이 내려옴
		//한 줄을 판단함
		//처리
		system("cls");
		PrintBoard();
	}
}

void Tetris::randomblock() {

}