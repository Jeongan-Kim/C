#include <stdio.h>


int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
			printf("*");
		printf("\n");
	}


	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		for (int j = 4; j >= i; j--)
			printf("*");
		printf("\n");
	}

	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0;j <i; j++)
			printf(" ");
		for (int k = 5; k > i; k--)
			printf("*");
		printf("\n");
	}

	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		for (int j = 4; j > i; j--)
			printf(" ");
		for (int k = 0; k <= i; k++)
			printf("*");
		printf("\n");
	}

	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		if (i <= 2)
		{
			for (int j = 2; j > i; j--)
				printf(" ");
			for (int k = 0; k < 2 * i + 1; k++)
				printf("*");
			printf("\n");
		}
		else if (i > 2)
		{
			for (int j = 3; j <= i; j++)
				printf(" ");
			for (int k = 10; k > 2 * i + 1; k--)
				printf("*");
			printf("\n");
		}

	}

	return 0;
}