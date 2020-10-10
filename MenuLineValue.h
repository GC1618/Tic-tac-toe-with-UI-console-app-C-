#pragma once
#include <string>
#include "PreferencesContainer.h"


class MenuLineValue
{
public:
	MenuLineValue(std::string, int, PreferencesContainer::PreferenceType);
	~MenuLineValue();

	void SetValue(int);
	int GetValue();

	PreferencesContainer::PreferenceType GetPreferanceType();
	std::string GetName();

private:
	std::string name;
	int value;
	PreferencesContainer::PreferenceType preferenceType;
};

