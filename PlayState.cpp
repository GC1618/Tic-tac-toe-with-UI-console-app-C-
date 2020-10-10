#include "PlayState.h"
#include "AI.h"
#include <fstream>

PlayState::PlayState(int exitState_)
	: State(exitState_)
{
	board = new Board(*this);
	player = new Player(*this, *board);
	ai = new AI(*board, 0);
	countMoves = 0;
}

PlayState::~PlayState()
{
	State::~State();
}

void PlayState::HandleInput()
{
	Command& command = *(inputHandler.HandleInput());
	if (&command)
	{
		command.Execute(*player);
	}
}

void PlayState::Display()
{
	system("cls");
	board->Display();

	std::cout << "Press [ESC] to enter the Pause Menu" << std::endl;
}

void PlayState::Update()
{	
	if (player->IsPlayerTurn())
	{
		HandleInput();
	}
	else
	{
		ai->MakeMove();
		isLastDisplayed = false;
		player->SetIsPlayerTurn(true);
	}

	if (!isLastDisplayed)
	{
		Display();
		isLastDisplayed = true;

		CheckWin();
	}
}

void PlayState::Restart()
{
	board->Fill();
	board->ResetCountMoves();
}

void PlayState::CheckWin()
{
	if (board->CheckWin())
	{
		std::cout << board->GetWinner() << " wins!" << std::endl;
		board->SetWinner(' ');
		board->Fill();
		Sleep(3000);
		Exit();
	}

	if (!board->IsMovesLeft())
	{
		std::cout << "It's a tie!" << std::endl;
		board->Fill();
		Sleep(3000);
		Exit();
	}
}

void PlayState::Save()
{
	int matrixSize = 3;
	std::vector<std::vector<char>>& matrix = board->GetMatrix();
	std::ofstream file;
	file.open("Save.bin", std::ios::out | std::ios::binary);

	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if (matrix[i][j] == ' ')
			{
				file << '-' << std::endl;
			}
			else
			{
				file << matrix[i][j] << std::endl;
			}
		}
	}

	file << player->IsPlayerTurn() << std::endl;
	file << PreferencesContainer::GetInstance().GetDifficulty() << std::endl;
	file << board->GetCountMoves() << std::endl;
	file << PreferencesContainer::GetInstance().GetPlayerMark() << std::endl;

	file.close();
}

bool PlayState::Load()
{
	std::ifstream file;
	file.open("Save.bin", std::ios::in | std::ios::binary);
	if(!file)
	{
		return false;
	}

	int matrixSize = 3;
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			char element;
			file >> element;
			if (element == '-')
			{
				board->SetElement(' ', i, j);
			}
			else
			{
				board->SetElement(element, i, j);
			}
		}
	}

	bool playerTurn_;
	int difficulty_;
	int countMoves_;
	char playerMark_;

	file >> playerTurn_ ;
	file >> difficulty_;
	file >> countMoves_;
	file >> playerMark_;

	player->SetIsPlayerTurn(playerTurn_);
	PreferencesContainer::GetInstance().SetDifficulty(difficulty_);
	board->SetCountMoves(countMoves_);
	PreferencesContainer::GetInstance().SetPlayerMark(playerMark_);

	file.close();
	return true;
}