#include "MenuLineValue.h"
#include "PreferencesContainer.h"

MenuLineValue::MenuLineValue(std::string name_, int value_, PreferencesContainer::PreferenceType preferenceType_)
{
	name = name_;
	value = value_;
	preferenceType = preferenceType_;
}

MenuLineValue::~MenuLineValue()
{
	name.clear();
}

PreferencesContainer::PreferenceType MenuLineValue::GetPreferanceType()
{
	return preferenceType;
}

void MenuLineValue::SetValue(int value_)
{
	value = value_;
}

int MenuLineValue::GetValue()
{
	return value;
}

std::string MenuLineValue::GetName()
{
	return name;
}