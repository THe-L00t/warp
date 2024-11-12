#include "Board.h"
#include "Block.h"
//#include "Tetris.h"


Board::Board()
{
	BoardInit();
	RuleInit();
}

void Board::BoardInit()
{
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (i == 0) wallBoard[i][j] = BoardType::WALL;	//상단 테두리
			else if (j == 0) { 
				wallBoard[i][j] = BoardType::WALL; 
				ruleBorad[i][j] = BoardType::WALL;
			}		//좌측 테두리
			else if (j == W - 1) {
				wallBoard[i][j] = BoardType::WALL;
				ruleBorad[i][j] = BoardType::WALL;
			}		//우측 테두리
			else if (i == H - 1) {
				wallBoard[i][j] = BoardType::WALL;
				ruleBorad[i][j] = BoardType::WALL;
			}		//하단
			else { 
				wallBoard[i][j] = BoardType::SPACE; 
				ruleBorad[i][j] = BoardType::SPACE;
			}					//빈 공간
		}
	}
}

void Board::RuleInit()
{
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (j == 0) {
				ruleBorad[i][j] = BoardType::WALL;
			}		//좌측 테두리
			else if (j == W - 1) {
				ruleBorad[i][j] = BoardType::WALL;
			}		//우측 테두리
			else if (i == H - 1) {
				ruleBorad[i][j] = BoardType::WALL;
			}		//하단
			else {
				ruleBorad[i][j] = BoardType::SPACE;
			}		//빈 공간
		}
	}
}

void Board::PrintBoard()
{
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (board[i][j] == BoardType::WALL) {
				std::cout << "▒▒";
			}
			else if (board[i][j] == BoardType::SPACE) {
				std::cout << "  ";
			}
			else if (board[i][j] == BoardType::BLOCK) {
				std::cout << "ㅁ";
			}

		}
		std::cout << std::endl;
	}
}

void Board::Set(Block* block)
{
	int x = block->GetX();
	int y = block->GetY();
	short** B = block->PutBlock();
	RuleInit();
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (B[i][j] == BoardType::BLOCK) {
				ruleBorad[i + x][j + y] = B[i][j];
			}
			/*if (i + x != 0) {
				ruleBorad[i + x][j + y] = B[i][j];
			}*/
		}
	}
}

void Board::CopyBuffer()
{
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			board[i][j] = backBufferBoard[i][j];
		}
	}
}

void Board::MakeBuffer()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			backBufferBoard[i][j] = wallBoard[i][j];
		}
	}
	for (int i = 1; i < H-1; i++)
	{
		for (int j = 1; j < W-1; j++)
		{
			backBufferBoard[i][j] = ruleBorad[i][j];
		}
	}
}

bool Board::IsFloor()
{
	bool re{ false };
	for (int i = 1; i < W-1; i++)
	{
		if (ruleBorad[H - 2][i] == BoardType::BLOCK) {
			re = true;
		}

	}
	return re;
}
