#include "Common.h"

#include "Tetris.h"
#include "Board.h"
#include "Block.h"


int main() {
	Tetris tet;
	int x{}, y{};
	
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = false; // Ŀ���� ������ �ʰ� ����
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);

	tet.mainloop();

}
