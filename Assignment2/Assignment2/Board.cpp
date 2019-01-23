#include <iostream>
#include "Board.h"
#include <stdlib.h> 


Board::Board()
{
	initBoard();
}

void Board::initBoard()
{
	//SETS UP GAME BOARD
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			gameBoard[r][c] = '!';
		}
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

