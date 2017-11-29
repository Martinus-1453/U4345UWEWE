#pragma once
#include <string>

class Solution
{
public:
	int finishedNum;
	int visitedNum;
	double time;
	int maxDepth;
	bool solved;
	std::string path;


	Solution() { 
		finishedNum = 0;
		visitedNum = 0;
		solved = false;
	};
	~Solution();
};

