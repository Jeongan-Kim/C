#include <stdio.h>

int main()
{
	int a, b;
	scanf_s("%d %d", &a, &b);
	int x = b / 100; //3
	int y = (b % 100) / 10; //4
	int z = (b % 100) % 10; //5

	printf("%d\n", a * z);
	printf("%d\n", a * y);
	printf("%d\n", a * x);
	printf("%d\n", a * z + a * y * 10 + a * x * 100);
	
	return 0;
}