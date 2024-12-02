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
				ruleBoard[i][j] = BoardType::WALL;
			}		//좌측 테두리
			else if (j == W - 1) {
				wallBoard[i][j] = BoardType::WALL;
				ruleBoard[i][j] = BoardType::WALL;
			}		//우측 테두리
			else if (i == H - 1) {
				wallBoard[i][j] = BoardType::WALL;
				ruleBoard[i][j] = BoardType::WALL;
			}		//하단
			else { 
				wallBoard[i][j] = BoardType::SPACE; 
				ruleBoard[i][j] = BoardType::SPACE;
				rememBoard[i][j] = BoardType::SPACE;
			}					//빈 공간
		}
	}
}

void Board::RuleInit()
{
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (j == 0) {
				ruleBoard[i][j] = BoardType::WALL;
			}		//좌측 테두리
			else if (j == W - 1) {
				ruleBoard[i][j] = BoardType::WALL;
			}		//우측 테두리
			else if (i == H - 1) {
				ruleBoard[i][j] = BoardType::WALL;
			}		//하단
			else {
				ruleBoard[i][j] = BoardType::SPACE;
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

void Board::Remove(Block* block)
{
	int x = block->GetX();
	int y = block->GetY();
	short** B = block->PutBlock();
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (B[i][j] == BoardType::BLOCK) {
				ruleBoard[i + x][j + y] = BoardType::SPACE;
			}
		}
	}
}

void Board::Set(Block* block)
{
	int x = block->GetX();
	int y = block->GetY();
	short** B = block->PutBlock();
	//RuleInit();
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (B[i][j] == BoardType::BLOCK) {
				ruleBoard[i + x][j + y] = B[i][j];
			}
			
		}
	}
}

void Board::CopyBuffer()
{
	for (int i = 0; i < H; ++i) {
		memcpy(board[i], backBufferBoard[i], sizeof(short) * W);
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
			backBufferBoard[i][j] = ruleBoard[i][j];
		}
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (rememBoard[i][j] == BoardType::BLOCK) {
				backBufferBoard[i][j] = rememBoard[i][j];
			}
		}
	}

}

bool Board::IsCollision(Block* block)
{
	int x = block->GetX();
	int y = block->GetY();
	short** B = block->PutBlock();
	//RuleInit();
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (B[i][j] != BoardType::BLOCK) {
				continue;
			}
			if (ruleBoard[i + x][j + y] == BoardType::BLOCK ||
				ruleBoard[i + x][j + y] == BoardType::WALL) {
				return true;
			}

		}
	}
	return false;
	//bool re{ false };
	//for (int i = 0; i < H; ++i)
	//{
	//	for (int j = 1; j < W; ++j)
	//	{
	//		if (ruleBoard[i][j] == BoardType::BLOCK && wallBoard[i+1][j] == BoardType::WALL)
	//			re = true;
	//		else if (ruleBoard[i][j] == BoardType::BLOCK && wallBoard[i][j + 1] == BoardType::WALL)
	//		{
	//			rwc = true;
	//		}
	//		else if (ruleBoard[i][j] == BoardType::BLOCK && wallBoard[i][j + 1] != BoardType::WALL)
	//		{
	//			rwc = false;
	//		}
	//		else if (ruleBoard[i][j] == BoardType::BLOCK && wallBoard[i][j - 1] == BoardType::WALL)
	//		{
	//			lwc = true;
	//		}
	//		else if (ruleBoard[i][j] == BoardType::BLOCK && wallBoard[i][j - 1] != BoardType::WALL)
	//		{
	//			lwc = false;
	//		}
	//	}
	//	/*if (ruleBoard[H - 2][i] == BoardType::BLOCK) {
	//		re = true;
	//	}*/

	//}
	//return re;
}

void Board::RememberBlock(Block* block)
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (board[i][j] == BoardType::BLOCK) {
				ruleBoard[i][j] = BoardType::BLOCK;
			}
		}
	}
}

bool Board::FullBlock()
{
	int cnt{ 0 };
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if(ruleBoard[i][j] == BoardType::BLOCK) cnt += 1;
			if (cnt == W - 2) return true;
		}
		cnt = 0;
	}
	return false;
}

void Board::DownBlock()
{
	short temp[H][W]{};
	for (int i = 0; i < H; ++i) {
		memcpy(temp[i], ruleBoard[i], sizeof(short) * W);
		memcpy(ruleBoard[i], temp[i-1], sizeof(short) * W);
	}
}

