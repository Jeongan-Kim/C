#include <stdio.h>

//sort : 정렬
//bubble 정렬(앞에서부터 두개씩 비교하면서 오름차순 또는 내림차순 식으로 바꿈)
//선택(selection) 정렬(최솟값을 정한 뒤, 가장 앞 자리와 그 수를 바꿈, 그 이후는 첫번째 인덱스를 두고 나머지 작업 반복)

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

void bubbleSort(int arr[], int arrSize) //효율성이 좋지는 않음
{
	for (int i = 0; i < arrSize; i++) //i를 한번의 사이클이라고 생각하면 편함
	{
		for (int j = 0; j < (arrSize - 1) - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j]; //임시 변수에 j값을 넣어놓음
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void selectionSort(int arr[], int arrSize)
{
	int minIndex = 0; //내림차순이면 가장 큰 값으로 설정하면 됨

	for (int i = 0; i < arrSize - 1; i++) //하나 전까지 찾으면 끝까지 찾을 필요없으므로 한번 덜 돌게 설정
	{
		minIndex = i;//우선 첫번째값이 가장 작다고 설정
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
