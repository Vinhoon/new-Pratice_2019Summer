#include "main.h"

#ifndef KEY_CODE
#define KEY_CODE

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4		//�����̽���


#endif

void gLoop(int);
int keyControl();
void titleDraw();
int menuDraw();
int maplistDraw();
void infoDraw();
void drawMap(int*,int*);
void move(int *, int*, int, int,int*);		//�����̴� ����� ������
void drawUI(int *, int*,int*);