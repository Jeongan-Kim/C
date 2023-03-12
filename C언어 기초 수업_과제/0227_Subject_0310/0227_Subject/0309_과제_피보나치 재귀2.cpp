#include <stdio.h>

int Fibonacci(int n)
{
	if (n == 1)
		return 0;
	else if (n == 2)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
	int number = 0;
	printf("피보나치 수열의 항의 개수: ");
	scanf_s("%d", &number);

	for (int i = 1; i <= number; i++)
	{
		printf("%d ", Fibonacci(i));
	}

	return 0;
}