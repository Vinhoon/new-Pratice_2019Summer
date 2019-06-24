#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n)
{
	int max= a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];			// 선언한 변수만 왼쪽 식에 사용 가능함
	}
}



int main(void)
{
	int i;
	int *height;
	int number;

	printf("사람 수:");
	scanf("%d", &number);
	height = calloc(number, sizeof(int));

	printf("%d  사람의 키를 입력하세요. \n", number);
	for (i = 0; i < number; i++)
	{
		printf("height[%d]:", i + 1);
		scanf("%d", &height[i]);
	}

	printf("최대값은 %d 입니다 \n", maxof(height, number));
	free(height);// 동적 할당한 것에 대해 메모리를 해제해줌
}


