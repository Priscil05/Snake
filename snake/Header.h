//#pragma once

#define N 20

extern bool gOVR;
extern int scor;
extern bool mar_check;

struct sarpe
{
	int width = 0;
	int height = 0;
	char corp = 'O';
};

struct MAR {
	int height;
	int width;
};

char** allocateBoard();
void initBoard(char**& Board);
void showBoard(char** Board);
void movements(char**& Board, sarpe*& cap);
void input_s();
sarpe* init_sarpe();
void modif_sarpe(sarpe*& cap);
void logic(char**& Board, sarpe* cap);
void modif_board(char**& Board, sarpe* cap);
void mar(char**& Board);
char iesire();