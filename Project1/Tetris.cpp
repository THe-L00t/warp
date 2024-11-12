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
	Block* next = new Block;
	short speed{ 1 };
	while (true) {
		Base.Set(b);
		Base.MakeBuffer();
		Base.CopyBuffer();
		if (Base.IsFloor()) {
			b = next;
			delete next;
			next = new Block;
		}
		
		Base.PrintBoard();
		gotoxy(0, 0);
		Sleep(500);
		b->SetBlockXY(speed, 0);
		

	}
	delete b;
}
