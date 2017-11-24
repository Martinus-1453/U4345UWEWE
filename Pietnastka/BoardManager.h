#pragma once
#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H
#include "Board.h"

class BoardManager
{
public:
	BoardManager(int columns, int rows);

	void RandomizeValues();
	
	void Display();

private:
	Board mBoard;
	Board solvedBoard;

	void SetOrederedValues();
};

#endif // BOARDMANAGER_H



