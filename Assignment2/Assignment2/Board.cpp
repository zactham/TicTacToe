#include <iostream>
#include "Board.h"
#include <stdlib.h> 


Board::Board()
{
	//SETS UP GAME BOARD
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			gameBoard[r][c] = '!';
		}
	}
	turnCounter = 0;
	while (!gameOver)
	{
		AIMove();
		printBoard();
		setPlayerMove();
		printBoard();
		turnCounter++;
		if (turnCounter > 2)
		{
			checkGameOver();
		}
		if (turnCounter == 9)
		{
			std::cout << "Tie Game";
			tieGame = true;
			break;
		}
	}
	if (!tieGame)
	{
		endGame();
	}
	int temp;
	std::cin >> temp;

	

	//DELETE ARRAYS AND NEW OBJECTS
}

void Board::AIMove()
{
	xPosAI = rand() % 3;
	yPosAI = rand() % 3;

	//cHECK IF NULL IN THE BOARD GRID
	while (gameBoard[xPosAI][yPosAI] != '!')
	{
		//GET RANDOM X AND RANDOM Y FROM 0-2
		xPosAI = rand() % 3;
		yPosAI = rand() % 3;
	}
	gameBoard[xPosAI][yPosAI] = 'X';
	
	std::cout << "AI puts an X in " << xPosAI << ", " << yPosAI << std::endl;
}

void Board::setPlayerMove()
{
	xPosPlayer = xPosAI;
	yPosPlayer = yPosAI;
	while (gameBoard[xPosPlayer][yPosPlayer] != '!')
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
	gameBoard[xPosPlayer][yPosPlayer] = 'O';
	
}

void Board::checkGameOver()
{
	//RUNS THROUGH GRID CHECKING IF THERE ARE 3 XS OR 3 Os
	checkRows();
	if (!gameOver)
	{
		checkCols();
	}
	else if (!gameOver)
	{
		checkDiagonals();
	}
}

void Board::checkRows()
{
	//TOP ROW
	counterX = 0;
	counterY = 0;
	

	for (int r = 0; r < 3; r++)
	{
		if (!gameOver)
		{
			for (int c = 0; c < 3; c++)
			{
				if (gameBoard[r][c] == 'X')
				{
					counterX++;
				}
				if (gameBoard[r][c] == 'O')
				{
					counterY++;
				}
			}
		}
		checkCounter();
	}
}

void Board::checkCols()
{
	for (int c = 0; c < 3; c++)
	{
		if (!gameOver)
		{
			for (int r = 0; c < 3; r++)
			{
				if (gameBoard[r][c] == 'X')
				{
					counterX++;
				}
				if (gameBoard[r][c] == 'O')
				{
					counterY++;
				}
			}
		}
		checkCounter();
	}
}

void Board::checkCounter()
{
	if (counterX == 3)
	{
		AIWins = true;
		gameOver = true;

	}
	if (counterY == 3)
	{
		playerWins = true;
		gameOver = true;

	}
}

void Board::checkDiagonals()
{
	for (int rc = 0; rc < 3; rc++)
	{
		if (gameBoard[rc][rc] == 'X')
		{
			counterX++;
		}
		if (gameBoard[rc][rc] == 'O')
		{
			counterY++;
		}
	}
	checkCounter();
}

void Board::endGame()
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

void Board::printBoard()
{
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			std::cout << gameBoard[r][c] << " ";
		}
		std::cout << "" << std::endl;
	}
}

