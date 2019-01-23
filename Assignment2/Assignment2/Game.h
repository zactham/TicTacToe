#pragma once
#include <iostream>
#include "Board.h"

class Game{

	public:
		Game();
		void checkCounter();
		bool gameOver = false;
		void startGame();
		void playGame();
		

	private:
		Board* b;
		int counterX;
		int counterO;
		int turnCounter;
		int xPosAI;
		int yPosAI;
		int xPosPlayer;
		int yPosPlayer;
		bool tieGame = false;
		bool playerWins = false;
		bool AIWins = false;
		void endGame();
		void checkGameOver();
		void AIMove();
		void setPlayerMove();
		void checkRows();
		void checkCols();
		void checkDiagonalsLeft();
		void checkDiagonalsRight();

		
};
