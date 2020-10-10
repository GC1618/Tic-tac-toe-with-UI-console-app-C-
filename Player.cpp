#include "Player.h"
#include "Board.h"
#include "PlayState.h"

Player::Player(PlayState& playState_, Board& board_)
{
	playState = &playState_;
	board = &board_;
	isPlayerTurn = true;
}

Player::~Player()
{

}

bool Player::IsPlayerTurn()
{
	return isPlayerTurn;
}

void Player::SetIsPlayerTurn(bool isPlayerTurn_)
{
	isPlayerTurn = isPlayerTurn_;

}

void Player::OnEnterPressed()
{
	if (board->PlayerPlaceMark())
	{
		SetIsPlayerTurn(false);
	}
}

void Player::OnEscPressed()
{
	playState->Exit();
}

void Player::OnUpArrowPressed()
{
	board->MoveUp();
}

void Player::OnDownArrowPressed()
{
	board->MoveDown();
}

void Player::OnLeftArrowPressed()
{
	board->MoveLeft();
}

void Player::OnRightArrowPressed()
{
	board->MoveRight();
}