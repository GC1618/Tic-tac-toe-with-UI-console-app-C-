#include "InputHandler.h"
#include "Game.h"

InputHandler::InputHandler()
{
	enter = new EnterCommand();
	esc = new EscCommand();
	upArrow = new UpCommand();
	downArrow = new DownCommand();
	leftArrow = new LeftCommand();
	rightArrow = new RightCommand();
}

InputHandler::~InputHandler()
{
	delete enter;
	delete upArrow;
	delete downArrow;
	delete esc;
	delete leftArrow;
	delete rightArrow;
}

Command* InputHandler::HandleInput()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		Sleep(150);
		return enter;
	}
		
	else if (GetAsyncKeyState(VK_UP)) 
	{
		Sleep(150);
		return upArrow;
	}

	else if (GetAsyncKeyState(VK_DOWN))
	{
		Sleep(150);
		return downArrow;
	}

	else if (GetAsyncKeyState(VK_ESCAPE))
	{
		Sleep(150);
		return esc;
	}

	else if (GetAsyncKeyState(VK_LEFT))
	{
		Sleep(150);
		return leftArrow;
	}

	else if (GetAsyncKeyState(VK_RIGHT))
	{
		Sleep(150);
		return rightArrow;
	}

	return NULL;
}
