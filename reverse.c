#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define swap(type,x,y) do{type t=x; x=y; y=t;} while(0)

void ary_reverse(int a[], int n)
{
	int i;
	for (i = 0; i < n / 2; i++)		//���� ��ȯ Ƚ����  ��� ������ 2�� ���� ��
	{
		swap(int, a[i], a[n - i - 1]);
	}
}

/*	int t= a[i];
	a[i] =a[n-i-1];
	 a[n-i-1]=t;      �� �κ��� ���� �Լ��� �����ϰ� ó���� swap �Լ� ����  type�� �߰�*/


int main(void)
{
	int i;
	int *p;
	int num;

	printf(" ��� ����");
	scanf("%d", &num);
	p = calloc(num, sizeof(int));		// ��� ������ŭ  �޸𸮸� �Ҵ�����

	printf("%d ���� ������ �Է��ϼ���", num);
	for (int i = 0; i < num; i++)
	{
		printf("p[%d]:", i);
		scanf("%d", &p[i]);   // ����ڰ� ���� ���� �Ҵ��Ŵ
	}

	/*for (int i = 0; i < num; i++)
	{
		printf("p[%d] : %d", i, p[i]);
	}*/

	ary_reverse(p, num);		// �������� ���� ��ġ�ϴ� �Լ��� �����
	printf("�迭�� ��Ҹ� �������� �����մϴ� \n");
	for (i = 0; i < num ; i++)
		printf("p[%d}: %d", i, p[i]);
	
	
	free(p);  // �迭 p�� ����������  ���� �迭 �Ҵ�� �߿���

	return 0;
}























