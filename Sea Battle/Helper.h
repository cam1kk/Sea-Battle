#pragma once
#include <iostream>
using namespace std;

void winorlose(int player, int bot) {
	if (player > 0) {
		cout << "Player wins!" << endl;
	}
	else if (bot > 0) {
		cout << "Bot wins!" << endl;
	}
}
int letternumber(char letter) {
	if (letter == 'A') return 1;
	else if (letter == 'B') return 2;
	else if (letter == 'C') return 3;
	else if (letter == 'D') return 4;
	else if (letter == 'E') return 5;
	else if (letter == 'F') return 6;
	else if (letter == 'G') return 7;
	else if (letter == 'H') return 8;
	else if (letter == 'I') return 9;
	else if (letter == 'J') return 10;
}

char numberletter(int number) {
	if (number == 1) return 'A';
	else if (number == 2) return 'B';
	else if (number == 3) return 'C';
	else if (number == 4) return 'D';
	else if (number == 5) return 'E';
	else if (number == 6) return 'F';
	else if (number == 7) return 'G';
	else if (number == 8) return 'H';
	else if (number == 9) return 'I';
	else if (number == 10) return 'J';
}