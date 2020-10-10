#pragma once
#include "MenuLine.h"
#include <vector>
#include <string>
#include "MenuLineValue.h"
#include "MenuState.h"


class MenuLineWithValues : public MenuLine
{
public:
	MenuLineWithValues(MenuState&, std::string, std::vector<MenuLineValue>);
	virtual ~MenuLineWithValues();
	virtual void Display()override;
	virtual void OnLeftArrowPressed()override;
	virtual void OnRightArrowPressed()override;

	void DisplayLine();

private:
	//Moves the currentValue index to the correct value from Preferences
	void MoveCurrentValue();

	std::vector<MenuLineValue> values;
	int currentValue;
};

