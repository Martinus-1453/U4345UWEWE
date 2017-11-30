#pragma once
#ifndef MOVELOGIC_H
#define MOVELOGIC_H

#include "Board.h"
#include "Index.h"

enum class Direction {L,R,U,D};

class Logic
{
public:
	static bool Move(Board* board, Direction direction, int index_x, int index_y);
	static bool Move(Board* board, Direction direction, Index index);
	
private:
	static void MoveLeft(Board* board, int index_x, int index_y);
	static void MoveRight(Board* board, int index_x, int index_y);
	static void MoveUp(Board* board, int index_x, int index_y);
	static void MoveDown(Board* board, int index_x, int index_y);
	static bool CanMove(Board* board, Direction direction, int index_x, int index_y);
};

#endif // MOVELOGIC_H
