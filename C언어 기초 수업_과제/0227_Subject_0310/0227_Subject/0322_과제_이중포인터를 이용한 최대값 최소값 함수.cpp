#include <stdio.h>

void MaxAndMin(int* ptr, int** dmaxPtr, int** dminPtr);


int main()
{
	int* maxPtr = 0; //5
	int* minPtr = 0; //1
	int arr[5]; // 1 2 3 4 5
	int* ptr = arr;

	int** dmaxPtr = &maxPtr;
	int** dminPtr = &minPtr;

	for (int i = 0; i < 5; i++)
	{
		printf("정수 입력 %d : ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	MaxAndMin(ptr, dmaxPtr, dminPtr); //최대값 최소값이 나오게끔

	printf("최대 : %d, 최소 : %d \n", *maxPtr, *minPtr); // 5, 1


	return 0;
}

void MaxAndMin(int* ptr, int** dmaxPtr, int** dminPtr)
{
	int maxValue = *ptr;
	int minValue = *ptr;
	for (int i = 1; i < 5; i++)
	{
		if (maxValue < *(ptr + i))
		{
			maxValue = *(ptr + i);
		}

		if (minValue > *(ptr + i))
		{
			minValue = *(ptr + i);
		}
	}

	*(dmaxPtr) = &maxValue;
	*(dminPtr) = &minValue;
}
