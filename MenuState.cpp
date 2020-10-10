#include "MenuState.h"
#include "PreferencesContainer.h"

MenuState::MenuState() : State()
{
	currentIndex = 0;
	preDisplayText = " ";
}

MenuState::MenuState(int exitState_) : State(exitState_)
{
	currentIndex = 0;
	preDisplayText = " ";
}

void MenuState::SetPreDisplayText(std::string text_)
{
	preDisplayText = text_;
}

MenuState::~MenuState()
{
	for (int i = 0; i < menuLines.size(); i++)
	{
		delete menuLines[i];
	}

	menuLines.clear();
}

void MenuState::ScrollUp()
{
	if (currentIndex == 0)
	{
		return;
	}

	menuLines[currentIndex]->Deselect();
	currentIndex -= 1;
	menuLines[currentIndex]->Select();
	isLastDisplayed = false;
}

void MenuState::ScrollDown()
{
	if (currentIndex == menuLines.size() - 1)
	{
		return;
	}

	menuLines[currentIndex]->Deselect();
	currentIndex += 1;
	menuLines[currentIndex]->Select();
	isLastDisplayed = false;
}

int MenuState::GetCurrentIndex()
{
	return currentIndex;
}

void MenuState::AddMenuItem(MenuLine* menuItem)
{
	menuLines.push_back(menuItem);

	if (menuLines.size() == 1)
	{
		menuLines[0]->Select();
	}
}

void MenuState::HandleInput()
{
	for (int i = 0; i < menuLines.size(); i++)
	{
		if (menuLines[i]->GetIsSelected())
		{
			Command& command = *inputHandler.HandleInput();
			if (&command)
			{
				command.Execute(*menuLines[i]);
			}
		}
	}
}

void MenuState::Display()
{
	system("cls");

	std::cout << preDisplayText << std::endl;

	for (int i = 0; i < menuLines.size(); i++)
	{
		menuLines[i]->Display();
	}
}

void MenuState::Update()
 {
	HandleInput();

	if (!IsActiv())
	{
		return;
	}

	if (!isLastDisplayed)
	{
		Display();
		isLastDisplayed = true;
	}
}