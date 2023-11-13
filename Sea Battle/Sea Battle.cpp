#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include "board.h"
#include "Helper.h"
#include "Game.h"
#include "Logic.h"
using namespace std;





int main() {
	char board[10][10]{};
	fillBoard(board);
	randomPlace(board);
	//manualPlace(board);
	while (true)
	{
		showBoard(board);
		playerTurn(board);
		system("cls");

	}


}