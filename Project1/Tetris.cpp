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
		//b->RotateL();
		Base.MakeBuffer();
		Base.CopyBuffer();
		//���忡 �� ����
		if (Base.IsFloor()) {
			delete b;
			b = next;
			next = new Block;
		}
		Base.PrintBoard();
		gotoxy(0, 0);
		Sleep(500);
		b->SetBlockXY(speed, 0);
		if (_kbhit()) { b->MoveBlock(); }
		

	}
	delete b;
}
