#include <iostream>
using namespace std;

struct ProductInfo {
	int num;
	char name[100];
	int cost;
};

int main()
{
	ProductInfo myProduct = { 4797283,"Jeju",19900 };
	//myproduct라는 정보를 저장함

	printf("상품번호: %d \n", myProduct.num);
	printf("이   름: %s \n", myProduct.name);
	printf("가   격: %d  \n", myProduct.cost);

	return 0;

}