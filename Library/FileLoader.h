#pragma once
#ifndef FILELOADER_H
#define FILELOADER_H
#include "Board.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class FileLoader
{
public:
	FileLoader();
	static Board LoadFile(std::string path);
};

#endif // FILELOADER_H