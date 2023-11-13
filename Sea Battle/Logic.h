#pragma once
#include <iostream>
using namespace std;
bool canPlace(char board[][10], int row, int col, int shipsize, char direc) {
	if (direc == 'H' && col + shipsize > 10) {
		return false;
	}
	else if (direc == 'V' && row + shipsize > 10) {
		return false;
	}
	for (int i = -1; i <= shipsize; i++)
	{
		for (int j = -1; j <= shipsize; j++)
		{
			int row2 = row + i;
			int col2 = col + j;
			if (row2 >= 0 && row2 < 10 && col2 >= 0 && col2 < 10) {
				if (board[row2][col2] != '~') {
					return false;
				}
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
void smart(char board[][10], int row, int col) {

}
bool isSunk(char board[][10], int row, int col) {
	char symb = board[row][col];

	int top = row, bottom = row;
	while (top >= 0 && board[top][col] == symb) 
	{
		--top;
	}
	while (bottom < 10 && board[bottom][col] == symb)
	{
		++bottom;
	}
	
	int left = col, right = col;
	while (left >= 0 && board[row][left] == symb)
	{
		--left;
	}
	while (right < 10 && board[row][right] == symb)
	{
		++right;
	}
	if (bottom - top - 1 > 0 || right - left - 1 > 0) {
		return true;
	}
	else {
		return false;
	}
}
void sunkShip(char board[][10], int row, int col) {
	for (int i = row - 1; i <+ row + 1; i++)
	{
		for (int j = col - 1; j <= col + 1; i++)
		{
			if (i >= 0 && i < 10 && j >= 0 && j < 10) {
				if (board[i][j] != 'X') {
					board[i][j] = 'o';
				}
			}
		}
	}
}