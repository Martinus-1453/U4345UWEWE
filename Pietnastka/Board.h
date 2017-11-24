#pragma once
#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>

class Board
{
public:
	Board(const int _sizeColumn, const int _sizeRow);
	
	// Logic
	void SwapIndicies(const int index1_c, const int index1_r, const int index2_c, const int index2_r);

	// Getters
	int GetColumnSize();
	int GetRowSize();
	uint16_t GetIndex(const int column, const int row);
	std::vector<uint16_t> GetRow(const int columnNumber);
	
	// Setters
	void SetIndex(const int column, const int row, uint16_t value);
	void SetRow(const int number, std::vector<uint16_t> row);

private:
	int sizeColumn, sizeRow;
	std::vector<uint16_t> boardData;
};


#endif // BOARD_H




