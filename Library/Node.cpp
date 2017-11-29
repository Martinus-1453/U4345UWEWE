#include "Node.h"


Node::Node(Board _parent, Board _self): parent(_parent), self(_self), visited(false)
{
}

Board Node::GetParent() const
{
	return parent;
}

Board Node::GetSelf() const
{
	return self;
}

std::vector<Board> Node::GetChildren() const
{
	return children;
}

bool Node::IsVisited() const
{
	return visited;
}

int Node::GetDepth() const
{
	return depth;
}
