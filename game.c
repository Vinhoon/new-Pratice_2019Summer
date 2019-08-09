#include "game.h"
#include "util.h"

int keyControl()
{
	char temp = getch();		// Ű�� ������ ��ȯ���ִ� �Լ�
	
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
	printf("\n\n\n\n");		//�� ���� 4���� ����
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
	printf("                  [���۹�]\n\n");
	printf("           �̵�:W ,A, S, D \\n");
	printf("           ����: �����̽��� \n\n\n\n\n");
	printf("           ������: ������ �� \n");
	printf("          �����̽��ٸ� ������ ����ȭ������ �̵��մϴ�. ");

	while (1)
	{
		if (keyControl() == SUBMIT)
		{
			break;
		}
	}
}
char tempMap[14][56];		//���� �ӽ� ������ �迭

char map1[14][56] = {
	{"11111111111111111111111111111111111111111111111111111111"},	//0�� ����
	{"100000a0000000000000000000000000000000000000000000000001"},	//1 ��
	{"1000000000000000000000000000000000000000000000000000q001"},	//k ����
	{"10010000000000000000000000000000000000000000000000000001"},	//L ��� ��
	{"10010000000000000000000000000000000000000000000000000001"},	//q Ż�ⱸ
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
	int h, w;  // ����,����

	for (h = 0; h < 14; h++)	//���α��̱���
	{
		for (w = 0; w < 56; w++)		//���α��̱���
		{
			char temp = tempMap[h][w];
			if (temp == '0')
			{
				setColor(black, black);
				printf(" ");	//�� ����
			}
			else if (temp == '1')
			{
				setColor(white, white);
				printf("#");	//��
			}
			else if (temp == 's')
			{
				*x = w;		//�÷��̿� ��ǥ�� ����
				*y = h;
				setColor(cyan, black);
				printf("@");	//�÷��̾�
			}
			else if (temp == 'q')
			{
				setColor(lightgreen, black);
				printf("O");	//������
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

	gotoxy(x - 2, y);		//-2�� >�� ����ϱ� ���� �ʿ��ϴ�
	printf("> ���� ����");
	gotoxy(x, y + 1);
	printf("���� ����");
	gotoxy(x, y + 2);
	printf("����");

	while (1)		//���ѹݺ�
	{
		int n = keyControl();
		switch (n)
		{
		case UP:			//�Էµ� Ű�� up�� ���
		{
			if (y > 12)			//y�� 12-14������ �̵�
			{
				gotoxy(x - 2, y);
				printf(" ");	//���� ��ġ�� �����
				gotoxy(x - 2, --y);
				printf(">");	//���� �����
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
		system("cls");		//ȭ�� ��� �����
		printf("\n\n");
		printf("					[�ʼ���]	\n\n");

		gotoxy(x - 2, y);
		printf("> ����");
		gotoxy(x, y + 1);
		printf("�����");
		gotoxy(x, y + 2);
		printf("�ڷ�");

		while (1)
		{
			int n = keyControl();	//Ű���� �̺�Ʈ�� Ű�� �޾ƿ���
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
		int x, y;		//�÷��̾��� ��ǥ ����(x,y)
		int playing = 1;		//1�̸� ������,0�̸� ���� ����
		int key = 0;

		if (mapCode == 0)
		{
			memcpy(tempMap, map1, sizeof(tempMap));	//map1�� tempMap�� ����
		}
		else if (mapCode == 1)
		{
			memcpy(tempMap, map2, sizeof(tempMap));	//map2�� tempMap�� ����
		}
	
		drawMap(&x,&y);		//�� ���� �� ���
		//�ʿ� ��ǥ �����͸� ����

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
				playing = 0;	//0�� �Ǹ� �ݺ� ����
			}
		}
	
	
	
	
	
	
	}

	void move(int *x, int *y, int _x, int _y,int *key)	//ĳ���� �̵�
	{

		char mapObject = tempMap[*y + _y][*x + _x];
		setColor(white, black);

		if (mapObject == '0')
		{
			gotoxy(*x, *y);
			printf(" ");	//�����

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
		setColor(white, black);		//�� �⺻��
		gotoxy(3, 16);
		printf("��ġ : %02d , %02d", *x, *y);	//x,y �� ���

		setColor(yellow, black);
		gotoxy(34, 16);
		printf("���� %d��", *key);
	}

















