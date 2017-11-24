#include "Index.h"
#include <memory>

Index::Index()
{
	column = 0;
	row = 0;
}

Index::Index(const Index& index): column(index.column), row(index.row)
{
}

Index::Index(int _x, int _y)
{
	column = _x;
	row = _y;
}

Index& Index::operator=(Index other)
{
	std::swap(column, other.column);
	std::swap(row, other.row);
	return *this;
}

bool Index::operator==(const Index & b) const
{
	if (GetRow() == b.GetRow() && GetColumn() == b.GetColumn()) return true;
	return false;
}

bool Index::operator!=(const Index & b) const
{
	if (GetRow() == b.GetRow() && GetColumn() == b.GetColumn()) return false;
	return true;
}

int Index::GetColumn() const
{
	return column;
}

int Index::GetRow() const
{
	return row;
}

void Index::SetColumn(int _column)
{
	column = _column;
}

void Index::SetRow(int _row)
{
	row = _row;
}

void Index::Set(int _column, int _row)
{
	column = _column;
	row = _row;
}

void Index::Set(Index index)
{
	column = index.GetColumn();
	row = index.GetRow();
}
