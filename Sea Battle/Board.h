#pragma once
#include <iostream>
#include "Logic.h"
#include "Helper.h"
using namespace std;

void fillBoard(char board[][10]) {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			board[i][j] = '~';
		}
	}
}
void showBoard(char board[][10], char empty_board[][10]) {
	system("cls");
	cout << " A B C D E F G H I J        A B C D E F G H I J" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << ' ';
		for (int j = 0; j < 10; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << i + 1 << "     ";
		if (i < 9) {
			cout << ' ';
		}
		for (int j = 0; j < 10; j++)
		{
			cout << empty_board[i][j] << " ";
		}
		cout << i + 1 << endl;
	}
}
void randomPlace(char board[][10]) {
	srand(time(NULL));
	int row, col;
	char direc;
	char directs[]{ 'H','V' };
	// 1 - x4
	do
	{
		row = rand() % 7;
		col = rand() % 7;
		direc = directs[rand() % 2];
	} while (!canPlace(board, row, col, 4, direc));
	placeShip(board, row, col, 4, direc);
	// 2 - x3
	for (int i = 0; i < 2; i++)
	{
		do
		{
			row = rand() % 8;
			col = rand() % 8;
			direc = directs[rand() % 2];
		} while (!canPlace(board, row, col, 3, direc));
		placeShip(board, row, col, 3, direc);
	}
	// 3 - 2x
	for (int i = 0; i < 3; i++)
	{
		do
		{
			row = rand() % 9;
			col = rand() % 9;
			direc = directs[rand() % 2];
		} while (!canPlace(board, row, col, 2, direc));
		placeShip(board, row, col, 2, direc);
	}
	// 4 - 1x
	for (int i = 0; i < 4; i++)
	{
		do
		{
			row = rand() % 10;
			col = rand() % 10;
			direc = directs[rand() % 2];
		} while (!canPlace(board, row, col, 1, direc));
		placeShip(board, row, col, 1, direc);
	}
}
void manualPlace(char board[][10], char empty_board[][10]) {
	int row, col;
	char col_ch;
	char direc;
	// 1 - x4
	while (true) {
		showBoard(board, empty_board);
		cout << "\n1 - 4xship\nDirection(H - Horizontal | V - Vertical)\nif you write V your ship will be directed right\nif you write H your ship will be directed down\nRow(1 - 10)\nCol(A - J)" << endl;
		cout << "\nDirection: ";
		cin >> direc;
		cout << "Row: ";
		cin >> row;
		cout << "Col: ";
		cin >> col_ch;
		col = letternumber(col_ch);
		if (canPlace(board, row - 1, col - 1, 4, direc)) {
			break;
		}
		cout << "\nYou can't put a ship here, try again\n" << endl;
		system("pause");
	}
	placeShip(board, row - 1, col - 1, 4, direc);
	// 2 - x3
	for (int i = 0; i < 2; i++)
	{
		while (true) {
			showBoard(board, empty_board);
			cout << "\n2 - 3xship\nDirection(H - Horizontal | V - Vertical)\nif you write V your ship will be directed right\nif you write H your ship will be directed down\nRow(1 - 10)\nCol(A - J)" << endl;
			cout << "\nDirection: ";
			cin >> direc;
			cout << "Row: ";
			cin >> row;
			cout << "Col: ";
			cin >> col_ch;
			col = letternumber(col_ch);
			if (canPlace(board, row - 1, col - 1, 3, direc)) {
				break;
			}
			cout << "\nYou can't put a ship here , try again\n" << endl;
			system("pause");
		}
		placeShip(board, row - 1, col - 1, 3, direc);
	}
	// 3 - x2
	for (int i = 0; i < 3; i++)
	{
		while (true) {
			showBoard(board, board);
			cout << "\n3 - 2xship\nDirection(H - Horizontal | V - Vertical)\nif you write V your ship will be directed right\nif you write H your ship will be directed down\nRow(1 - 10)\nCol(A - J)" << endl;
			cout << "\nDirection: ";
			cin >> direc;
			cout << "Row: ";
			cin >> row;
			cout << "Col: ";
			cin >> col_ch;
			col = letternumber(col_ch);
			if (canPlace(board, row - 1, col - 1, 3, direc)) {
				break;
			}
			cout << "\nYou can't put a ship here , try again\n" << endl;
			system("pause");
		}
		placeShip(board, row - 1, col - 1, 2, direc);
	}
	// 4 - x1
	for (int i = 0; i < 4; i++)
	{
		while (true) {
			showBoard(board, board);
			cout << "\n1 - 4xship\nRow(1 - 10)\nCol(A - J)" << endl;
			cout << "Row: ";
			cin >> row;
			cout << "Col: ";
			cin >> col;
			col = letternumber(col);
			if (canPlace(board, row - 1, col - 1, 1, direc)) {
				break;
			}
			cout << "\nYou can't put a ship here , try again\n" << endl;
			system("pause");
		}
		placeShip(board, row - 1, col - 1, 1, direc);
	}
}
