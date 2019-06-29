#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define swap(type,x,y) do{type t=x; x=y; y=t;} while(0)

void ary_reverse(int a[], int n)
{
	int i;
	for (i = 0; i < n / 2; i++)		//값의 교환 횟수는  요소 개수를 2로 나눈 값
	{
		swap(int, a[i], a[n - i - 1]);
	}
}

/*	int t= a[i];
	a[i] =a[n-i-1];
	 a[n-i-1]=t;      이 부분을 위의 함수로 간단하게 처리함 swap 함수 사용시  type만 추가*/


int main(void)
{
	int i;
	int *p;
	int num;

	printf(" 요소 갯수");
	scanf("%d", &num);
	p = calloc(num, sizeof(int));		// 요소 갯수만큼  메모리를 할당해줌

	printf("%d 개의 정수를 입력하세요", num);
	for (int i = 0; i < num; i++)
	{
		printf("p[%d]:", i);
		scanf("%d", &p[i]);   // 사용자가 직접 값을 할당시킴
	}

	/*for (int i = 0; i < num; i++)
	{
		printf("p[%d] : %d", i, p[i]);
	}*/

	ary_reverse(p, num);		// 역순으로 수를 배치하는 함수를 사용함
	printf("배열의 요소를 역순으로 정렬합니다 \n");
	for (i = 0; i < num ; i++)
		printf("p[%d}: %d", i, p[i]);
	
	
	free(p);  // 배열 p를 해제해주자  동적 배열 할당시 중요함

	return 0;
}























