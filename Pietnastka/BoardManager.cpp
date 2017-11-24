#include "BoardManager.h"

BoardManager::BoardManager(int columns, int rows): mBoard(columns, rows), solvedBoard(columns, rows)
{
	SetOrederedValues();
}

BoardManager::BoardManager(std::string boardPath, std::string solvePath): mBoard(4, 4), solvedBoard(4, 4)
{

}

void BoardManager::RandomizeValues()
{
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
			std::cout << mBoard.GetIndex(i, j) << " ";
		}
		std::cout << "\n";
	}
}
