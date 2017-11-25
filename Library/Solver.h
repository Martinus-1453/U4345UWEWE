#pragma once
#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"

class Solver
{
public:
	Solver(Board _boardToSolve, Board _boardSolved);
	virtual ~Solver() = default;

	// Zwracanie stringa jako rozwiązanie. Format zwracany jeszcze do uzgodnienia : )
	virtual std::string SolveBoard() = 0;

protected:
	Board  boardToSolve;
	Board  boardSolved;
};

#endif // SOLVER_H


