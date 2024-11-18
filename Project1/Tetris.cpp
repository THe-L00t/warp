#include "Common.h"

#include "Tetris.h"
#include "Board.h"
#include "Block.h"
#include "GameTimer.h"



Tetris::Tetris() {
	//CopyBuffer();
}


void Tetris::mainloop() {
	GameTimer gt;
	Board Base;
	Block* b = new Block;
	Block* next = new Block;
	float speed{ 1 };
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
		b->SetBlockXY(speed * gt.elapsedTime, 0);
		if (_kbhit()) { b->MoveBlock(); }
		gt.Update();
		//std::this_thread::sleep_for(std::chrono::milliseconds(16));
		

	}
	delete b;
}
