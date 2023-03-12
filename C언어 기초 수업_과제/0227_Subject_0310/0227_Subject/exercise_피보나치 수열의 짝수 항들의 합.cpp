#include <stdio.h>
// 1000000 이하의 피보나치 수열 ( N 번째 항이 N - 1 번째 항과 N - 2번째 항으로 표현되는 수열, 시작은 1,1,2,3,5,8,...) 의 짝수 항들의 합을 구한다.

int main()
{
	int a = 1;
	int b = 2;
	int c = 0;
	int sum = a;
	for (int i = 1; c <= 1000000; i++)
	{
		c = a + b;
		a = b;
		b = c;
		if(i % 2 != 0)
		sum += c;
	}
	printf("1000000 이하의 피보나치 수열의 짝수 항들의 합 : %d", sum);
	return 0;
}