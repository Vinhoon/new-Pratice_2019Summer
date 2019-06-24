#include <stdio.h>

int main(void)
{
	int year, month, day;

	scanf("%d.%d.%d", &year, &month, &day);

	printf("04%d-02%d-%02d", day, month, year);// 기본적인 날짜 형태 바꿔 출력하기'
	//print 할때에 자리 수를 맞춰준다

}
