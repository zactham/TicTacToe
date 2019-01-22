#pragma once
#include <iostream>


class Board
{
public:
	char gameBoard[3][3] = {};
	Board();

private:
	int xPosAI;
	int yPosAI;
	int xPosPlayer;
	int yPosPlayer;
	int counterX;
	int counterY;
	int turnCounter;
	bool gameOver = false;
	bool playerWins = false;
	bool AIWins = false;
	bool tieGame = false;
	void AIMove();
	void setPlayerMove();
	void checkGameOver();
	void checkRows();
	void checkCols();
	void checkDiagonals();
	void checkCounter();
	void endGame();
	void printBoard();


};