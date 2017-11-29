﻿#pragma once
#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"
#include "Solution.h"

class Solver
{
public:
	Solver(Board _boardToSolve, Board _boardSolved);
	virtual ~Solver() = default;


	// Zwracanie stringa jako rozwiązanie. Format zwracany jeszcze do uzgodnienia : )
	virtual Solution SolveBoard(std::string order) = 0;

protected:
	Solution solution;
	bool IsSolved(Board board);
	Board  boardToSolve;
	Board  boardSolved;
};

#endif // SOLVER_H


