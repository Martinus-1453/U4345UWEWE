#pragma once
#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <string>

#include "Index.h"
class Board;

class Board
{
public:
	Board(const int _sizeColumn, const int _sizeRow);
	Board(const Board& board);
	Board& operator=(Board other);


	friend bool operator==(const Board& lhs, const Board& rhs);

	friend bool operator!=(const Board& lhs, const Board& rhs);

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

	int getDepth() { return depth; }
	int getTotalCost() { return totalCost; }
	int getCost() { return cost; }
	
	
	// Setters
	void SetIndex(const int column, const int row, uint16_t value);
	void SetIndex(Index index, uint16_t value);
	void SetRow(const int number, std::vector<uint16_t> row);
	void SetSizeColumn(const int _sizeColumn);
	void SetSizeRow(const int _sizeRow);

	void ResizeBoardData();

	void setDepth(int _depth) { this->depth = _depth; }
	void setCost(int _cost) { this->cost = _cost; }
	void setTotalCost(int _totalCost) { this->totalCost = _totalCost; }
	

private:
	int sizeColumn, sizeRow;
	std::vector<uint16_t> boardData;
	
	int depth;
	int cost;
	int totalCost;

};


#endif // BOARD_H




