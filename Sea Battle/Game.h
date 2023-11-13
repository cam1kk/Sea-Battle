#pragma once
#include <iostream>
#include "Helper.h"
#include "Logic.h"
#include "Board.h"
using namespace std;
void playerTurn(char board[][10]) {
	int row{};
	char col{};
	cout << "Row(1-10): ";
	cin >> row;
	cout << "Col(A-J): ";
	cin >> col;
	col = letternumber(col);
	col = col - 1;
	row = row - 1;
	while (row < 0 || row >= 10 || col < 0 || col >= 10 || board[row][col] == 'X' || board[row][col] == 'o') {
		cout << "Wrong coordinates try again\n\n" << endl;
		cout << "Row(1-10): ";
		cin >> row;
		cout << "Col(A-J): ";
		cin >> col;
	}
	if (board[row][col] == (char)254) {
		board[row][col] = 'X';
		cout << "Hit!" << endl;
		if (isSunk(board,row,col)) {
			sunkShip(board,row,col);
		}
	}
	else {
		board[row][col] = 'o';
		cout << "Miss!" << endl;
	}
}
void botTurn(char board[][10]) {
	srand(time(NULL));
	int row{};
	char col{};
	do
	{
		row = rand() % 10;
		col = rand() % 10;
	} while (board[row][col] == 'X' || board[row][col] == 'o');

	if (board[row][col] == (char)254) {
		cout << "Bot Hit!" << endl;
		board[row][col] = 'X';

	}
	else {
		cout << "Bot Miss!" << endl;
		board[row][col] = 'o';
	}
}
