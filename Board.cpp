 #include "Board.h"
#include "PreferencesContainer.h"
#include <windows.h>
 
Board::Board(PlayState& playState_)
{
	playState = &playState_;
	currentSpot.row = 0;
	currentSpot.column = 0;
	countMoves = 0;
	winner = ' ';
	Fill();
}

Board::~Board()
{

}

void Board::Fill()
{
	for (int i = 0; i < size; i++)
	{
		if (matrix.size() == 0)
		{
			matrix.resize(size);
		}

		for (int j = 0; j < size; j++)
		{
			if (matrix[i].size() == 0)
			{
				matrix[i].resize(size);
			}

			matrix[i][j] = ' ';
		}
	}
}

int Board::GetSize() const
{
	return size;
}

void Board::DisplayMark(char mark, int markColor, int menuColor, HANDLE hConsole)
{
	SetConsoleTextAttribute(hConsole, markColor);
	std::cout << "[" << mark << "] ";
	SetConsoleTextAttribute(hConsole, menuColor);
}

void Board::Display()
{
	//REWRITE THIS!!

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int cursorColor = PreferencesContainer::GetInstance().GetSelectedColor();
	int xColor = PreferencesContainer::GetInstance().GetXColor();
	int oColor = PreferencesContainer::GetInstance().GetOColor();
	int menuColor = PreferencesContainer::GetInstance().GetMenuColor();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] == 'X')
			{
				//Move from here
				if (i == currentSpot.row && j == currentSpot.column)
				{
					DisplayMark('X', cursorColor, menuColor, hConsole);
				}
				else
				{
					DisplayMark('X', xColor, menuColor, hConsole);
				}
			}

			else if (matrix[i][j] == 'O')
			{
				if (i == currentSpot.row && j == currentSpot.column)
				{
					DisplayMark('O', cursorColor, menuColor, hConsole);
				}
				else
				{
					DisplayMark('O', oColor, menuColor, hConsole);
				}
			}

			else
			{
				if (i == currentSpot.row && j == currentSpot.column)
				{
					DisplayMark(' ', cursorColor, menuColor, hConsole);
				}
				else
				{
					DisplayMark(' ', menuColor, menuColor, hConsole);
				}
			}
		}

		std::cout << std::endl;
	}

}

bool Board::IsSpotAvailableAtCursor()
{
	return IsSpotAvailable(currentSpot.row, currentSpot.column);
}

bool Board::IsSpotAvailable(int row, int column)
{
	if (matrix[row][column] == 'X' ||
		matrix[row][column] == 'O')
	{
		return false;
	}

	return true;
}


bool Board::PlayerPlaceMark()
{
	if (!IsSpotAvailableAtCursor())
	{
		std::cout << "No good!" << std::endl;
		return false;
	}
	 
	PlaceMarkAt(PreferencesContainer::GetInstance().GetPlayerMark(), currentSpot.row, currentSpot.column);
	playState->SetIsLastDisplayedFalse();
	return true;
}

void Board::PlaceMarkAt(char mark, int row, int column)
{
	countMoves += 1;
	matrix[row][column] = mark;
}

bool Board::CheckWin()
{
	for (int i = 0; i < size; i++)
	{
		//Check rows
		if ((matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2])
			&& matrix[i][2] != ' ')
		{
			winner = matrix[i][0];
			return true;
		}

		//Check colums
		if ((matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i])
			&& matrix[2][i] != ' ')
		{
			winner = matrix[0][i];
			return true;
		}
	}

	//Check diagonals
	if ((matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
		&& matrix[2][2] != ' ')
	{
		winner = matrix[0][0];
		return true;
	}

	if ((matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
		&& matrix[2][0] != ' ')
	{
		winner = matrix[0][0];
		return true;
	}

	return false;
}

bool Board::IsMovesLeft()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] == ' ')
			{
				return true;
			}
		}
	}

	return false;
}

char Board::GetWinner()
{
	return winner;
}

void Board::SetWinner(char winner_)
{
	winner = winner_;
}

int Board::GetCountMoves()
{
	return countMoves;
}

void Board::ResetCountMoves()
{
	countMoves = 0;
}

void Board::SetCountMoves(int countMoves_)
{
	countMoves = countMoves_;
}

void Board::MoveUp()
{
	if (currentSpot.row == 0)
	{
		return;
	}

	playState->SetIsLastDisplayedFalse();
	currentSpot.row -= 1;
}

void Board::MoveDown()
{
	if (currentSpot.row == size - 1)
	{
		return;
	}

	playState->SetIsLastDisplayedFalse();
	currentSpot.row += 1;
}

void Board::MoveLeft()
{
	if (currentSpot.column == 0)
	{
		return;
	}

	playState->SetIsLastDisplayedFalse();
	currentSpot.column -= 1;
}

void Board::MoveRight()
{
	if (currentSpot.column == size - 1)
	{
		return;
	}

	playState->SetIsLastDisplayedFalse();
	currentSpot.column += 1;
}

std::vector<std::vector<char>>& Board::GetMatrix()
{
	return matrix;
}

void Board::SetMatrix(std::vector<std::vector<char>> matrix_)
{
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			char element;
			if (matrix_[i][j] == '-')
			{
				element = ' ';
			}
			else
			{
				element = matrix_[i][j];
			}

			matrix[i][j] = element;
		}
	}
}

void Board::SetElement(char element, int row, int column)
{
	matrix[row][column] = element;
}