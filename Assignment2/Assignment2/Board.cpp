#include <iostream>
#include "Board.h"
#include <stdlib.h> 


Board::Board()
{
	initBoard();
}

//Creates a board w ! symbolizing blank spots
void Board::initBoard()
{
	//SETS UP GAME BOARD
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			setPos(r, c, '!');
		}
	}
}

//Prints the board in a grid
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

char Board::getPos(int r, int c)
{
	return gameBoard[r][c];
}

void Board::setPos(int r, int c, char symbol)
{
	gameBoard[r][c] = symbol;
}

