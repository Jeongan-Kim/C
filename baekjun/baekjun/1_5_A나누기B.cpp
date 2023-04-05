#include <stdio.h>

int main()
{
	int A, B;
	scanf_s("%d%d", &A, &B);

	double C = (double)A / (double)B;

	printf("%.9f", C);

	return 0;
}