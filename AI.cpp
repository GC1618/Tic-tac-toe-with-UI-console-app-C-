#include "AI.h"
#include "PreferencesContainer.h"

AI::AI(Board& board_, int difficulty_)
{
	board = &board_;
	difficulty = difficulty_;
}

AI::~AI()
{

}

void AI::MakeMove()
{
	char aiMark = PreferencesContainer::GetInstance().GetAiMark();

	if (PreferencesContainer::GetInstance().GetDifficulty() ==
		int(PreferencesContainer::Difficulty::Easy))
	{
		//Random choice
		bool validMove = false;
		int row = -1;
		int column = -1;

		while (!validMove)
		{
			int choice = (rand() % 9) + 1;

			row = (choice - 1) / 3;
			column = (choice - 1) % 3;

			validMove = board->IsSpotAvailable(row, column);
		}

		board->PlaceMarkAt(aiMark, row, column);
	}
	else
	{
		//Using the minimax algorithm
		Board::MatrixElement bestMove = GetBestMove();
		board->PlaceMarkAt(aiMark, bestMove.row, bestMove.column);
	}
}

int AI::MiniMax(int depth, bool isMax)
{
	int score = Evaluate();

	if (PreferencesContainer::GetInstance().GetDifficulty() ==
		(int)PreferencesContainer::Difficulty::Medium)
	{
		depth = 0;
	}

	if (score == 10)
	{
		return score - depth;
	}

	if (score == -10)
	{
		return score + depth;
	}

	if (!board->IsMovesLeft())
	{
		return 0;
	}

	char aiMark = PreferencesContainer::GetInstance().GetAiMark();
	char playerMark = PreferencesContainer::GetInstance().GetPlayerMark();
	int smallNumber = -1000;
	int bigNumber = 1000;

	if (isMax)
	{
		int bestMoveValue = smallNumber;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board->GetMatrix()[i][j] == ' ')
				{
					board->SetElement(playerMark, i, j);

					bestMoveValue = max(bestMoveValue, MiniMax(depth + 1, !isMax));

					board->SetElement(' ', i, j);
				}
			}
		}

		return bestMoveValue;
	}
	else
	{
		int bestMoveValue = bigNumber;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board->GetMatrix()[i][j] == ' ')
				{
					board->SetElement(aiMark, i, j);

					bestMoveValue = min(bestMoveValue, MiniMax(depth + 1, !isMax));

					board->SetElement(' ', i, j);
				}
			}
		}

		return bestMoveValue;
	}

}

Board::MatrixElement AI::GetBestMove()
{
	int size = board->GetSize();
	int bestVal = 1000;
	Board::MatrixElement bestMove;
	bestMove.row = -1;
	bestMove.column = -1;
	char aiMark = PreferencesContainer::GetInstance().GetAiMark();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board->GetMatrix()[i][j] == ' ')
			{
				board->SetElement(aiMark, i, j);

				int moveVal = MiniMax(0, true);

				board->SetElement(' ', i, j);

				if (moveVal < bestVal)
				{
					bestMove.row = i;
					bestMove.column = j;
					bestVal = moveVal;
				}
			}
		}
	}

	return bestMove;
}

int AI::Evaluate()
{
	//This method returns 10 if the player wins, -10 if the player losese and 0 if nobody wins
	//It is use by the Minimax algorithm

	int size = board->GetSize();
	char playerMark = PreferencesContainer::GetInstance().GetPlayerMark();
	std::vector<std::vector<char>> matrix = board->GetMatrix();


	for (int i = 0; i < size; i++)
	{
		//Check rows
		if ((matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
			&& matrix[i][2] != ' ')
		{
			if (matrix[i][0] == playerMark)
			{
				return 10;
			}
			else
			{
				return -10;
			}
		}

		//Check colums
		if ((matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])
			&& matrix[2][i] != ' ')
		{
			if (matrix[0][i] == playerMark)
			{
				return 10;
			}
			else
			{
				return -10;
			}
		}
	}

	//Check diagonals
	if ((matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
		&& matrix[2][2] != ' ')
	{
		if (matrix[0][0] == playerMark)
		{
			return 10;
		}
		else
		{
			return -10;
		}
	}

	if ((matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
		&& matrix[2][0] != ' ')
	{
		if (matrix[0][2] == playerMark)
		{
			return 10;
		}
		else
		{
			return -10;
		}
	}

	return 0;
}