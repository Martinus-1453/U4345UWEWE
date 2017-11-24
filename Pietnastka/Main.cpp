#include "BoardManager.h"

const int COLUMN_SIZE = 4;
const int ROW_SIZE = 4;

int main()
{
	BoardManager board_manager(COLUMN_SIZE, ROW_SIZE);
	board_manager.Display();
	std::cout << "\n ------------------- \n";
	board_manager.MoveTest();
	board_manager.Display();
	system("pause");
    return 0;
}

