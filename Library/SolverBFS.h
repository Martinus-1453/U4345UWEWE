#pragma once
#ifndef SOLVERBFS_H
#define SOLVERBFS_H
#include "Solver.h"
#include <string>
#include <algorithm>
#include <queue>
#include <chrono>

class SolverBFS : public Solver
{
private:
	Solution solution;
	void explorePaths(Board board);
	void hashBoard(Board board);
	std::string order;
	std::queue<Board> front;
	Board currentBoard;

public:
	SolverBFS(Board& _boardToSolve,Board& _boardSolved);

	Solution SolveBoard(std::string order) override;
};

#endif // SOLVERBFS_H


