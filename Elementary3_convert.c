	//������ n ������ �ٲٴ� ���
	#include <stdio.h>

	int card_convr(unsigned x, int n, char AB[])
	{
		char A[] = "0123456789ABCDEFGHIJKLMNOPQRTSUVWXYZ";;
		int digits = 0;		//  �Ϲ�����  for���� i�� ���� ����
		if (x == 0)
		{
			AB[digits++] = A[0];
		}
		else
			while (x)
			{
				AB[digits++] = A[x%n];		// %�� �������� ���Ҷ� �����
				x /= n;						// x= ���� n���� �������� ��
			}
		return digits;
	}










