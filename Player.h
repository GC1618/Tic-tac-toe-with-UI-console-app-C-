#pragma once
#include "InputReceiver.h"

class PlayState;
class Board;

class Player :
    public InputReceiver
{
public:
	Player(PlayState&, Board&);
	virtual ~Player();

	bool IsPlayerTurn();
	void SetIsPlayerTurn(bool);

	virtual void OnEnterPressed()override;
	virtual void OnEscPressed()override;
	virtual void OnUpArrowPressed()override;
	virtual void OnDownArrowPressed()override;
	virtual void OnLeftArrowPressed()override;
	virtual void OnRightArrowPressed()override;

private:
	Board* board;
	bool isPlayerTurn;

	PlayState* playState;
};

