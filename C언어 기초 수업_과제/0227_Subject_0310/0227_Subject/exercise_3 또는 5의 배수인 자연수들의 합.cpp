#include <stdio.h>

int main()
{
	//1000 이하의 3 또는 5의 배수인 자연수들의 합을 구한다.
	int total = 0;
	for (int i = 0; i <= 1000; i++)    //i += 2
	{
		if (i % 3 == 0 || i % 5 == 0)
			total += i;
	}
	printf("1000 이하의 3 또는 5의 배수인 자연수들의 합 : %d", total);
	return 0;
}