#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#pragma once
class FileWriter
{
public:
	FileWriter();
	~FileWriter();

	void LoadToFile(std::string path, std::vector<std::string> stringVec);
};

