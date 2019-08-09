#include "game.h"
#include "util.h"

int keyControl()
{
	char temp = getch();		// 키가 눌리면 반환해주는 함수
	
	if (temp == 'W' || temp == 'w')
	{
		return UP;
	}
	else if (temp == 'A' || temp == 'a')
	{
		return LEFT;
	}
	else if (temp == 's' || temp == 'S')
	{
		return DOWN;
	}
	else if ((temp == 'D' || temp == 'd'))
	{
		return RIGHT;
	}
	else if (temp == ' ')
		return SUBMIT;
}

void titleDraw()
{
	printf("\n\n\n\n");		//맨 위에 4줄을 개행
	printf("    ######         #        ##    ##     ######                  \n");
	printf("    #             # #       # #  # #     #             \n");
	printf("    #      #     #   #      #  ##  #     ######               \n");
	printf("    #     ##    #######     #      #     #             \n");
	printf("    ########   #       #    #      #     ######                   \n");

}




void infoDraw()
{
	system("cls");
	printf("\n\n");
	printf("                  [조작법]\n\n");
	printf("           이동:W ,A, S, D \\n");
	printf("           선택: 스페이스바 \n\n\n\n\n");
	printf("           개발자: 개발자 빈 \n");
	printf("          스페이스바를 누르면 메인화면으로 이동합니다. ");

	while (1)
	{
		if (keyControl() == SUBMIT)
		{
			break;
		}
	}
}
char tempMap[14][56];		//맵을 임시 저장할 배열

char map1[14][56] = {
	{"11111111111111111111111111111111111111111111111111111111"},	//0빈 공간
	{"100000a0000000000000000000000000000000000000000000000001"},	//1 벽
	{"1000000000000000000000000000000000000000000000000000q001"},	//k 열쇠
	{"10010000000000000000000000000000000000000000000000000001"},	//L 잠긴 문
	{"10010000000000000000000000000000000000000000000000000001"},	//q 탈출구
	{"10010000000000000000000000000000000000000000000000000001"},
	{"10010001111100000000000000000000000000000000000000000001"},
	{"10010000000100000000000000000000000000000000000000000001"},
	{"10010000000100000000000000000000000000000000000000000001"},
	{"100100000k0100000000000000000000000000000000000001111111"},
	{"10010000000100000000000000000000000000000000000001000001"},
	{"10s10001111111111111111111111111111111111111111111001001"},
	{"10010010000100000000000000000000000000000000000000000001"},
	{"11111111111111111111111111111111111111111111111111111111"},
};

char map2[14][56] = {
	{"11111111111111111111111111111111111111111111111111111111"},
	{"10000000000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000000000001"},
	{"10010000000000000000000000000000000000000000000000000001"},
	{"10010000000000000000000000000000000000000000000000000001"},
	{"10010000000000000000000000000000000000000000000000000001"},
	{"10010000000000000000000000000000000000000000000000000001"},
	{"10010000000000000000000000000000000000000000000000000001"},
	{"10010000000000000000000000000000000000000000000000000001"},
	{"10010000000000000000000000000000000000000000000000000001"},
	{"10010000000000000000000000000000000000000000000000000001"},
	{"10s0100000000000000000000000000000000000000000000000q001"},
	{"10010000000000000000000000000000000000000000000000000001"},
	{"11111111111111111111111111111111111111111111111111111111"},
};


void drawMap(int *x,int *y)
{
	system("cls");
	int h, w;  // 세로,가로

	for (h = 0; h < 14; h++)	//세로길이까지
	{
		for (w = 0; w < 56; w++)		//가로길이까지
		{
			char temp = tempMap[h][w];
			if (temp == '0')
			{
				setColor(black, black);
				printf(" ");	//빈 공간
			}
			else if (temp == '1')
			{
				setColor(white, white);
				printf("#");	//벽
			}
			else if (temp == 's')
			{
				*x = w;		//플레이와 좌표값 저장
				*y = h;
				setColor(cyan, black);
				printf("@");	//플레이어
			}
			else if (temp == 'q')
			{
				setColor(lightgreen, black);
				printf("O");	//목적지
			}
			else if (temp == 'k')
			{
				setColor(yellow, black);
				printf("*");
			}
			else if (temp == 'A');
			{
				setColor(brown, black);
				printf("?");
			}
		}
		printf("\n");
	}
	setColor(white, black);
	//Sleep(3000);
}

