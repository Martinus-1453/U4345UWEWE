#pragma once
#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>

#include "Index.h"

class Board
{
public:
	Board(const int _sizeColumn, const int _sizeRow);
	Board(const Board& board);
	Board& operator=(Board other);
	// Logic
	void SwapIndicies(const int index1_c, const int index1_r, const int index2_c, const int index2_r);
	void SwapIndicies(const Index index1, const Index index2);

	// Getters
	int GetColumnSize() const;
	int GetRowSize() const;
	Index GetZeroIndex();
	uint16_t GetIndexValue(const int column, const int row);
	uint16_t GetIndexValue(Index point);

	std::vector<uint16_t> GetRow(const int columnNumber);
	
	// Setters
	void SetIndex(const int column, const int row, uint16_t value);
	void SetIndex(Index index, uint16_t value);
	void SetRow(const int number, std::vector<uint16_t> row);

private:
	int sizeColumn, sizeRow;
	std::vector<uint16_t> boardData;
};


#endif // BOARD_H




