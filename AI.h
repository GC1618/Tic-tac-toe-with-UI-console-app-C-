#pragma once
#include "Board.h"

class AI
{
public:
	AI(Board&, int);
	~AI();

	void MakeMove();

	struct Move
	{
		int x;
		int y;
	};


private:
	int MiniMax(int, bool);
	int Evaluate();
	Board::MatrixElement GetBestMove();

	Board* board;
	int difficulty;
};

