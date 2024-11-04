#include "Common.h"

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
		Base.Set(b);
		Base.CopyBuffer();
		Base.PrintBoard();
		GoToXY(0, 0);
		//블럭이 내려옴
		//한 줄을 판단함
		//처리
	}
	delete b;
}
