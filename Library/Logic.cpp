#include "Logic.h"

bool Logic::Move(Board * board, Direction direction, int index_x, int index_y)
{

	switch (direction)
	{
	case Direction::L:
		if (CanMove(board, direction, index_x, index_y)) 
		{
			MoveLeft(board, index_x, index_y);
			return true;
		}
		break;
	case Direction::R:
		if (CanMove(board, direction, index_x, index_y))
		{
			MoveRight(board, index_x, index_y);
			return true;
		}
		break;
	case Direction::U:
		if (CanMove(board, direction, index_x, index_y))
		{
			MoveUp(board, index_x, index_y);
			return true;
		}
		break;
	case Direction::D:
		if (CanMove(board, direction, index_x, index_y))
		{
			MoveDown(board, index_x, index_y);
			return true;
		}
		break;
	}

	return false;
}

void Logic::MoveLeft(Board* board, int index_x, int index_y)
{
	
	board->SwapIndicies(index_x, index_y, index_x, index_y - 1);
}

void Logic::MoveRight(Board* board, int index_x, int index_y)
{
	board->SwapIndicies(index_x, index_y, index_x, index_y + 1);
}

void Logic::MoveUp(Board* board, int index_x, int index_y)
{
	board->SwapIndicies(index_x, index_y, index_x - 1, index_y);

}

void Logic::MoveDown(Board* board, int index_x, int index_y)
{
	
	board->SwapIndicies(index_x, index_y, index_x + 1, index_y);

}

bool Logic::CanMove(Board* board, Direction direction, int index_x, int index_y)
{
	switch(direction)
	{
	case Direction::L:
		if (index_x == 0) return false;
		break;
	case Direction::R:
		if (index_x == board->GetColumnSize() - 1) return false;
		break;
	case Direction::U:
		if (index_y == 0) return false;
		break;
	case Direction::D:
		if (index_y == board->GetRowSize() - 1) return false;
		break;
	}
	return true;
}
