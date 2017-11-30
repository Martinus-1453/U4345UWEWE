#include "Solver.h"

Solver::Solver(Node _nodeToSolve, Board _boardSolved): nodeToSolve(_nodeToSolve), boardSolved(_boardSolved)
{
}

bool Solver::IsSolved(Node _node)
{
	return boardSolved == _node.GetSelf();
}

