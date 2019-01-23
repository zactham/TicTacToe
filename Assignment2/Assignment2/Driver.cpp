#include <iostream>
#include "Game.h"

//Runs the tic tac toe game
int main()
{
	Game* game = new Game();
	game->startGame();
	game->playGame();
	delete game;
}