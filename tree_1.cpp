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
	//myproduct��� ������ ������

	printf("��ǰ��ȣ: %d \n", myProduct.num);
	printf("��   ��: %s \n", myProduct.name);
	printf("��   ��: %d  \n", myProduct.cost);

	return 0;

}