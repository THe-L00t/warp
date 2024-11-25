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
	float speed{ 3 };

	while (true) {
		gt.Update();
		Base.Remove(b);
		if (_kbhit()) { b->MoveBlock(); }
		b->SetBlockXY(b->GetX() + speed * gt.elapsedTime, b->GetY());
		Base.Set(b);
		if (Base.IsCollision(b)) {
			//Base.RememberBlock(b);
			delete b;
			b = new Block;
			std::cout << "b" << std::endl;
		}
		//b->RotateL();
		Base.MakeBuffer();
		Base.CopyBuffer();
		//보드에 블럭 저장
		Base.PrintBoard();
		gotoxy(0, 0);
		//Base.Remove(b);
		//Base.Set(b);
		//std::this_thread::sleep_for(std::chrono::milliseconds(16));
		
		

	}
	delete b;
}
