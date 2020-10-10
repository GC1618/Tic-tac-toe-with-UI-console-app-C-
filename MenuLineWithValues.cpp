#include "MenuLineWithValues.h"
#include "MenuState.h"
#include "PreferencesContainer.h"
#include <windows.h>

MenuLineWithValues::MenuLineWithValues(MenuState& menuState_, std::string text_, std::vector<MenuLineValue> values_) : MenuLine(menuState_)
{
	text = text_;
	values = values_;
	currentValue = 0;

	MoveCurrentValue();
}

MenuLineWithValues::~MenuLineWithValues()
{
	MenuLine::~MenuLine();
}

void MenuLineWithValues::DisplayLine()
{
	std::cout << text << "			[";
	for (int i = 0; i < values.size(); i++)
	{
		if (i == currentValue)
		{
			std::cout << values[i].GetName() << "]" << std::endl;
		}
	}
}

void MenuLineWithValues::Display()
{
	if (isSelected)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int selectedColor = PreferencesContainer::GetInstance().GetSelectedColor();
		int menuColor = PreferencesContainer::GetInstance().GetMenuColor();

		SetConsoleTextAttribute(hConsole, selectedColor);
		DisplayLine();
		SetConsoleTextAttribute(hConsole, menuColor);
	}
	else
	{
		DisplayLine();
	}
}

void MenuLineWithValues::OnLeftArrowPressed()
{
	if (currentValue == 0)
	{
		return;
	}

	currentValue -= 1;
	PreferencesContainer::GetInstance().ChangeValueInBuffer(values[currentValue].GetPreferanceType(), values[currentValue].GetValue());
	menuState->SetIsLastDisplayedFalse();
}

void MenuLineWithValues::OnRightArrowPressed()
{
	if (currentValue == values.size() - 1)
	{
		return;
	}

	currentValue += 1;
	PreferencesContainer::GetInstance().ChangeValueInBuffer(values[currentValue].GetPreferanceType(), values[currentValue].GetValue());
	menuState->SetIsLastDisplayedFalse();
}

void MenuLineWithValues::MoveCurrentValue()
{
	PreferencesContainer::PreferenceType preferenceType = values[0].GetPreferanceType();
	int correctValue = -1;

	switch (preferenceType)
	{
	case PreferencesContainer::PreferenceType::Difficulty:
		correctValue = PreferencesContainer::GetInstance().GetDifficulty();
		break;

	case PreferencesContainer::PreferenceType::MenuColor:
		correctValue = PreferencesContainer::GetInstance().GetMenuColor();
		break;

	case PreferencesContainer::PreferenceType::XColor:
		correctValue = PreferencesContainer::GetInstance().GetXColor();
		break;

	case PreferencesContainer::PreferenceType::OColor:
		correctValue = PreferencesContainer::GetInstance().GetOColor();
		break;
	}

	for (int i = 0; i < values.size(); i++)
	{
		if (values[i].GetValue() == correctValue)
		{
			currentValue = i;
		}
	}
}