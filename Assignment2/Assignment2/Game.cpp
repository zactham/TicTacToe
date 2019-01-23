#include <iostream>
#include "Game.h"
#include "Board.h"

Game::Game() 
{
	startGame();
	playGame();
	
}

void Game:: startGame()
{
	std::cout << "Welcome to Tic Tac Toe" << std::endl;
}

void Game::playGame()
{
	b = new Board();
	turnCounter = 0;
	while (!gameOver)
	{
		AIMove();
		

		turnCounter++;
		if (turnCounter > 1)
		{
			checkGameOver();
			std::cout << "After AI" << std::endl;
		}

		if (!gameOver)
		{
			setPlayerMove();


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
		endGame();
	}
	int temp;
	std::cin >> temp;
	delete b;
}

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
	//RUNS THROUGH GRID CHECKING IF THERE ARE 3 XS OR 3 Os
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

void Game::AIMove()
{
	do
	{
		xPosAI = rand() % 3;
		yPosAI = rand() % 3;
	} while (b->gameBoard[xPosAI][yPosAI] != '!');
	
	b->gameBoard[xPosAI][yPosAI] = 'X';

	std::cout << "AI puts an X in " << xPosAI << ", " << yPosAI << std::endl;

	b->printBoard();
}

void Game::setPlayerMove()
{
	xPosPlayer = xPosAI;
	yPosPlayer = yPosAI;
	while (b->gameBoard[xPosPlayer][yPosPlayer] != '!')
	{
		std::cout << "Enter player X : ";
		std::cin >> xPosPlayer;
		while (xPosPlayer < 0 || xPosPlayer > 2)
		{
			std::cout << "Invalid Dimensions, Enter Again : ";
			std::cin >> xPosPlayer;
		}
		std::cout << "Enter player Y : ";
		std::cin >> yPosPlayer;
		while (yPosPlayer < 0 || yPosPlayer > 2)
		{
			std::cout << "Invalid Dimensions, Enter Again : ";
			std::cin >> yPosPlayer;
		}
	}
	b->gameBoard[xPosPlayer][yPosPlayer] = 'O';
	b->printBoard();

}

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
				if (b->gameBoard[r][c] == 'X')
				{
					counterX++;
				}
				if (b->gameBoard[r][c] == 'O')
				{
					counterO++;
				}
			}
			checkCounter();
		}
		
	}
}

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
				if (b->gameBoard[r][c] == 'X')
				{
					counterX++;
				}
				if (b->gameBoard[r][c] == 'O')
				{
					counterO++;
				}
			}
			checkCounter();
		}
	}
}



void Game::checkDiagonalsLeft()
{
	counterX = 0;
	counterO = 0;
	for (int rc = 0; rc < 3; rc++)
	{
		if (b->gameBoard[rc][rc] == 'X')
		{
			counterX++;
		}
		if (b->gameBoard[rc][rc] == 'O')
		{
			counterO++;
		}
	}
	checkCounter();
}

void Game::checkDiagonalsRight()
{
	counterX = 0;
	counterO = 0;

	for (int rc = 2; rc > -1; rc--)
	{
		if (b->gameBoard[rc][rc] == 'X')
		{
			counterX++;
		}
		if (b->gameBoard[rc][rc] == 'O')
		{
			counterO++;
		}
	}
	checkCounter();
}


