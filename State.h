#pragma once
#include <vector>
#include "MenuLine.h"
#include "MenuLineValue.h"
#include "InputHandler.h"
#include <unordered_map>
#include "Game.h"

class State
{
public:
	State();
	State(int);
	virtual ~State();

	virtual void HandleInput() = 0;
	virtual void Display() = 0;
	virtual void Update() = 0;

	virtual void Activate();
	virtual void Deactivate();
	virtual bool IsActiv();
	virtual void Exit();
	virtual void SetIsLastDisplayedFalse();

	virtual void SetExitState(int);

protected:
	int exitState;
	bool isActive;
	bool isLastDisplayed;
	InputHandler inputHandler;
};

