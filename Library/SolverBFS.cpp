#include "SolverBFS.h"


SolverBFS::SolverBFS(Node _nodeToSolve, Board _nodeSolved): Solver(_nodeToSolve, _nodeSolved), currentNode(_nodeToSolve)
{
	this->boardSolved = _nodeSolved;
	this->nodeToSolve = _nodeToSolve;
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
	
	solution.maxDepth = std::max(solution.maxDepth, node.GetDepth());
	
	if (IsSolved(node)) {
		solution.solved = true;
		solution.path = node.GetPath();
		return;
	}

	for (char c : order) {
		if (c == 'L') {
			HashNode(node.GetLeftChild());
		}
		if (c == 'R') {
			HashNode(node.GetRightChild());
		}
		if (c == 'U') {
			HashNode(node.GetUpChild());
		}
		if (c == 'D') {
			HashNode(node.GetDownChild());
		}
	}
	solution.finishedNum++;
}

void SolverBFS::HashNode(Node node) {
		solution.visitedNum++;
		front.push(node);
	}