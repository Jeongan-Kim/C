#include <stdio.h>

int FibonacciAdd(int f1, int f2, int n)
{
	if (n == 0)
		return 0;
	else
	{
		int f3;
		f3 = f2 + f1;
		f1 = f2;
		f2 = f3;
		printf("%d ", f3);
	}
	return FibonacciAdd(f1, f2, n-1);
}


int Fibonacci(int n)
{
	int f1 = 0, f2 = 1;

	if (n == 1)
		printf("%d", f1);
	else 
		printf("%d %d ", f1, f2);
	
	return FibonacciAdd(f1, f2, n-2);
}

int main()
{
	int FibonacciElementNum;
	printf("피보나치 수열 몇 항까지 출력할까요? : ");
	scanf_s("%d", &FibonacciElementNum);

	printf("\n");
	Fibonacci(FibonacciElementNum);
	return 0;
}