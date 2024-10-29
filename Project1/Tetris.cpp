#include "Tetris.h"
#include "Board.h"
#include "Block.h"



Tetris::Tetris() {
	//CopyBuffer();
}


void Tetris::mainloop() {
	Board Base;
	Block* b = new Block;
	while (true) {
		system("cls");
		Base.PrintBoard();
		Base.Set(b);
		//블럭이 내려옴
		//한 줄을 판단함
		//처리
		system("cls");
		Base.PrintBoard();
	}
	delete b;
}
