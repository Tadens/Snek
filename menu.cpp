#include "pch.h"
#include "SnekMenu.h"
#include "SnekMecha.h"

void DisplayMenu()
{
	const char *mini[] = {
		"    ###    #    #   ####   #    #\n   #   #   ##   #   #      #   #\n    #      # #  #   ###    #  #\n     #     #  # #   ###    # ##\n  #   #    #   ##   #      ##  #\n   ###     #    #   ####   #    #\n\n",
		"===================================\n"
		"Witaj w menu glownym Sneka, wybierz opcje wpisujac odpowiedni numer:\n",
		"1. Graj",
		"2. Od autora",
		"3. Opcje",
		"\nDowolny klawisz by zamknac.",
		"\nWersja Beta 2.1\n_"
	};

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (int menu = 0; menu < (sizeof(mini) / sizeof(const char *)); menu++)
		std::cout << mini[menu]<<"\n";

}

void Options(unsigned short *snekco, unsigned short *wallco)
{
	const char *mini[] = {
		"Mozesz zmieniac kolorki:",
		"1. Sneka",
		"2. Muru",
		"wprowadzenie innej opcji zakonczy dzialanie proramu, nie pytaj czemu"
	};

	const char *snek[] = {
		"Zmieniasz kolor sneka:",
		"1. Cyjan",
		"2. Czerwony",
		"3. Zielony",
		"4. Niebieski",
		"5. Zolty",
		"6. Bialy"
	};

	const char *wall[] = {
		"Zmieniasz kolor scianki:",
		"1. Czerwony",
		"2. Zielony",
		"3. Niebieski",
		"4. Zolty",
		"5. Bialy"
	};

	int *point;
	unsigned short helpcolor;
	bool exitnum = true;

	point = new int[1];


	system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (int menu = 0; menu < (sizeof(mini) / sizeof(const char *)); menu++)
		std::cout << mini[menu] << "\n";

	std::cin >> point[0];

	if (point == nullptr)
	{
		system("cls");
		std::cout << "E: blad pamieci!!!!";
		exit(1);
	}


	switch (point[0])
	{
		case 1:
		{
			system("cls");
			for (int i = 0; i < (sizeof(snek) / sizeof(const char *)); i++)
				std::cout << snek[i] << "\n";

			helpcolor = changeSnekColour();
			if (helpcolor)
				*snekco = helpcolor;
		}
		break;
		case 2:
		{
			system("cls");
			for (int i = 0; i < (sizeof(wall) / sizeof(const char *)); i++)
				std::cout << wall[i] << "\n";

			helpcolor = changeWallColour();
			if (helpcolor)
				*wallco = helpcolor;
		}
		break;
		default:
			delete[] point;
			break;
	}
	return;
}

unsigned short changeSnekColour()
{
	int whatnow;

	std::cin >> whatnow;

	switch (whatnow)
	{
	case 1:
		return 11;
		break;
	case 2:
		return 12;
		break;
	case 3:
		return 10;
		break;
	case 4:
		return 9;
		break;
	case 5:
		return 14;
		break;
	case 6:
		return 15;
		break;
	default:
		return 0;
		break;
	}
}

unsigned short changeWallColour()
{
	int whatnow;

	std::cin >> whatnow;

	switch (whatnow)
	{
	case 1:
		return 12;
		break;
	case 2:
		return 10;
		break;
	case 3:
		return 9;
		break;
	case 4:
		return 14;
		break;
	case 5:
		return 15;
		break;
	default:
		return 0;
		break;
	}
}

void authorMess()
{
	const char *author[] = {
		"\nWersja Beta (albo wieczna Beta),",
		"aplikacje napisal Tadeusz \'Tade\' Ciapaua.",
		"Sterowanie: W A S D - zmiana kierunku Sneka, ESC - wyjscie od razu.\n"
		"nie wiem co tu jeszcze wpisac, milej gry czy cos...\n\n"
	};

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	for (int m = 0; m < (sizeof(author) / sizeof(const char *)); m++)
		std::cout << author[m] << "\n";
	
	Sleep(4000);
}

void endGame(int *snekLen)
{
	setCursorPosition(60, 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	std::cout << "*CRASH*!";
	Sleep(1100);
	setCursorPosition(2, 18);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << "Koniec gry, twoje punkty: "<< *snekLen - 1 <<"\n\n  nacisnij dowolny klawisz\n";
	system("pause > nul");
}