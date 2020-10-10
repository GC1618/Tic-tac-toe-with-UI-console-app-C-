#pragma once
#include<vector>
#include<unordered_map>
#include<string>
#include<iostream>
#include<windows.h>
#include <WinUser.h>
#include "PreferencesContainer.h"
#include "MenuLineValue.h"


class PlayState;
class State;
class MenuState;
class PreferencesState;

class Game
{
public:
	Game();
	~Game();

	void Update();
	static void ChangeState(int);
	static int GetState();
	static bool IsRunning();
	static void SetIsRunning(bool);

	enum class GameStates : int
	{
		MainMenu = 0,
		ChooseXorO,
		Play,
		PauseMenu,
		ChooseColors,
		Preferences, 
		ExitState
	};

	
private:
	//Create state methods
	void CreateMainMenuState();
	void CreateChooseXorOState();
	void CreatePreferencesState();
	void CreateChooseColorsState();
	void CreatePauseMenuState();
	void CreateExitState();
	void FillColorsVector(std::vector<MenuLineValue>&, PreferencesContainer::PreferenceType);
	
	
	static int currentState;
	static bool isRunning;
	std::unordered_map<int, State*> gameStates;
	MenuState* mainMenuState;
	MenuState* preferencesState;
	MenuState* chooseXorOState;
	MenuState* pauseMenuState;
	MenuState* chooseColorsState;
	PlayState* playState;
};

