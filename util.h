#include "main.h"

#ifndef __COLOR_LIST_
#define __COLOR_LIST_

enum {
	black,	//열거형은 /를 사용한다
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

#endif

void init();
void gotoxy(int, int);
void setColor(int, int);