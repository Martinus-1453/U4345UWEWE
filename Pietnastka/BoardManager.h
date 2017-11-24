#pragma once
#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H
#include "Board.h"

#include <iostream>
#include "Logic.h"

class BoardManager
{
public:
	BoardManager(int columns, int rows);

	void RandomizeValues();
	
	void Display();

	void MoveTest()
	{
		Logic::Move(&mBoard, Direction::D, 0, 0);
		Logic::Move(&mBoard, Direction::R, 1, 0);
	}

private:
	Board mBoard;
	Board solvedBoard;

	void SetOrederedValues();
};

#endif // BOARDMANAGER_H



