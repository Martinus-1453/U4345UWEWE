#pragma once
#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H
#include "Board.h"
#include "Logic.h"
#include "FileLoader.h"
#include "Solver.h"
#include "Solution.h"
// Solve Methods
#include "SolverBFS.h"

//
#include <iostream>
#include <string>

class BoardManager
{
public:
	BoardManager(int columns, int rows);
	BoardManager(std::string boardPath, std::string solvePath);

	void RandomizeValues();
	
	void Display();

	void MoveTest()
	{
		Logic::Move(&mBoard, Direction::D, 0, 0);
		Logic::Move(&mBoard, Direction::R, 1, 0);
		//mBoard.SetRow(1, mBoard.GetRow(0));
	}

	void BFSTest()
	{
		SolverBFS* p = &BFS;
		SetSolver(p);
	}

	void SetBoard(std::string path);

	void SetSolver(Solver* newSolver);

	void Solve();

private:
	Board mBoard;
	Board solvedBoard;
	Solver* currentSolver;
	Solution solution;
	// Solvers
	SolverBFS BFS;

	//
	void SetOrederedValues();
	void InitBoardValues(Board& board);
};

#endif // BOARDMANAGER_H



