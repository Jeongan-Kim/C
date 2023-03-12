#include <stdio.h>

void printArr(int arr[], int arrSize);
void bubbleSort(int arr[], int arrSize);
void selectionSort(int arr[], int arrSize);

int main()
{
	int arr[5] = { 3, 5, 4, 1, 2 };

	printArr(arr, sizeof(arr) / sizeof(int));

	printf("\n");

	//bubbleSort(arr, sizeof(arr) / sizeof(int));
	selectionSort(arr, sizeof(arr) / sizeof(int));
	
	printArr(arr, sizeof(arr) / sizeof(int));

	return 0;
}

void printArr(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		printf("%d ", arr[i]);
	}
}

void bubbleSort(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < (arrSize - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void selectionSort(int arr[], int arrSize)
{
	int minIndex = 0;
	for (int i = 0; i < (arrSize - 1); i++)
	{
		minIndex = i;
		for (int j = i + 1; j < arrSize; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}
