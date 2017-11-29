#include "SolverBFS.h"

SolverBFS::SolverBFS(Board& _boardToSolve, Board& _boardSolved): Solver(_boardToSolve, _boardSolved)
{
	this->boardSolved = _boardSolved;
	this->boardToSolve = _boardToSolve;
}

Solution SolverBFS::SolveBoard(std::string _order)
{
	this->order = _order;

	//init time
	
	hashBoard(currentBoard); // czyli ktora

	while (!front.empty() && !solved) {
		currentBoard = front.front();
		front.pop();
		explorePaths(currentBoard);
	}
	//end time

	return solution;
}

void SolverBFS::explorePaths(Board board) {
	
	solution.maxDepth = std::max(solution.maxDepth, board.getDepth());
	
	if (isSolved(board)) {
		solution.solved = true;
		solution.path = board.getPath();
		return;
	}

	for (char c : order) {
		if (c == 'L') {
			hashBoard(board.GetLeftChild());
		}
		if (c == 'R') {
			hashBoard(board.GetRightChild());
		}
		if (c == 'U') {
			hashBoard(board.GetUpChild());
		}
		if (c == 'D') {
			hashBoard(board.GetDownChild());
		}
	}
	solution.finishedNum++;
}

void SolverBFS::hashBoard(Board board) {
	if (board != NULL && explored.add(board)) {
		solution.visitedNum++;
		front.push(board);
	}
}