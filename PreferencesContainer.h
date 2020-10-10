#pragma once

class PreferencesContainer
{
public:
	static PreferencesContainer& GetInstance();

	~PreferencesContainer();

	void SetAllValues(int, int, int, int, int);

	void SetDifficulty(int);
	int GetDifficulty();

	void SetMenuColor(int);
	int GetMenuColor();

	void SetSelectedColor(int);
	int GetSelectedColor();

	void SetXColor(int);
	int GetXColor();

	void SetOColor(int);
	int GetOColor();

	enum class PreferenceType
	{
		Difficulty,
		MenuColor,
		XColor,
		OColor
	};

	enum class Difficulty : int
	{
		Easy,
		Medium,
		Hard
	};

	enum class Colors : int
	{
		Blue = 1,
		Red = 4,
		Purple = 5,
		Yellow = 14,
		White = 15,
	};

	//Buffer
	void ChangeValueInBuffer(PreferencesContainer::PreferenceType, int);

	void SetBufferDifficulty(int);
	int GetBufferDifficulty();

	void SetBufferMenuColor(int);
	int GetBufferMenuColor();

	void SetBufferXColor(int);
	int GetBufferXColor();

	void SetBufferOColor(int);
	int GetBufferOColor();
;
	void SaveBuffer();

	void SetPlayerMark(char);
	char GetPlayerMark();
	char GetAiMark();

	void Save();
	//If there is a file with preferences returns true
	bool Load();

private:
	PreferencesContainer();
	static PreferencesContainer* instance;

	char playerMark;
	char aiMark;
	int difficulty;
	int menuColor;
	int selectedColor;
	int xColor;
	int oColor;

	//Buffer values
	int difficultyBuffer;
	int menuColorBuffer;
	int xColorBuffer;
	int oColorBuffer;
};