int menuDraw()
{
	int x = 24;
	int y = 12;

	gotoxy(x - 2, y);		//-2는 >를 출력하기 위해 필요하다
	printf("> 게임 시작");
	gotoxy(x, y + 1);
	printf("게임 정보");
	gotoxy(x, y + 2);
	printf("종료");

	while (1)		//무한반복
	{
		int n = keyControl();
		switch (n)
		{
		case UP:			//입력된 키가 up인 경우
		{
			if (y > 12)			//y는 12-14까지만 이동
			{
				gotoxy(x - 2, y);
				printf(" ");	//원래 위치를 지운다
				gotoxy(x - 2, --y);
				printf(">");	//새로 만들기
			}
			break;
		}

		case DOWN:
		{
			if (y < 14)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT:
		{
			return y - 12;
		}
		}
	}
}
	int maplistDraw()
	{
		int x = 24;
		int y = 6;
		system("cls");		//화면 모두 지우기
		printf("\n\n");
		printf("					[맵선택]	\n\n");

		gotoxy(x - 2, y);
		printf("> 쉬움");
		gotoxy(x, y + 1);
		printf("어려움");
		gotoxy(x, y + 2);
		printf("뒤로");

		while (1)
		{
			int n = keyControl();	//키보드 이벤트로 키값 받아오기
			switch (n)
			{
			case UP:
			{
				if (y > 6)
				{
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, --y);
					printf(">");
				}
				break;
			}

			case DOWN:
			{
				if (y < 9)
				{
					gotoxy(x - 2, y);
					printf(" ");
					gotoxy(x - 2, ++y);
					printf(">");
				}
				break;
			}

			case SUBMIT: {
				return y - 6;
			}
			
			}
		}
	}

	void gLoop(int mapCode)
	{
		int x, y;		//플레이어의 좌표 설정(x,y)
		int playing = 1;		//1이면 게임중,0이면 게임 종료
		int key = 0;

		if (mapCode == 0)
		{
			memcpy(tempMap, map1, sizeof(tempMap));	//map1을 tempMap에 복사
		}
		else if (mapCode == 1)
		{
			memcpy(tempMap, map2, sizeof(tempMap));	//map2를 tempMap에 복사
		}
	
		drawMap(&x,&y);		//맵 설정 후 출력
		//맵에 좌표 포인터를 전달

		while (playing)
		{
			drawUI(&x, &y,&key);

			switch (keyControl())
			{
			case UP:
				move(&x, &y, 0, -1,&key);
				break;

			case DOWN:
				move(&x, &y, 0, 1,&key);
				break;

			case RIGHT:
				move(&x, &y, 1, 0,&key);
				break;

			case LEFT:
				move(&x, &y, -1, 0,&key);
				break;

			case SUBMIT:
				playing = 0;	//0이 되면 반복 종료
			}
		}
	
	
	
	
	
	
	}

	void move(int *x, int *y, int _x, int _y,int *key)	//캐릭터 이동
	{

		char mapObject = tempMap[*y + _y][*x + _x];
		setColor(white, black);

		if (mapObject == '0')
		{
			gotoxy(*x, *y);
			printf(" ");	//지우기

			setColor(cyan, black);
			gotoxy(*x + _x, *y + _y);
			printf("@");

			*x += _x;
			*y += _y;
		}
		else if (mapObject == 'k')
		{
			*key += 1;
			tempMap[*y + _y][*x + _x] = '0';
			gotoxy(*x + _x, *y + _y);
			printf(" ");
		}
		else if (mapObject == "a")
		{
			if (*key > 0)
				*key -= 1;
			tempMap[*y + _y][*x + _x] = '0';
			setColor(white, black);
			gotoxy(*x + _x, *y + _y);
			printf(" ");
		}
	}

	void drawUI(int *x, int *y, int *key)
	{
		setColor(white, black);		//색 기본값
		gotoxy(3, 16);
		printf("위치 : %02d , %02d", *x, *y);	//x,y 값 출력

		setColor(yellow, black);
		gotoxy(34, 16);
		printf("열쇠 %d개", *key);
	}

















