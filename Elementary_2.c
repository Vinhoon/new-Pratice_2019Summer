#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n)
{
	int max= a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];			// ������ ������ ���� �Ŀ� ��� ������
	}
}



int main(void)
{
	int i;
	int *height;
	int number;

	printf("��� ��:");
	scanf("%d", &number);
	height = calloc(number, sizeof(int));

	printf("%d  ����� Ű�� �Է��ϼ���. \n", number);
	for (i = 0; i < number; i++)
	{
		printf("height[%d]:", i + 1);
		scanf("%d", &height[i]);
	}

	printf("�ִ밪�� %d �Դϴ� \n", maxof(height, number));
	free(height);// ���� �Ҵ��� �Ϳ� ���� �޸𸮸� ��������
}


