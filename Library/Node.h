#pragma once
#ifndef NODE_H
#define NODE_H

#include "Board.h"

class Node
{
public:
	Node(Board _parent, Board _self);

	Board GetParent() const;

	Board GetSelf() const;

	std::vector<Board> GetChildren() const;

	bool IsVisited() const;

	int GetDepth() const;

	Node GetLeftChild();
	Node GetRightChild();
	Node GetUpChild();
	Node GetDownChild();

	int getDepth();


	//????????????????????????????????
	//getPath()


private:
	Board parent;
	Board self;
	std::vector<Board> children;
	bool visited;
	int depth;
};

#endif // NODE_H



