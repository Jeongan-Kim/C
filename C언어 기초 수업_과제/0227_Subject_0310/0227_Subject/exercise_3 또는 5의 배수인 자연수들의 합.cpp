#include <stdio.h>

int main()
{
	//1000 ������ 3 �Ǵ� 5�� ����� �ڿ������� ���� ���Ѵ�.
	int total = 0;
	for (int i = 0; i <= 1000; i++)    //i += 2
	{
		if (i % 3 == 0 || i % 5 == 0)
			total += i;
	}
	printf("1000 ������ 3 �Ǵ� 5�� ����� �ڿ������� �� : %d", total);
	return 0;
}