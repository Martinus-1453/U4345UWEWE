#include "SolverBFS.h"

SolverBFS::SolverBFS(Board& _boardToSolve, Board& _boardSolved): Solver(_boardToSolve, _boardSolved), currentBoard(_boardToSolve)
{
	this->boardSolved = _boardSolved;
	this->boardToSolve = _boardToSolve;
}

Solution SolverBFS::SolveBoard(std::string _order)
{
	auto startTime = std::chrono::high_resolution_clock::now();
	
	this->order = _order;



	HashBoard(currentBoard); // czyli ktora

	while (!front.empty() && !solution.solved) {
		currentBoard = front.front();
		front.pop();
		ExplorePaths(currentBoard);
	}
	
	auto endTime = std::chrono::high_resolution_clock::now();
	auto timeDiff = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
	solution.time = (double)timeDiff / 1000.0;

	return solution;
}

void SolverBFS::ExplorePaths(Board board) {
	
	solution.maxDepth = std::max(solution.maxDepth, board.getDepth());
	
	if (IsSolved(board)) {
		solution.solved = true;
		solution.path = board.getPath();
		return;
	}

	for (char c : order) {
		if (c == 'L') {
			HashBoard(board.GetLeftChild());
		}
		if (c == 'R') {
			HashBoard(board.GetRightChild());
		}
		if (c == 'U') {
			HashBoard(board.GetUpChild());
		}
		if (c == 'D') {
			HashBoard(board.GetDownChild());
		}
	}
	solution.finishedNum++;
}

void SolverBFS::HashBoard(Board board) {
	if (board != NULL && explored.add(board)) {
		solution.visitedNum++;
		front.push(board);
	}
}