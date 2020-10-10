#include "MenuLine.h"
#include <windows.h>
#include "MenuState.h"
#include "PreferencesContainer.h"

MenuLine::MenuLine()
{
	isSelected = false;
}

MenuLine::MenuLine(MenuState& menuState_)
{
	isSelected = false;
	menuState = &menuState_;
}

MenuLine::MenuLine(std::string newText)
{
	text = newText;
	isSelected = false;
}

void MenuLine::Select()
{
	isSelected = true;
}

void MenuLine::Deselect()
{
	isSelected = false;
}

bool MenuLine::GetIsSelected()
{
	return isSelected;
}

MenuLine::~MenuLine()
{
	text.clear();
}

void MenuLine::Display() 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int menuColor = PreferencesContainer::GetInstance().GetMenuColor();
	int selectedColor = PreferencesContainer::GetInstance().GetSelectedColor();;

	if (isSelected)
	{
		SetConsoleTextAttribute(hConsole, selectedColor);
		std::cout << text << std::endl;
		SetConsoleTextAttribute(hConsole, menuColor);
	}
	else
	{
		SetConsoleTextAttribute(hConsole, menuColor);
		std::cout << text << std::endl;
	}
}


void MenuLine::SetText(std::string text_)
{
	text = text_;
}

void MenuLine::OnUpArrowPressed()
{
	menuState->ScrollUp();
}

void MenuLine::OnDownArrowPressed()
{
	menuState->ScrollDown();
}

void MenuLine::OnEscPressed()
{
	menuState->Exit();
}