#include "FileLoader.h"

FileLoader::FileLoader()
{
}

Board FileLoader::LoadFile(std::string path) {
	
	int x = 0, y = 0;

	uint16_t input;
	
	std::vector<uint16_t> row;
	std::ifstream inputReader;
	inputReader.open(path, std::ios::in);
	if (inputReader.good()) {
		inputReader >> x >> y;
		Board board(x, y);
		for (int i = 0; i < x; i++) {
			row.clear();
			row.resize(0);
			for (int j = 0; j < y; j++) {
				inputReader >> input;
				row.push_back(input);
			}
			board.SetRow(i, row);
		}
		inputReader.close();
		return board;
	}

	inputReader.close();
	return Board(0,0);
}
