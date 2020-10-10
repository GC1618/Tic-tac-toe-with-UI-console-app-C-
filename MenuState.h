#pragma once
#include "State.h"

class MenuState : public State
{
public:
	MenuState();
	MenuState(int);
	virtual ~MenuState();

	void AddMenuItem(MenuLine*);
	int GetCurrentIndex();

	void ScrollUp();
	void ScrollDown();

	virtual void HandleInput()override;
	virtual void Display()override;
	virtual void Update()override;

	void SetPreDisplayText(std::string);

protected:
	std::vector<MenuLine*> menuLines;
	int currentIndex;
	std::string preDisplayText;
};

