#pragma once
#include <string>
#include <iostream>
#include "InputReceiver.h"

class MenuState;

class MenuLine : public InputReceiver
{
public:
	MenuLine();
	MenuLine(MenuState&);
	MenuLine(std::string);
	virtual ~MenuLine();

	virtual void Display();
	virtual void OnEscPressed()override;
	virtual void OnUpArrowPressed()override;
	virtual void OnDownArrowPressed()override;

	void SetText(std::string);

	void Select();
	void Deselect();
	bool GetIsSelected();

protected:
	std::string text;
	bool isSelected;

	MenuState* menuState;
};

