// TicTacToe2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Game.h"

int main()
{
    Game* game = new Game();

    while (game->IsRunning())
    {
        game->Update();
    }
  
}

