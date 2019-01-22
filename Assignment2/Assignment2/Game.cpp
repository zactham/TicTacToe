#include <iostream>
#include "Game.h"
#include "Board.h"

Game::Game() 
{
	startGame();
	Board* b = new Board();
	delete b;
}

void Game:: startGame()
{
	std::cout << "Welcome to Tic Tac Toe" << std::endl;
}

