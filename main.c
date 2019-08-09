	#include "main.h"
	#include "util.h"
	// 키보드 값 
	
	//함수 선언하기
	int keyControl();
	void init();
	void titleDraw();
	void gotoxy(int, int);
	int maplistDraw();
	void infoDraw();
	void drawMap();

	int main()
	{
		init();
		while (1)
		{
			titleDraw();
			int menuCode = menuDraw();
			if (menuCode == 0)
			{
				int n = maplistDraw();

				if (n == 0)
				{
					gLoop(0);		//0; 쉬운 맵
				}
				else if (n == 1)
				{
					gLoop(1);		//1: 어려운 맵
				}
			}
			else if (menuCode == 1)
			{
				infoDraw();	//게임 정보
			}
			else if (menuCode == 2)
			{
				return 0;	//종료
			}
			system("cls");
			setColor(white, black);
		}
		return 0;
	}






























