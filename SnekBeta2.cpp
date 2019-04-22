// SnekBeta2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//Tade ciapała 15-04-19

#include "pch.h"
#include "SnekMenu.h"
#include "SnekMecha.h"
#include <time.h>
#include <fstream>
#include <conio.h>
#include <strsafe.h>
#include <math.h>

//using namespace std;

bool gameOver, IsFoodOnTable;
int positionX, positionY, foodX, foodY, SnekLength, tempX, tempY;
unsigned short SnekColour = 11, WallPaint = 15;
int TailX[1000];
int TailY[1000];

// x is the column, y is the row. The origin (0,0) is top-left.
//void setCursorPosition(int x, int y);

//ustawienia okna
void ScreenInit();
// Ustawienia poczatkowe gry
void Start();


int main(int argc, char *argv[])
{
	ScreenInit();

	int * choice;

	do
	{
		DisplayMenu();

		choice = new int[1];

		std::cin >> choice[0];

		switch (choice[0])
		{
			case 1:
			{
				delete[] choice;
				Start();
				if (!LoadMap("map1.bin", &WallPaint))
					continue;

				srand(time(NULL));
				
				while (!gameOver)
				{
					SpawnFood(&foodX, &foodY,&IsFoodOnTable, &SnekLength, TailX, TailY);
					Collision(&positionX, &positionY, &foodX, &foodY, &SnekLength, TailX, TailY, &IsFoodOnTable, &gameOver);

					Draw(&positionX, &positionY, TailX, TailY, &SnekLength, &SnekColour, &tempX, &tempY);
					
					snekTrigger(&gameOver);
					snekMove(&positionX, &positionY, TailX, TailY, &SnekLength, &tempX, &tempY);
				}
				endGame(&SnekLength);
			}break;
			case 2:
			{
				authorMess();
				delete[] choice;
			}break;
			case 3:
			{
				Options(&SnekColour,&WallPaint);
				delete[] choice;
			}
			break;
			default:
				return 0;
				break;
		}
	} while (true);
}

void ScreenInit()
{
	_COORD wspl;
	wspl.X = 52;
	wspl.Y = 20;

	_SMALL_RECT rect;
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = 99;//o jeden mniejsze od Y
	rect.Right = 99;//o jeden mniejsze od X

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
	SetConsoleScreenBufferSize(Handle, wspl);            // Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &rect);            // Set Window Size

	CONSOLE_CURSOR_INFO cursor;
	GetConsoleCursorInfo(Handle, &cursor);
	cursor.bVisible = false;
	if (cursor.dwSize < 100 && cursor.dwSize > 1)
		SetConsoleCursorInfo(Handle, &cursor);

	std::cout.flush();

	TCHAR szNewTitle[MAX_PATH];
	StringCchPrintf(szNewTitle, MAX_PATH, TEXT("IS IT BIRD? IS IT PLANE? NOOO, IT IS SNEK!  * by Tade *"));
	SetConsoleTitle(szNewTitle);
}

void Start()
{
	gameOver = false;
	IsFoodOnTable = false;
	foodX = 1;
	foodY = 1;
	positionX = 23;
	positionY = 9;
	SnekLength = 1;
	Direction = 2;
}

//////////////////////////////////////////////////////////////////////////////////////////
