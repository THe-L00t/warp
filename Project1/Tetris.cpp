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
		//���� ������
		//�� ���� �Ǵ���
		//ó��
	}
	delete b;
}
