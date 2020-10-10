#pragma once
#include <vector>
#include "PlayState.h"

class Board
{
public:
	Board(PlayState&);
	~Board();

	void Fill();
	void Display();
	void DisplayMark(char, int, int, HANDLE);
	bool PlayerPlaceMark();
	void PlaceMarkAt(char, int, int);  

	std::vector<std::vector<char>>& GetMatrix();
	void SetMatrix(std::vector<std::vector<char>>);
	void SetElement(char, int, int);

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	enum class Winner : int
	{
		X = 0,
		O = 1,
		Draw = 2,
		Nothing
	};


	bool IsMovesLeft();

	bool CheckWin();
	char GetWinner();
	void SetWinner(char);
	int GetCountMoves();
	void ResetCountMoves();
	void SetCountMoves(int);
	int GetSize()const;

	bool IsSpotAvailableAtCursor();
	bool IsSpotAvailable(int, int);

	struct MatrixElement
	{
		int row;
		int column;
	};

private:
	const int size = 3;
	std::vector<std::vector<char>> matrix;
	PlayState* playState;

	MatrixElement currentSpot;
	int countMoves;
	char winner;
};

