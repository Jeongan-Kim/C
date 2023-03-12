#include <stdio.h>

//sort : ����
//bubble ����(�տ������� �ΰ��� ���ϸ鼭 �������� �Ǵ� �������� ������ �ٲ�)
//����(selection) ����(�ּڰ��� ���� ��, ���� �� �ڸ��� �� ���� �ٲ�, �� ���Ĵ� ù��° �ε����� �ΰ� ������ �۾� �ݺ�)

void printArr(int arr[], int arrSize);
void bubbleSort(int arr[], int arrSize);
void selectionSort(int arr[], int arrSize);

int main()
{
	int arr[5] = { 3, 5, 4, 1, 2 };
	
	printArr(arr, sizeof(arr) / sizeof(int));

	bubbleSort(arr, sizeof(arr) / sizeof(int));
	printArr(arr, sizeof(arr) / sizeof(int));

	printf("\n");

	selectionSort(arr, sizeof(arr) / sizeof(int));
	printArr(arr, sizeof(arr) / sizeof(int));
	return 0;
}

void printArr(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void bubbleSort(int arr[], int arrSize) //ȿ������ ������ ����
{
	for (int i = 0; i < arrSize; i++) //i�� �ѹ��� ����Ŭ�̶�� �����ϸ� ����
	{
		for (int j = 0; j < (arrSize - 1) - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j]; //�ӽ� ������ j���� �־����
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void selectionSort(int arr[], int arrSize)
{
	int minIndex = 0; //���������̸� ���� ū ������ �����ϸ� ��

	for (int i = 0; i < arrSize - 1; i++) //�ϳ� ������ ã���� ������ ã�� �ʿ�����Ƿ� �ѹ� �� ���� ����
	{
		minIndex = i;//�켱 ù��°���� ���� �۴ٰ� ����
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
