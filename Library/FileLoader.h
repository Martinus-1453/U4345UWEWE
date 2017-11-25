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
	static void LoadFile(std::string path, Board& board);
};

#endif // FILELOADER_H