#include<iostream>
using namespace std;
#define N 5

int main(void)
{
	int i;
	int a[5] = { 1,2,3,4,5 };
	int na = sizeof(a) / sizeof(int);//요소의 개수
	printf("배열 a의 요소 개수는 %d입니다. \n", na);

	for (i = 0; i < na; i++)
		printf("a[%d]=%d \n", i, a[i]);

	return 0;
}