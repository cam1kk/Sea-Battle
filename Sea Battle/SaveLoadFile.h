#pragma once
#include <iostream>
void saveFile(char board[][10], const char* filename) {
	FILE* file;
	fopen_s(&file, filename, "wb");
	fwrite(board, sizeof(board), 16, file);
	fclose(file);
}
void loadFile(char board[][10], const char* filename) {
	FILE* file;
	fopen_s(&file, filename, "rb");
	fread(board, sizeof(board), 16, file);
	fclose(file);
}