	//정수를 n 진수로 바꾸는 방법
	#include <stdio.h>

	int card_convr(unsigned x, int n, char AB[])
	{
		char A[] = "0123456789ABCDEFGHIJKLMNOPQRTSUVWXYZ";;
		int digits = 0;		//  일반적인  for문의 i와 같은 역할
		if (x == 0)
		{
			AB[digits++] = A[0];
		}
		else
			while (x)
			{
				AB[digits++] = A[x%n];		// %은 나머지를 구할때 사용함
				x /= n;						// x= 몫을 n으로 나눌때의 몫
			}
		return digits;
	}










