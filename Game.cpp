#include "Game.h"
#include "MenuState.h"
#include "MenuLines.h"
#include "PreferencesContainer.h"
#include "PlayState.h"


int Game::currentState = int(GameStates::MainMenu);
bool Game::isRunning = true;

void Game::ChangeState(int state_)
{
	currentState = state_;
}

int Game::GetState()
{
	return currentState;
}

bool Game::IsRunning()
{
	return isRunning;
}

void Game::SetIsRunning(bool isRunning_)
{
	isRunning = isRunning_;
}

Game::Game()
{
	//Create game states
	playState = new PlayState(int(GameStates::PauseMenu));
	gameStates[int(GameStates::Play)] = playState;
	CreatePreferencesState();
	CreateMainMenuState();
	CreateChooseXorOState();
	CreateChooseColorsState();
	
	CreatePauseMenuState();
}

Game::~Game()
{
	for (auto& state : gameStates)
	{
		delete state.second;
	}
}

void Game::Update()
{
	if (!gameStates[currentState]->IsActiv())
	{
		gameStates[currentState]->Activate();
	}

	gameStates[currentState]->Update();
}

void Game::CreateMainMenuState()
{
	mainMenuState = new MenuState(int(GameStates::MainMenu));
	mainMenuState->SetPreDisplayText("MAIN MENU");
	mainMenuState->AddMenuItem(new NewGameMenuLine(*mainMenuState));
	mainMenuState->AddMenuItem(new LoadMenuLine(*mainMenuState, *playState));
	mainMenuState->AddMenuItem(new PreferenceMenuLine(*mainMenuState, *preferencesState));
	mainMenuState->AddMenuItem(new ExitMenuLine(*mainMenuState));
	mainMenuState->Activate();

	gameStates[int(GameStates::MainMenu)] = mainMenuState;
}

void Game::CreateChooseXorOState()
{
	chooseXorOState = new MenuState(int(GameStates::MainMenu));
	chooseXorOState->SetPreDisplayText("Choose X or O:");
	chooseXorOState->AddMenuItem(new XMenuLine(*chooseXorOState));
	chooseXorOState->AddMenuItem(new OMenuLine(*chooseXorOState));

	gameStates[int(GameStates::ChooseXorO)] = chooseXorOState;
}

void Game::CreatePauseMenuState()
{
	pauseMenuState = new MenuState(int(GameStates::Play));
	pauseMenuState->SetPreDisplayText("PAUSE MENU");
	pauseMenuState->AddMenuItem(new RestartGameMenuLine(*pauseMenuState, *playState));
	pauseMenuState->AddMenuItem(new SaveGameMenuLine(*pauseMenuState, *playState)) ;
	pauseMenuState->AddMenuItem(new LoadMenuLine(*pauseMenuState, *playState));
	pauseMenuState->AddMenuItem(new PreferenceMenuLine(*pauseMenuState, *preferencesState));
	pauseMenuState->AddMenuItem(new ExitToMainMenuMenuLine(*pauseMenuState, *playState));

	gameStates[int(GameStates::PauseMenu)] = pauseMenuState;
}

void Game::CreatePreferencesState()
{
	PreferencesContainer::PreferenceType preferenceType = PreferencesContainer::PreferenceType::Difficulty;
	int easy = int(PreferencesContainer::Difficulty::Easy);
	int medium = int(PreferencesContainer::Difficulty::Medium);
	int hard = int(PreferencesContainer::Difficulty::Hard);


	preferencesState = new MenuState(int(GameStates::MainMenu));
	preferencesState->SetPreDisplayText("Click [SAVE] to save changes!");
	std::vector <MenuLineValue> menuLineValues;
	menuLineValues.push_back(MenuLineValue("EASY", easy, preferenceType));
	menuLineValues.push_back(MenuLineValue("MEDIUM", medium, preferenceType));
	menuLineValues.push_back(MenuLineValue("HARD", hard, preferenceType));
	preferencesState->AddMenuItem(new MenuLineWithValues(*preferencesState, "Difficulty", menuLineValues));
	preferencesState->AddMenuItem(new ColorsMenuLine(*preferencesState));
	preferencesState->AddMenuItem(new SavePreferencesMenuLine(*preferencesState));
	menuLineValues.clear();

	gameStates[int(GameStates::Preferences)] = preferencesState;
}

void Game::CreateChooseColorsState()
{
	PreferencesContainer::PreferenceType preferenceType = PreferencesContainer::PreferenceType::MenuColor;
	std::vector <MenuLineValue> menuLineValues;
	chooseColorsState = new MenuState(int(GameStates::Preferences));
	chooseColorsState->SetPreDisplayText("After choosing the colors, press [ESC] and then [SAVE] to save the changes!");

	FillColorsVector(menuLineValues, preferenceType);
	chooseColorsState->AddMenuItem(new MenuLineWithValues(*chooseColorsState, "Menu Color", menuLineValues));
	menuLineValues.clear();

	preferenceType = PreferencesContainer::PreferenceType::XColor;
	FillColorsVector(menuLineValues, preferenceType);
	chooseColorsState->AddMenuItem(new MenuLineWithValues(*chooseColorsState, "X Color", menuLineValues));
	menuLineValues.clear();

	preferenceType = PreferencesContainer::PreferenceType::OColor;
	FillColorsVector(menuLineValues, preferenceType);
	chooseColorsState->AddMenuItem(new MenuLineWithValues(*chooseColorsState, "O Color", menuLineValues));

	menuLineValues.clear();

	gameStates[int(GameStates::ChooseColors)] = chooseColorsState;
}

void Game::CreateExitState()
{

}

void Game::FillColorsVector(std::vector<MenuLineValue>& vector, PreferencesContainer::PreferenceType preferenceType)
{
	vector.push_back(MenuLineValue("WHITE", int(PreferencesContainer::Colors::White), preferenceType));
	vector.push_back(MenuLineValue("BLUE", int(PreferencesContainer::Colors::Blue), preferenceType));
	vector.push_back(MenuLineValue("YELLOW", int(PreferencesContainer::Colors::Yellow), preferenceType));
	vector.push_back(MenuLineValue("PURPLE", int(PreferencesContainer::Colors::Purple), preferenceType));
}