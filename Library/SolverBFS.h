#pragma once
#ifndef SOLVERBFS_H
#define SOLVERBFS_H
#include "Solver.h"

class SolverBFS : public Solver
{
public:
	SolverBFS(Board& _boardToSolve,Board& _boardSolved);

	std::string SolveBoard() override;
};

#endif // SOLVERBFS_H


