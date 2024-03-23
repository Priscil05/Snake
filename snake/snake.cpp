#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include "Header.h"

using namespace std;

int main()
{

	char Y;
	char** Board = 0;
	Board = allocateBoard();
	initBoard(Board);

	sarpe* cap = 0;
	cap = init_sarpe();
	
	int mar_w, mar_h;
	
	while (true)
	{
		initBoard(Board);
		cap = init_sarpe();
		scor = 4;
		gOVR = 1;

		while (gOVR)
		{
			system("CLS");
			showBoard(Board);
			input_s();
			movements(Board, cap);
			logic(Board, cap);
			modif_board(Board, cap);
			if (mar_check)
			{
				mar(Board);
			}
			Sleep(50);
		}

		int _scor = scor;

		system("CLS");
		cout << endl << endl << endl;
		cout << "                                                   " << "AI PIERDUT" << endl;
		cout << "                                                   " << " scor: " << _scor - 4 << endl;
		cout << endl << endl << endl;

		cout << "                               Doriti sa rejucati?  y   /  n" << endl << endl << endl << endl;

		Y = iesire();
		if (Y == 'n') break;
	}

	for ( int i = 0; i < N + 2; i++)
	{
		delete[] Board[i];
	}

	delete[] Board;
	delete[] cap;

	return 0;
}