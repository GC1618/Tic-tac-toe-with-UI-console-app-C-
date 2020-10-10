#pragma once
#include "MenuLine.h"
#include "MenuLineWithValues.h"
#include "PlayState.h"
#include "MenuState.h"

class NewGameMenuLine : public MenuLine
{
public:
	NewGameMenuLine(MenuState&);
	virtual ~NewGameMenuLine();

	virtual void OnEnterPressed()override;
};

class PreferenceMenuLine: public MenuLine
{
public:
	PreferenceMenuLine(MenuState&, MenuState&);
	virtual ~PreferenceMenuLine();

	virtual void OnEnterPressed() override;

private:
	MenuState* preferenceState;
};

class LoadMenuLine : public MenuLine
{
public:
	LoadMenuLine(MenuState&, PlayState&);
	virtual	~LoadMenuLine();

	virtual void OnEnterPressed()override;

private:
	PlayState* playState;
};

class ExitMenuLine : public MenuLine
{
public:
	ExitMenuLine(MenuState&);
	virtual ~ExitMenuLine();

	virtual void OnEnterPressed()override;
};

class ColorsMenuLine : public MenuLine
{
public:
	ColorsMenuLine(MenuState&);
	virtual ~ColorsMenuLine();

	virtual void OnEnterPressed() override;
};

class SavePreferencesMenuLine : public MenuLine
{
public:
	SavePreferencesMenuLine(MenuState&);
	virtual ~SavePreferencesMenuLine();

	virtual void OnEnterPressed()override;
};

class XMenuLine : public MenuLine
{
public:
	XMenuLine(MenuState&);
	virtual ~XMenuLine();

	virtual void OnEnterPressed()override;
};

class OMenuLine : public MenuLine
{
public:
	OMenuLine(MenuState&);
	virtual ~OMenuLine();

	virtual void OnEnterPressed()override;
};

class RestartGameMenuLine : public MenuLine
{
public:
	RestartGameMenuLine(MenuState&, PlayState&);
	virtual ~RestartGameMenuLine();

	virtual void OnEnterPressed()override;

private:
	PlayState* playState;
};

class SaveGameMenuLine: public MenuLine
{
public:
	SaveGameMenuLine(MenuState&, PlayState&);
	virtual ~SaveGameMenuLine();

	virtual void OnEnterPressed()override;

private:
	PlayState* playState;

};

class ExitToMainMenuMenuLine : public MenuLine
{
public:
	ExitToMainMenuMenuLine(MenuState&, PlayState&);
	virtual ~ExitToMainMenuMenuLine();

	virtual void OnEnterPressed()override;

private:
	PlayState* playState;
};