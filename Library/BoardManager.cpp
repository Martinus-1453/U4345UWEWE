#include "BoardManager.h"


BoardManager::BoardManager(int columns, int rows): mBoard(columns, rows), solvedBoard(columns, rows), currentSolver(nullptr), BFS(Node(Board(0,0),mBoard), solvedBoard)
{
	SetOrederedValues();
}

BoardManager::BoardManager(std::string boardPath, std::string solvePath): mBoard(4, 4), solvedBoard(4, 4), currentSolver(nullptr), BFS(Node(Board(0, 0), mBoard),solvedBoard)
{
}

void BoardManager::RandomizeValues()
{
}

void BoardManager::SetBoard(std::string path)
{
	FileLoader::LoadFile(path, mBoard);

	solvedBoard.SetSizeColumn(mBoard.GetColumnSize());
	solvedBoard.SetSizeRow(mBoard.GetRowSize());
	solvedBoard.ResizeBoardData();
	InitBoardValues(solvedBoard);
}

void BoardManager::SetSolver(Solver* newSolver)
{
	currentSolver = newSolver;
}

void BoardManager::Solve() {
	solution = currentSolver->SolveNode("LUDR");

}

void BoardManager::SetOrederedValues()
{
	uint16_t count = 1;
	for (int i = 0 ; i < mBoard.GetColumnSize(); ++i)
	{
		for (int j = 0; j < mBoard.GetRowSize(); ++j)
		{
			mBoard.SetIndex(i,j,count);
			solvedBoard.SetIndex(i, j, count);
				count++;
		}
	}
	mBoard.SetIndex(mBoard.GetColumnSize() - 1, mBoard.GetRowSize() - 1, 0);
	solvedBoard.SetIndex(mBoard.GetColumnSize() - 1, mBoard.GetRowSize() - 1, 0);
			
}

void BoardManager::Display()
{
	for (int i = 0; i < mBoard.GetColumnSize(); ++i)
	{
		for (int j = 0; j < mBoard.GetRowSize(); ++j)
		{
			std::cout << mBoard.GetIndexValue(i, j) << " ";
		}
		std::cout << "\n";
	}
}

void BoardManager::InitBoardValues(Board& board) {

	uint16_t count = 1;
	for (int i = 0; i < board.GetColumnSize(); ++i)
	{
		for (int j = 0; j < board.GetRowSize(); ++j)
		{
			board.SetIndex(i, j, count);
			
			count++;
		}
	}
	board.SetIndex(board.GetColumnSize() - 1, board.GetRowSize() - 1, 0);
}