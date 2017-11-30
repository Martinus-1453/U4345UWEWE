#pragma once
#ifndef NODE_H
#define NODE_H

#include "Board.h"
#include "Logic.h"
#include <iostream>

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

	int GetDepth();


	//????????????????????????????????
	std::string GetPath();


private:
	Board parent;
	Board self;
	std::vector<Board> children;
	bool visited;
	int depth;
};

#endif // NODE_H



