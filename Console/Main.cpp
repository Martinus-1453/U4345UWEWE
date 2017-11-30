#pragma comment(lib, "Library.lib") 
#include "../Library/BoardManager.h"
#include <chrono>
#include <iostream>
const int COLUMN_SIZE = 3;
const int ROW_SIZE = 3;

int main(int argc, char** argv)
{
	
	std::string strategy = argv[0];
	std::string parameter = argv[1];
	std::string startingTable = argv[2];
	std::string solutionPath = argv[3];
	std::string statisticsPath = argv[4];

	BoardManager board_manager(COLUMN_SIZE, ROW_SIZE);
	
	
	board_manager.SetBoard(startingTable);
	// Set solve method to BFS;
	board_manager.BFSTest();
	
	board_manager.Solve();

	board_manager.Display();
	std::cout << "\n ------------------- \n";
	board_manager.MoveTest();
	board_manager.Display();

	system("pause");
    return 0;
}

