#include "Common.h"
#include "Tetris.h"
#include "Board.h"
#include "Block.h"

int main() {
	Tetris tet;
	int x{}, y{};

	// 커서 숨기기
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	tet.mainloop();
}
