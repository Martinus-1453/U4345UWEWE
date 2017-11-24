#pragma once
#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H
#include "Board.h"
#include "Logic.h"
#include "FileLoader.h"

#include <iostream>


class BoardManager
{
public:
	BoardManager(int columns, int rows);
	BoardManager(std::string boardPath, std::string solvePath);

	void RandomizeValues();
	
	void Display();

	void MoveTest()
	{
		//Logic::Move(&mBoard, Direction::D, 0, 0);
		//Logic::Move(&mBoard, Direction::R, 1, 0);
		mBoard.SetRow(1, mBoard.GetRow(0));
	}

private:
	Board mBoard;
	Board solvedBoard;

	void SetOrederedValues();
};

#endif // BOARDMANAGER_H



