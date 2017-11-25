#pragma comment(lib, "Library.lib") 
#include "../Library/BoardManager.h"
const int COLUMN_SIZE = 3;
const int ROW_SIZE = 3;

int main()
{
	BoardManager board_manager(COLUMN_SIZE, ROW_SIZE);
	
	//board_manager.SetBoard("4x4_01_00002.txt");
	board_manager.SetBoard("4x4_05_00028.txt");
	// Set solve method to BFS;
	board_manager.BFSTest();
	//
	board_manager.Display();
	std::cout << "\n ------------------- \n";
	board_manager.MoveTest();
	board_manager.Display();
	system("pause");
    return 0;
}

