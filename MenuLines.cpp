#include "MenuLines.h"
#include "PreferencesContainer.h"

//Main menu state
NewGameMenuLine::NewGameMenuLine(MenuState& menuState_) : MenuLine(menuState_)
{
	text = "New Game";
}

NewGameMenuLine ::~NewGameMenuLine()
{
	MenuLine::~MenuLine();
}

void NewGameMenuLine::OnEnterPressed()
{
	menuState->Deactivate();
	Game::ChangeState(int(Game::GameStates::ChooseXorO));
}

PreferenceMenuLine::PreferenceMenuLine(MenuState& menuState_, MenuState& preferanceState_) : MenuLine(menuState_)
{
	text = "Preferences";
	preferenceState = &preferanceState_;
}

PreferenceMenuLine::~PreferenceMenuLine()
{
	MenuLine::~MenuLine();
}

void PreferenceMenuLine::OnEnterPressed()
{
	menuState->Deactivate();
	preferenceState->SetExitState(Game::GetState());
	Game::ChangeState(int(Game::GameStates::Preferences));

}

LoadMenuLine::LoadMenuLine(MenuState& menuState_, PlayState& playState_) : MenuLine(menuState_)
{
	text = "Load Game";
	playState = &playState_;
}

LoadMenuLine::~LoadMenuLine()
{
	MenuLine::~MenuLine();
}

void LoadMenuLine::OnEnterPressed()
{
	if (playState->Load())
	{
		menuState->Deactivate();
		Game::ChangeState(int(Game::GameStates::Play));
	}
	else
	{
		std::cout << "File not found!" << std::endl;
	}
}

ExitMenuLine::ExitMenuLine(MenuState& menuState_) : MenuLine(menuState_)
{
	text = "Exit Game";
}

ExitMenuLine ::~ExitMenuLine()
{
	MenuLine::~MenuLine();
}

void ExitMenuLine::OnEnterPressed()
{
	Game::SetIsRunning(false);
}

//Prefernces menu state
ColorsMenuLine::ColorsMenuLine(MenuState& menuState_) : MenuLine(menuState_)
{
	text = "Colors";
}

ColorsMenuLine ::~ColorsMenuLine()
{
	MenuLine::~MenuLine();
}

void ColorsMenuLine::OnEnterPressed()
{
	menuState->Deactivate();
	Game::ChangeState(int(Game::GameStates::ChooseColors));
}

SavePreferencesMenuLine::SavePreferencesMenuLine(MenuState& menuState_) : MenuLine(menuState_)
{
	text = "[SAVE]";
}

SavePreferencesMenuLine ::~SavePreferencesMenuLine()
{
	MenuLine::~MenuLine();
}

void SavePreferencesMenuLine::OnEnterPressed()
{

	PreferencesContainer::GetInstance().Save();
	menuState->Exit();
}

// Choose X or O state
XMenuLine::XMenuLine(MenuState& menuState_) : MenuLine(menuState_)
{
	text = "X";
}

XMenuLine ::~XMenuLine()
{
	MenuLine::~MenuLine();
}

void XMenuLine::OnEnterPressed()
{
	PreferencesContainer::GetInstance().SetPlayerMark('X');
	menuState->Deactivate();
	Game::ChangeState(int(Game::GameStates::Play));
}

OMenuLine::OMenuLine(MenuState& menuState_) : MenuLine(menuState_)
{
	text = "O";
}

OMenuLine ::~OMenuLine()
{
	MenuLine::~MenuLine();
}

void OMenuLine::OnEnterPressed()
{
	PreferencesContainer::GetInstance().SetPlayerMark('O');
	menuState->Deactivate();
	Game::ChangeState(int(Game::GameStates::Play));
}

//Pause menu state
RestartGameMenuLine::RestartGameMenuLine(MenuState& menuState_, PlayState& playState_) : MenuLine(menuState_)
{
	text = "Restart Game";
	playState = &playState_;
}

RestartGameMenuLine::~RestartGameMenuLine()
{
	MenuLine::~MenuLine();
}

void RestartGameMenuLine::OnEnterPressed()
{
	playState->Restart();
	menuState->Deactivate();
	Game::ChangeState(int(Game::GameStates::Play));
}

SaveGameMenuLine::SaveGameMenuLine(MenuState& menuState_, PlayState& playState_) : MenuLine(menuState_)
{
	text = "Save Game";
	playState = &playState_;
}

SaveGameMenuLine::~SaveGameMenuLine()
{
	MenuLine::~MenuLine();
}

void SaveGameMenuLine::OnEnterPressed()
{
	playState->Save();
	menuState->Exit();
}

ExitToMainMenuMenuLine::ExitToMainMenuMenuLine(MenuState& menuState_, PlayState& playState_) : MenuLine(menuState_)
{
	text = "Exit to main menu";
	playState = &playState_;
}

ExitToMainMenuMenuLine::~ExitToMainMenuMenuLine()
{
	MenuLine::~MenuLine();
}

void ExitToMainMenuMenuLine::OnEnterPressed()
{
	//PlayState reset ?
	playState->Restart();
	menuState->Deactivate();
	Game::ChangeState(int(Game::GameStates::MainMenu));
}