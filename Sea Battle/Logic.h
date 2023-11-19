#pragma once
#include <iostream>
using namespace std;
bool canPlace(char board[][10], int row, int col, int shipsize, char direc) {
	if (direc != 'H' && direc != 'V' || row < 0 || row > 9 || col < 0 || col > 9) {
		return false;
	}
	if (direc == 'V' && row + shipsize > 10 ||
		direc == 'H' && col + shipsize > 10) {
		return false;
	}

	for (int i = max(0, row - 1); i <= (direc == 'V' ? row + shipsize : min(9, row + 1)); i++)
	{
		for (int j = max(0, col - 1); j <= (direc == 'H' ? col + shipsize : min(9, col + 1)); j++)
		{
			if (board[i][j] != '~') {
				return false;
			}
		}
	}
	return true;
}
void placeShip(char board[][10], int row, int col, int shipsize, char direc) {
	if (direc == 'H') {
		for (int i = 0; i < shipsize; i++)
		{
			board[row][col + i] = (char)254;
		}
	}
	else if (direc == 'V') {
		for (int i = 0; i < shipsize; i++)
		{
			board[row + i][col] = (char)254;
		}
	}
}
int findShipSize(char board[][10], int row, int col) {
	int size = 1;
	for (int i = row + 1; i < 10 && board[i][col] == 'X'; ++i) {
		size++;
	}
	for (int i = row - 1; i >= 0 && board[i][col] == 'X'; --i) {
		size++;
	}
	for (int i = col + 1; i < 10 && board[row][i] == 'X'; ++i) {
		size++;
	}
	for (int i = col - 1; i >= 0 && board[row][i] == 'X'; --i) {
		size++;
	}
	return size;
}
bool isSunk(char board[][10], int col, int row) {
	int col2 = col;
	int row2 = row;
	// up
	while (true)
	{
		if (row - 1 >= 0) {
			if (board[row - 1][col] == (char(254))) return false;
			else if (board[row - 1][col] == 'X') row = row - 1;
			else break;
		}
		else break;
	}
	row = row2;

	// down
	while (true)
	{
		if (row + 1 <= 9) {
			if (board[row + 1][col] == (char(254))) return false;

			else if (board[row + 1][col] == 'X') row = row + 1;

			else break;
		}
		else break;
	}
	row = row2;

	// left
	while (true)
	{
		if (col - 1 >= 0) {
			if (board[row][col - 1] == (char(254))) return false;
			else if (board[row][col - 1] == 'X') col = col - 1;
			else break;
		}
		else break;
	}
	col = col2;

	// right
	while (true)
	{
		if (col + 1 <= 9) {
			if (board[row][col + 1] == (char(254))) return false;
			else if (board[row][col + 1] == 'X') col = col + 1;
			else break;
		}
		else break;
	}
	col = col2;
	return true;
}
void shipSunk(char board[][10], int row, int col) {
	while (row - 1 >= 0) {
		if (board[row - 1][col] == '~' || board[row - 1][col] == 'o') break;

		row = row - 1;
	}

	while (col - 1 >= 0) {
		if (board[row][col - 1] == '~' || board[row][col - 1] == 'o') break;

		col = col - 1;
	}

	int directs[][2] = { {-1,-1}, {-1,0}, {-1,1},
						{0,-1},  {0,0},  {0,1},
						{1,-1},  {1,0},  {1,1} };

	int shipsize = findShipSize(board, row, col);
	int newposR = row, newposC = col;
	int changeR = row, changeC = col;
	for (int i = 0; i < shipsize; i++)
	{
		for (int j = 0; j < 9; j++) {
			changeR = row;
			changeC = col;

			changeR = changeR + directs[j][0];
			changeC = changeC + directs[j][1];

			if (directs[j][1] == 0 && directs[j][0] == 0) board[changeR][changeC] = 'S';

			else if (changeR >= 0 && changeR <= 9 && changeC >= 0 && changeC <= 9) {

				if (board[changeR][changeC] != 'S') {
					board[changeR][changeC] = 'o';
				}
				else if (board[changeR][changeC] == 'X') {
					newposR = changeR;
					newposC = changeC;
				}
			}
			changeR = changeR - directs[j][0];
			changeC = changeC - directs[j][1];
		}
		row = newposR;
		col = newposC;
	}
}