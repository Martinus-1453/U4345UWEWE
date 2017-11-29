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
	void ExplorePaths(Board board);
	void HashBoard(Board board);
	std::string order;
	std::queue<Board> front;
	Board currentBoard;

public:
	SolverBFS(Board& _boardToSolve,Board& _boardSolved);
	::Solution SolveBoard(std::string order) override;
};

#endif // SOLVERBFS_H


