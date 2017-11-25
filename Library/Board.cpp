#include "Board.h"

Board::Board(const int _sizeColumn, const int _sizeRow) : boardData(_sizeColumn*_sizeRow)
{
	sizeRow = _sizeRow;
	sizeColumn = _sizeColumn;
}

Board::Board(const Board& board): sizeColumn(board.sizeColumn), sizeRow(board.sizeRow), boardData(this->GetColumnSize()*this->GetRowSize())
{
}

Board& Board::operator=(Board other)
{
	std::swap(sizeColumn, other.sizeColumn);
	std::swap(sizeRow, other.sizeRow);
	//std::copy(other.boardData.begin(), other.boardData.end(), back_inserter(boardData));
	boardData = other.boardData;
	return *this;
}

void Board::SwapIndicies(const int index1_c, const int index1_r, const int index2_c, const int index2_r)
{
	uint16_t temp = GetIndexValue(index1_c,index1_r);
	SetIndex(index1_c, index1_r, GetIndexValue(index2_c, index2_r));
	SetIndex(index2_c, index2_r, temp);
}

void Board::SwapIndicies(const Index index1, const Index index2)
{
	uint16_t temp = GetIndexValue(index1);
	SetIndex(index1, GetIndexValue(index2));
	SetIndex(index2, temp);
}

int Board::GetColumnSize() const
{
	return sizeColumn;
}

int Board::GetRowSize() const
{
	return sizeRow;
}

Index Board::GetZeroIndex()
{
	for (int i = 0; i < GetColumnSize(); ++i)
	{
		for (int j = 0; j < GetRowSize(); ++i)
		{
			if (GetIndexValue(i, j) == 0) return Index(i, j);
		}
	}
	return Index();
}

uint16_t Board::GetIndexValue(const int column, const int row)
{
	if (column < GetColumnSize() && row < GetRowSize())
	return boardData[(column*GetColumnSize()) + row];
	return 0;
}

uint16_t Board::GetIndexValue(Index index)
{
	if (index.GetColumn() < GetColumnSize() && index.GetRow() < GetRowSize())
		return boardData[(index.GetColumn()*GetColumnSize()) + index.GetRow()];
	return 0;
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

void Board::SetIndex(Index index, uint16_t value)
{
	if (index.GetColumn() < GetColumnSize() && index.GetRow() < GetRowSize())
		boardData[(index.GetColumn()*GetColumnSize()) + index.GetRow()] = value;
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

void Board::SetSizeColumn(const int _sizeColumn)
{
	this->sizeColumn = _sizeColumn;
}

void Board::SetSizeRow(const int _sizeRow)
{
	this->sizeRow = _sizeRow;
}