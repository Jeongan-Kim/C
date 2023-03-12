#include <stdio.h>

int main()
{

	printf("Hello, World!\n");
	printf("%d\n", 10);
	printf("10\n");
	printf("%d %d %d %d %d\n", 1, 2, 3, 4, 5);

	int a;
	a = 10;
	printf("a=%d\n", a);

	a = 11;
	printf("다시 a=%d\n", a);

	int b = 20;
	printf("b=%d\n", b);

	int result1;
	result1 = a + b;
	printf("a+b는 %d이다.\n", result1);
	
	int result2;
	result2 = b - a;
	printf("b-a는 %d이다.\n", result2);



	return 0;
}