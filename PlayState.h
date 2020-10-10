#pragma once
#include "State.h"
#include "Player.h"

class AI;

class PlayState : public State
{
public:
	PlayState(int);
	~PlayState();

	virtual void HandleInput()override;
	virtual void Display()override;
	virtual void Update()override;

	void Save();
	bool Load();

	void Restart();
	void CheckWin();

private:
	Board* board;
	Player* player;
	AI* ai;

	int countMoves;
};

