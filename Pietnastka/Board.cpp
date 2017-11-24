#include "Board.h"

Board::Board(const int _sizeHorizontal, const int _sizeVertical) : boardData(_sizeHorizontal*_sizeVertical)
{
	sizeRow = _sizeVertical;
	sizeColumn = _sizeHorizontal;
}

void Board::SwapIndicies(const int index1_c, const int index1_r, const int index2_c, const int index2_r)
{
	uint16_t temp = GetIndex(index1_c,index1_r);
	SetIndex(index1_c, index1_r, GetIndex(index2_c, index2_r));
	SetIndex(index2_c, index2_r, temp);
}

int Board::GetColumnSize()
{
	return sizeColumn;
}

int Board::GetRowSize()
{
	return sizeRow;
}

uint16_t Board::GetIndex(const int column, const int row)
{
	if (column < GetColumnSize() && row < GetRowSize())
	return boardData[(column*GetColumnSize()) + row];
}

std::vector<uint16_t> Board::GetRow(const int columnNumber)
{
	if(columnNumber < GetColumnSize())
	{
		std::vector<uint16_t>::const_iterator first = boardData.begin() + columnNumber * GetRowSize();
		std::vector<uint16_t>::const_iterator last = boardData.begin() + columnNumber * GetRowSize() + GetRowSize();
		return std::vector<uint16_t>(first, last);
	}
	return std::vector<uint16_t>();
}

void Board::SetIndex(const int column, const int row, uint16_t value)
{
	if (column < GetColumnSize() && row < GetRowSize())
		boardData[(column*GetColumnSize()) + row] = value;
}

void Board::SetRow(const int columnNumber, std::vector<uint16_t> row)
{
	if (columnNumber < GetColumnSize())
	{
		for (int i = 0; i < row.size(); ++i)
		{
			SetIndex(columnNumber, i, row[i]);
		}
	}
}
