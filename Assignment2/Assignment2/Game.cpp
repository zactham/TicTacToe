#include <iostream>
#include "Game.h"
#include "Board.h"
#include <time.h>

Game::Game() 
{
	//Intro 
	startGame();
	//Game mechanics begin
	playGame();
	
}

void Game:: startGame()
{
	std::cout << "Welcome to Tic Tac Toe" << std::endl;
}

void Game::playGame()
{
	b = new Board();//makes a board obj
	turnCounter = 0;
	while (!gameOver)
	{
		AIMove(); //ai picks a spot
		

		turnCounter++; //counts each time an ai makes a spot
		if (turnCounter > 1)
		{
			checkGameOver();//after 3 turns checks if someone won 
		}

		if (!gameOver)
		{
			setPlayerMove(); //player move


			if (turnCounter > 1)
			{
				checkGameOver();
			}

			//TIE GAME
			if (turnCounter == 5)
			{
				std::cout << "Tie Game";
				tieGame = true;
				gameOver = true;
			}
		}
	}
	if (!tieGame)
	{
		endGame();//prints final message
	}
	int temp;
	std::cin >> temp;
	delete b;
}

//Prints the final message based on who won
void Game::endGame()
{
	if (playerWins)
	{
		std::cout << "Congrats Player you have won";
	}
	else if (AIWins)
	{
		std::cout << "Game Over you have lost";
	}
}

//Uses the counter to determine winner
void Game::checkCounter()
{
	if (counterX == 3)
	{
		AIWins = true;
		gameOver = true;

	}
	if (counterO == 3)
	{
		playerWins = true;
		gameOver = true;

	}
}

void Game::checkGameOver()
{
	//RUNS THROUGH GRID CHECKING IF THERE ARE 3 XS OR 3 Os in each direction
	checkRows();
	if (!gameOver)
	{
		checkCols();
	}
	else if (!gameOver)
	{
		checkDiagonalsLeft();
	}
	else if (!gameOver)
	{
		checkDiagonalsRight();
	}
}

//Random X is placed on the board in a spot where nothing else is placed
void Game::AIMove()
{
	srand(time(NULL));
	do
	{
		xPosAI = rand() % 3;
		yPosAI = rand() % 3;
	} while (b->getPos(xPosAI, yPosAI) != '!');
	
	b->setPos(xPosAI, yPosAI, 'X');

	std::cout << "AI puts an X in " << xPosAI << ", " << yPosAI << std::endl;

	b->printBoard();
}

//Asks the player for specific spot if that spot is invalid it prompts for input again
void Game::setPlayerMove()
{
	xPosPlayer = xPosAI;
	yPosPlayer = yPosAI;
	while (b->getPos(xPosPlayer, yPosPlayer) != '!')
	{
		std::cout << "Enter player Row : ";
		std::cin >> xPosPlayer;
		while (xPosPlayer < 0 || xPosPlayer > 2)
		{
			std::cout << "Invalid Dimensions, Enter Again : ";
			std::cin >> xPosPlayer;
		}
		std::cout << "Enter player Col : ";
		std::cin >> yPosPlayer;
		while (yPosPlayer < 0 || yPosPlayer > 2)
		{
			std::cout << "Invalid Dimensions, Enter Again : ";
			std::cin >> yPosPlayer;
		}
	}
	b->setPos(xPosPlayer, yPosPlayer, 'O');
	b->printBoard();

}

//Checks each row for 3 Xs or Os
void Game::checkRows()
{
	for (int r = 0; r < 3; r++)
	{
		if (!gameOver)
		{
			counterX = 0;
			counterO = 0;

			for (int c = 0; c < 3; c++)
			{
				if (b->getPos(r, c) == 'X')
				{
					counterX++;
				}
				if (b->getPos(r, c) == 'O')
				{
					counterO++;
				}
			}
			checkCounter();
		}
		
	}
}

//Checks each col for 3 Xs or Os
void Game::checkCols()
{
	for (int c = 0; c < 3; c++)
	{
		if (!gameOver)
		{
			counterX = 0;
			counterO = 0;
			for (int r = 0; r < 3; r++)
			{
				if (b->getPos(r, c) == 'X')
				{
					counterX++;
				}
				if (b->getPos(r, c) == 'O')
				{
					counterO++;
				}
			}
			checkCounter();
		}
	}
}


//Checks diagonal from the left for 3 Xs or Os
void Game::checkDiagonalsLeft()
{
	counterX = 0;
	counterO = 0;
	for (int rc = 0; rc < 3; rc++)
	{
		if (b->getPos(rc, rc) == 'X')
		{
			counterX++;
		}
		if (b->getPos(rc, rc) == 'O')
		{
			counterO++;
		}
	}
	checkCounter();
}

//Checks diagonal from the right for 3 Xs or Os
void Game::checkDiagonalsRight()
{
	counterX = 0;
	counterO = 0;

	for (int rc = 2; rc > -1; rc--)
	{
		if (b->getPos(rc,rc) == 'X')
		{
			counterX++;
		}
		if (b->getPos(rc, rc) == 'O')
		{
			counterO++;
		}
	}
	checkCounter();
}


