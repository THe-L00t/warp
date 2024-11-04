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
	short speed{ 1 };
	while (true) {
		Base.Set(b);
		Base.MakeBuffer();
		Base.CopyBuffer();
		Base.PrintBoard();
		gotoxy(0, 0);
		Sleep(500);
		b->SetBlockXY(speed++, 0);

	}
	delete b;
}
