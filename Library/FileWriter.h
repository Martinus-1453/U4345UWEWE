

#pragma once
#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileWriter
{
public:
	FileWriter();
	~FileWriter();

	void LoadToFile(std::string path, std::vector<std::string> stringVec);
};

#endif // FILEWRITER_H



