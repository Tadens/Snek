#include "pch.h"
#include "SnekMecha.h"
#include <math.h>
#include <time.h>
#include <fstream>
#include <conio.h>
#include <strsafe.h>
#include <vector>

using namespace std;
int Direction = 2;

void setCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

int LoadMap(string fileName,unsigned short *wallcou)
{
	system("cls");

	ifstream plik(fileName, ifstream::binary);
	if (plik.is_open())
	{
		unsigned int size = 0;
		plik.read(reinterpret_cast<char *>(&size), sizeof(size));
		string buffer;
		buffer.resize(size);
		plik.read(&buffer[0], buffer.size());
		plik.close();

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), *wallcou);
		cout << buffer;

		return 1;
	}
	else
	{
		cout << "\n E:Nie znaleziono pliku map1\n";
		Sleep(2000);
		return 0;
	}
}
//dodac sprawdzanie czy jedzenia nie ma na sneku - teoretycznie dodano, ale nie sprawdzono czy dziala
void SpawnFood(int *fX, int *fY, bool *check, int *snekLen,int *tailX, int *tailY)
{
	if (*check)
		return;
	else
	{
		*fX = rand() % 48 + 1;
		*fY = rand() % 14 + 1;

		for (int g = 0; g < *snekLen; g++)//sprawdzanie tego jedzenia
		{
			if (*fX == tailX[g] && *fY == tailY[g])
				return;
		}

		setCursorPosition(*fX, *fY);
		cout << "+";
		*check = true;
	}
}

void Draw(int *placeX, int *placeY,int *tailX, int *tailY,int *snekLen, unsigned short *snekcou, int *tX, int *tY)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), *snekcou);
	Sleep(80);

	//setCursorPosition(*placeX, *placeY);
	//cout << "o";

	for (int g = 0; g < *snekLen ; g++)
	{
			setCursorPosition(tailX[g], tailY[g]);
			cout << "o";
			setCursorPosition(*tX, *tY);
			cout << " ";
	}
}

void Collision(int *placeX, int *placeY, int *fX, int *fY, int *snekL, int *tailX, int *tailY, bool *foodTable, bool *gameO)
{
	if (*placeY == *fY && *placeX == *fX)
	{
		*snekL = *snekL + 1;
		*foodTable = false;
	}
	else if (*placeY == 0 || *placeY == 16 || *placeX == 0 || *placeX == 50)
		*gameO = true;
	else
	{
		for (int i = 1; i < *snekL; i++)
		{
			if (*placeX == tailX[i] && *placeY == tailY[i])
				*gameO = true;
		}
	}
	return;
}

void snekMove(int *placeX, int *placeY, int *tabX, int *tabY, int *snekLen, int *tX, int *tY)
{
	int prevX = tabX[0];
	int prevY = tabY[0];
	int prev2X, prev2Y;
	tabX[0] = *placeX;
	tabY[0] = *placeY;

	if (*snekLen == 1)
	{
		*tX = prevX;
		*tY = prevY;
	}

	for (int i = 1; i < *snekLen; i++)
	{
		prev2X = tabX[i];
		prev2Y = tabY[i];
		tabX[i] = prevX;
		tabY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
		*tX = prevX;
		*tY = prevY;
	}

	switch (Direction)
	{
	case 1:
		*placeX = *placeX - 1;
		break;
	case 2:
		*placeX = *placeX + 1;
		break;
	case 3:
		*placeY = *placeY - 1;
		break;
	case 4:
		*placeY = *placeY + 1;
		break;
	default:
		break;
	}
}

void snekTrigger(bool *gameO)
{
	if (_kbhit())
	{
		switch (_getch())
		{
			case 'a':
				Direction = 1;
				break;
			case 'd':
				Direction = 2;
				break;
			case 'w':
				Direction = 3;
				break;
			case 's':
				Direction = 4;
				break;
			case 27:
				*gameO = true;
				break;
			default:
				break;
		}
	}
}
