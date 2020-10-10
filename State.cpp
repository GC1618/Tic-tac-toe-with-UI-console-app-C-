#include "State.h"

State::State()
{
	exitState = 0;
	isActive = false;
	isLastDisplayed = false;
}

State::~State()
{

}

State::State(int exitState_)
{
	exitState = exitState_;
	isActive = false;
	isLastDisplayed = false;
}

void State::Activate()
{
	isActive = true;
	isLastDisplayed = false;
}

void State::Deactivate()
{
	isActive = false;
}

bool State::IsActiv()
{
	return isActive;
}

void State::Exit()
{
	Deactivate();
	Game::ChangeState(exitState);
}

void State::SetIsLastDisplayedFalse()
{
	isLastDisplayed = false;
}

void State::SetExitState(int exitState_)
{
	exitState = exitState_;
}
