#ifndef SNEK_MENU_H
#define SNEK_MENU_H

//Menu glowne gry snek
void DisplayMenu();
//obsluga opcji zmiany koloru sneka
unsigned short changeSnekColour();
//obsluga opcji zmiany koloru scian
unsigned short changeWallColour();
//menu z opcjami
void Options(unsigned short *, unsigned short *);
//informacje o grze
void authorMess();
//oblsuga powiadomien konca gry
void endGame(int *);

#endif
