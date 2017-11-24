#pragma once
#ifndef INDEX_H
#define INDEX_H

class Index
{
public:
	Index();
	Index(const Index& index);
	Index(int _x, int _y);
	Index& operator=(Index other);
	bool Index::operator==(const Index &b) const;
	bool Index::operator!=(const Index &b) const;

	int GetColumn() const;
	int GetRow() const;

	void SetColumn(int _column);
	void SetRow(int _row);
	void Set(int _column, int _row);
	void Set(Index index);

private:
	int column;
	int row;
};
#endif // INDEX_H






