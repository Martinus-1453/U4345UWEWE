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
	void ExplorePaths(Node node);
	void HashNode(Node node);
	std::string order;
	std::queue<Node> front;
	Node currentNode;

public:
	SolverBFS(Node& _boardToSolve, Node& _boardSolved);
	::Solution SolveNode(std::string order) override;
};

#endif // SOLVERBFS_H


