#include "Node.h"


Node::Node(Board _parent, Board _self): parent(_parent), self(_self), visited(false), depth(0)
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

Node Node::GetLeftChild()
{
	Board temp = this->GetSelf();
	Logic::Move(temp, Direction::L, temp.GetZeroIndex());
	return Node(this->GetSelf(), temp);
}

Node Node::GetRightChild()
{
	return *this;
}

Node Node::GetUpChild()
{
	return *this;
}

Node Node::GetDownChild()
{
	return *this;
}

int Node::GetDepth()
{
	return 0;
}

std::string Node::GetPath()
{
	return " ";
}
