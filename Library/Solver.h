#pragma once
#ifndef SOLVER_H
#define SOLVER_H

#include "Node.h"
#include "Solution.h"

class Solver
{
public:
	Solver(Node _nodeToSolve, Board _boardSolved);
	virtual ~Solver() = default;


	// Zwracanie stringa jako rozwiązanie. Format zwracany jeszcze do uzgodnienia : )
	virtual Solution SolveNode(std::string order) = 0;

protected:
	Solution solution;
	bool IsSolved(Node node);
	Node  nodeToSolve;
	Board  boardSolved;
};

#endif // SOLVER_H


