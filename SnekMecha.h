#ifndef SNEK_MECHA_H
#define SNEK_MECHA_H

// x is the column, y is the row. The origin (0,0) is top-left.
void setCursorPosition(int x, int y);
//rysuj sneka: ( X, Y, ogonX, ogonY, snekLen, kolor Sneka, tempX, tempY)
void Draw(int *placeX, int *placeY, int *, int * , int *snekLen, unsigned short *snekcou, int *, int *);
//poruszanie snekiem: ( gameOver )
void snekTrigger(bool *gameO);
//logika poruszania sie sneka: ( X, Y , TailX, TailY, snekLen, tempX, tempY)
void snekMove(int *, int *, int *, int *, int *, int *, int *);
//laduj poziom: ( nazwa, kolor scian )
int LoadMap(std::string fileName, unsigned short *);
//resp jedzonka: ( X, Y, isfoodontable, snekLen, tailX, tailY)
void SpawnFood(int *fX, int *fY, bool *, int *, int *, int *);
//obsluga kolizji: ( snekX, snekY, foodX, foodY, snekLen, tailX, tailY, foodOnTable, gameO )
void Collision(int *, int *, int *, int *, int *, int *, int *,bool *,bool *);

//zwrot sneka
extern int Direction;

#endif
