#include "SaveLoadFile.h"
#include <Windows.h>
#include <iostream>
#include <string.h>
#include "Helper.h"
#include <conio.h>
#include <iomanip>
#include "Board.h"
#include "Logic.h"
#include <time.h>
#include "Game.h"
using namespace std;

int main() {
	char board[10][10]{}, bot_board[10][10]{}, empty_board[10][10]{};
	const char* playerfile = "player.txt";
	const char* botfile = "bot.txt";
	const char* emptyfile = "empty.txt";
	int player_ships = 4 + 3 + 3 + 2 + 2 + 2 + 1 + 1 + 1 + 1, bot_ships = 4 + 3 + 3 + 2 + 2 + 2 + 1 + 1 + 1 + 1;

	int menu = -1;
	while (true) {
		cout << "1 - New Game\n2 - Continue Last Game\n3 - Exit\n\n" << endl;
		cin >> menu;
		if (menu == 1) {
			fillBoard(board);
			fillBoard(empty_board);
			fillBoard(bot_board);
			randomPlace(bot_board);
			system("cls");
			placement(board, empty_board);
			break;
		}
		else if (menu == 2) {
			loadFile(board, playerfile);
			loadFile(bot_board, botfile);
			loadFile(empty_board, emptyfile);
			break;
		}
		else if (menu == 3) {
			return 0;
		}
	}
	showBoard(board, empty_board);
	int bot_state = 0, hit_row = -1, hit_col = -1;
	while (player_ships && bot_ships) {
		while (playerTurn(bot_board, empty_board))
		{
			showBoard(board, empty_board);
			bot_ships -= 1;
			saveFile(board, playerfile);
			saveFile(bot_board, botfile);
			saveFile(empty_board, emptyfile);
		}


		showBoard(board, empty_board);
		while (botTurn(board, bot_state, hit_row, hit_col))
		{
			showBoard(board, empty_board);
			player_ships -= 1;
			saveFile(board, playerfile);
			saveFile(bot_board, botfile);
			saveFile(empty_board, emptyfile);
		}


		showBoard(board, empty_board);
	}
	winorlose(player_ships, bot_ships);

	return 0;
}