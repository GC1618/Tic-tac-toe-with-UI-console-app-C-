#include "PreferencesContainer.h"
#include <fstream>

PreferencesContainer* PreferencesContainer::instance = nullptr;

PreferencesContainer& PreferencesContainer::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new PreferencesContainer();
	}

	return *instance;
}

PreferencesContainer::PreferencesContainer()
{
	playerMark = ' ';
	aiMark = ' ';
	selectedColor = int(Colors::Red);

	if (!Load()) {
		difficulty = int(Difficulty::Easy);
		menuColor = int(Colors::Blue);
		xColor = int(Colors::Yellow);
		oColor = int(Colors::Purple);
	}

	difficultyBuffer = difficulty;
	menuColorBuffer = menuColor;
	xColorBuffer = xColor;
	oColorBuffer = oColor;
}

PreferencesContainer::~PreferencesContainer()
{
	if (instance != nullptr)
	{
		delete instance;
	}
}

void PreferencesContainer::SetAllValues(int difficulty_, int menuColor_, int selectedColor_, int xColor_, int oColor_)
{
	
	difficulty = difficulty_;
	selectedColor = selectedColor_;
	menuColor = menuColor_;
	xColor = xColor_;
	oColor = oColor_;
}

void PreferencesContainer::ChangeValueInBuffer(PreferenceType preferenceType, int value)
{
	switch(preferenceType)
	{
	case PreferenceType::Difficulty:
		SetBufferDifficulty(value);
		break;
	case PreferenceType::MenuColor:
		SetBufferMenuColor(value);
		break;
	case PreferenceType::XColor:
		SetBufferXColor(value);
		break;
	case PreferenceType::OColor:
		SetBufferOColor(value);
		break;
	}
}

void PreferencesContainer::SetDifficulty(int difficulty_)
{
	difficulty = difficulty_;
}

int PreferencesContainer::GetDifficulty()
{
	return difficulty;
}

void PreferencesContainer::SetMenuColor(int menuColor_)
{
	menuColor = menuColor_;
}

int PreferencesContainer::GetMenuColor()
{
	return menuColor;
}

void PreferencesContainer::SetSelectedColor(int selectedColor_)
{
	selectedColor = selectedColor_;
}

int PreferencesContainer::GetSelectedColor()
{
	return selectedColor;
}

void PreferencesContainer::SetXColor(int xColor_)
{
	xColor = xColor_;
}

int PreferencesContainer::GetXColor()
{
	return xColor;
}

void PreferencesContainer::SetOColor(int oColor_)
{
	oColor = oColor_;
}

int PreferencesContainer::GetOColor()
{
	return oColor;
}

//Buffer
void PreferencesContainer::SetBufferDifficulty(int difficulty_)
{
	difficultyBuffer = difficulty_;
}

int PreferencesContainer::GetBufferDifficulty()
{
	return difficultyBuffer;
}

void PreferencesContainer::SetBufferMenuColor(int menuColor_)
{
	menuColorBuffer = menuColor_;
}

int PreferencesContainer::GetBufferMenuColor()
{
	return menuColorBuffer;
}

void PreferencesContainer::SetBufferXColor(int xColor_)
{
	xColorBuffer = xColor_;
}

int PreferencesContainer::GetBufferXColor()
{
	return xColorBuffer;
}

void PreferencesContainer::SetBufferOColor(int oColor_)
{
	oColorBuffer = oColor_;
}

int PreferencesContainer::GetBufferOColor()
{
	return oColorBuffer;
}

void PreferencesContainer::SaveBuffer()
{
	//Rewrite this
	difficulty = difficultyBuffer;
	menuColor = menuColorBuffer;
	xColor = xColorBuffer;
	oColor = oColorBuffer;
}

void PreferencesContainer::SetPlayerMark(char playerMark_)
{
	if (playerMark_ == 'X')
	{
		aiMark = 'O';
	}
	else
	{
		aiMark = 'X';
	}

	playerMark = playerMark_;
}

char PreferencesContainer::GetPlayerMark()
{
	return playerMark;
}

char PreferencesContainer::GetAiMark()
{
	return aiMark;
}

void PreferencesContainer::Save()
{
	SaveBuffer();
	std::ofstream file;
	file.open("PreferencesFile.bin", std::ios::out | std::ios::binary);

	file << difficulty << std::endl;
	file << menuColor << std::endl;
	file << xColor << std::endl;
	file << oColor << std::endl;

	file.close();
}

bool PreferencesContainer::Load()
{
	bool ret = false;
	std::ifstream file;
	file.open("PreferencesFile.bin", std::ios::in | std::ios::binary);

	if (file)
	{
		file >> difficulty;
		file >> menuColor;
		file >> xColor;
		file >> oColor;

		ret = true;
	}

	file.close();

	return ret;
}