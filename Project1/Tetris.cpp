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
		//���� ������
		//�� ���� �Ǵ���
		//ó��
		system("cls");
		Base.PrintBoard();
	}
	delete b;
}
