#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "Header.h"

using namespace std;

bool gOVR = 1;
char tasta;
int scor = 4;
bool mar_check = 1;

MAR _mar;

char** allocateBoard()
{
	char** Board = 0;
	Board = new char* [N+2];
	int i;
	for (i = 0; i < N + 2; i++)
	{
		Board[i] = new char[N * 2 + 2];
	}

	return Board;
}

void initBoard(char**& Board)
{
	int i, j;
	for (i = 0; i < N ; i++)
	{
		for (j = 0; j < N * 2; j++)
		{
			if (i == 0 || i == N - 1 ) Board[i][j] = 35;
			else if (j == 0 || j == N * 2 - 1) Board[i][j] = 35;
			else Board[i][j] = 32;

		}
	}
	Board[0][0] = 35;
	mar(Board);
}

void showBoard(char** Board)
{
	int i, j;
	cout << endl << endl << "                                 ";
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N * 2; j++)
		{
			cout << Board[i][j];
		}
		cout << endl << "                                 ";
	}
}

sarpe* init_sarpe()
{
	sarpe* cap = 0;
	cap = new sarpe[N * (N * 2) - ((2 * N) + (4 * N)) + 4];


	cap[0].height = N / 2;
	cap[0].width = N;

	cap[1].height = cap[0].height;
	cap[1].width = N - 1;

	cap[2].height = cap[0].height;
	cap[2].width = N - 2;

	cap[3].height = cap[0].height;
	cap[3].width = N - 3;

	return cap;
}

void input_s()
{
	char control;

	if (_kbhit())
	{
		control = _getch();
		if (tasta == 'a' && control == 'd') return;
		if (tasta == 's' && control == 'w') return;
		if (tasta == 'd' && control == 'a') return;
		if (tasta == 'w' && control == 's') return;
		switch (control)
		{
		case 'a':
		{
			tasta =  'a';
			break;
		}
		case 'd':
		{
			tasta = 'd';
			break;
		}
		case 's':
		{
			tasta = 's';
			break;
		}
		case 'w':
		{
			tasta = 'w';
			break;
		}
		}
	}
}

void movements(char**& Board, sarpe*& cap)
{	
	switch (tasta)
	{
		case 'a':
		{
			modif_sarpe(cap);
			cap[0].width--;
			break;
		}
		case 'd':
		{
			modif_sarpe(cap);
			cap[0].width++;
			break;
		}
		case 's':
		{
			modif_sarpe(cap);
			cap[0].height++;
			break;
		}
		case 'w':
		{
			modif_sarpe(cap);
			cap[0].height--;
			break;
		}
	}
	
}

void modif_sarpe(sarpe*& cap)
{
	int i;
	for (i = scor; i >0; i--)
	{
		cap[i] = cap[i-1];
	}
}

void logic(char**& Board, sarpe* cap) //verificam marul mancat si daca se loveste de bordura
{
	if (Board[cap[0].height][cap[0].width] == '#')
	{
		gOVR = 0;
	}

	if (Board[cap[0].height][cap[0].width] == '$')
	{
		scor++;
		Board[_mar.height][_mar.width] = 32;
		mar_check = 1;
	}

	for (int i = 1; i < scor; i++)
	{
		if (cap[0].height == cap[i].height && cap[0].width == cap[i].width)
		{
			gOVR = 0;
		}
	}	
}

void modif_board(char**& Board, sarpe* cap)
{
	int i;
	for (i = 0; i < scor; i++)
	{
		Board[cap[i].height][cap[i].width] = cap[i].corp;
	}
	Board[cap[i].height][cap[i].width] = 32;
	Board[_mar.height][_mar.width] = '$';
}

void mar(char**& Board)
{
	
		srand(time(NULL));

		_mar.width = rand() % (N * 2 - 2) + 1;
		_mar.height = rand() % (N - 2) + 1;

		mar_check = 0;
		/*
		if (Board[_mar.height][_mar.width] == '#' || Board[_mar.height][_mar.width] == 'O')
		{
			mar(Board);
		}*/
}

char iesire()
{
	char Y;
	Y = _getch();
	if (Y != 'n' && Y != 'y') iesire();
	else return Y;
}

// iei ultimu element si il pui in fata cap
