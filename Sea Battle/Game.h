#pragma once
#include <iostream>
#include "Helper.h"
#include "Logic.h"
#include "Board.h"
using namespace std;

void placement(char board[][10], char empty_board[][10]) {
    int random = -1;
    while (true) {
        cout << "Do you want make random positions of your ships or make it manually? 1 - random, 0 - manual" << endl;
        cin >> random;
        if (random) {
            randomPlace(board);
            break;
        }
        else {
            manualPlace(board, empty_board);
            break;
        }
    }
}

bool playerTurn(char bot_board[][10], char empty_board[][10]) {
    int row, col;
    char col_ch;

    cout << "Row(1-10): ";
    cin >> row;
    cout << "Col(A-J): ";
    cin >> col_ch;
    col = letternumber(col_ch) - 1;
    row = row - 1;

    while (row < 0 || row >= 10 ||
        col < 0 || col >= 10 ||
        bot_board[row][col] == 'X' ||
        bot_board[row][col] == 'o' ||
        bot_board[row][col] == 'S') {

        cout << "Wrong coordinates try again\n\n" << endl;
        cout << "Row(1-10): ";
        cin >> row;
        cout << "Col(A-J): ";
        cin >> col_ch;
        col = letternumber(col_ch);
        col = col - 1;
        row = row - 1;
    }

    if (bot_board[row][col] == (char)254) {
        bot_board[row][col] = 'X';
        empty_board[row][col] = 'X';

        if (isSunk(bot_board, row, col)) {
            shipSunk(bot_board, row, col);
            shipSunk(empty_board, row, col);
        }
        return true;
    }
    else {
        bot_board[row][col] = 'o';
        empty_board[row][col] = 'o';
        return false;
    }
}
bool botTurn(char player_board[][10], int& state, int& row, int& col) {
    srand(time(NULL));
    int col2 = col;
    int row2 = row;

    switch (state) {
    case 0:
        while (true)
        {
            row = rand() % 10;
            col = rand() % 10;
            if (player_board[row][col] != 'o' && player_board[row][col] != 'S' && player_board[row][col] != 'X') break;
        }
        break;
    case 1:
        if (row > 0 && (row - 1) != 'o') {
            row -= 1;
        }
        else {
            state += 1;
            row = row2;
        }
        break;
    case 2:
        if (row < 9 && (row + 1) != 'o') {
            row += 1;
        }
        else {
            state += 1;
            row = row2;
        }
        break;
    case 3:
        if (col > 0 && (col - 1) != 'o') {
            col -= 1;
        }
        else {
            state += 1;
            col = col2;
        }
        break;
    case 4:
        if (col < 9 && (col + 1) != 'o') {
            col += 1;
        }
        else {
            state += 1;
            col = col2;
        }
        break;
    }
    if (player_board[row][col] == (char)254) {
        player_board[row][col] = 'X';
        if (isSunk(player_board, row, col)) {
            shipSunk(player_board, row, col);
            state = 0;
        }
        return true;
    }
    else {
        player_board[row][col] = 'o';
        return false;
    }
}