#include "SolverBFS.h"

SolverBFS::SolverBFS(Node& _boardToSolve, Node& _boardSolved): Solver(_boardToSolve, _boardSolved), currentNode(_boardToSolve)
{
	this->boardSolved = _boardSolved;
	this->boardToSolve = _boardToSolve;
}

Solution SolverBFS::SolveNode(std::string _order)
{
	auto startTime = std::chrono::high_resolution_clock::now();
	
	this->order = _order;



	HashNode(currentNode); // czyli ktora

	while (!front.empty() && !solution.solved) {
		currentNode = front.front();
		front.pop();
		ExplorePaths(currentNode);
	}
	
	auto endTime = std::chrono::high_resolution_clock::now();
	auto timeDiff = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
	solution.time = (double)timeDiff / 1000.0;

	return solution;
}

void SolverBFS::ExplorePaths(Node node) {
	
	solution.maxDepth = std::max(solution.maxDepth, node.getDepth());
	
	if (IsSolved(node)) {
		solution.solved = true;
		solution.path = node.getPath();
		return;
	}

	for (char c : order) {
		if (c == 'L') {
			HashBoard(node.GetLeftChild());
		}
		if (c == 'R') {
			HashBoard(node.GetRightChild());
		}
		if (c == 'U') {
			HashBoard(node.GetUpChild());
		}
		if (c == 'D') {
			HashBoard(node.GetDownChild());
		}
	}
	solution.finishedNum++;
}

void SolverBFS::HashNode(Node node) {
	if (node != NULL && explored.add(node)) {
		solution.visitedNum++;
		front.push(node);
	}
}