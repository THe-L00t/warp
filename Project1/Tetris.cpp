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
	float prevX, prevY, x, y;
	while (true) {
		prevX = b->GetX();
		prevY = b->GetY();
		x = prevX;
		y = prevY;

		gt.Update();
		Base.Remove(b);
		if (_kbhit()) { 
			int input{ 0 };
			input = _getch();
			if (input == 224) {
				input = _getch();
			}
			if (input == UP) {
				b->RotateL();
				if (Base.IsCollision(b)) {
					//b->SetBlockXY(prevX, prevY);
					b->RotateR();
				}
			}
			else if (input == DOWN) {
				x += 1;
			}
			else if (input == LEFT) {
				y -= 1;
				
			}
			else if (input == RIGHT) {
				y += 1;
			}
			b->SetBlockXY(x, y);
			if (Base.IsCollision(b)) {
				b->SetBlockXY(prevX, prevY);
			}
		}
		b->SetBlockXY(b->GetX() + speed * gt.elapsedTime, b->GetY());
		if (Base.IsCollision(b)) {
			//Base.RememberBlock(b);
			b->SetBlockXY(prevX, prevY);
			Base.Set(b);
			delete b;
			b = new Block;
		}
		Base.FullBlock();
		Base.Set(b);
		//b->RotateL();
		Base.MakeBuffer();
		Base.CopyBuffer();
		//보드에 블럭 저장
		Base.PrintBoard();
		gotoxy(0, 0);
		
		
		

	}
	delete b;
}
