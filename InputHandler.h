#pragma once
#include <iostream>
#include "Command.h"

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	Command* HandleInput();

private:
	Command* enter;
	Command* esc;
	Command* upArrow;
	Command* downArrow;
	Command* leftArrow;
	Command* rightArrow;
};

