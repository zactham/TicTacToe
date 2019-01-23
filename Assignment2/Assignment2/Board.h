#pragma once
#include <iostream>


class Board
{
public:
	
	Board();
	char getPos(int r, int c);
	void setPos(int r, int c, char symbol);
	void printBoard();
	

private:
	void initBoard();
	char gameBoard[3][3] = {};
	
	
	
	
	
	
	


};