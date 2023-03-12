#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int arrSize);
void printArr(int arr[], int arrSize);
void getInt(int arr[], int arrSize);
void randomnumber(int arr[], int arrSize);
void winNum(int arr1[], int arr2[]);

int main()
{
	printf("�ζ� ��ȣ�� 7���� �Է��ϼ���.\n ��ȣ�� �� 1~45 ���� ���� �Է��ϼ���.\n �Է� : ");
	int myLottoNum[7] = { 0 };
	getInt(myLottoNum, sizeof(myLottoNum) / sizeof(int));
	
	printf("���� �Է��� �ζ� ��ȣ : ");
	printArr(myLottoNum, sizeof(myLottoNum) / sizeof(int));

	printf("\n");

	int LottoNum[7] = { 0 };
	randomnumber(LottoNum, sizeof(LottoNum) / sizeof(int));

	int LottoNumSize = sizeof(LottoNum) / sizeof(int);
	selectionSort(LottoNum, LottoNumSize);

	printf("�̹� �� �ζ� ��÷ ��ȣ : ");
	printArr(LottoNum, LottoNumSize - 1);

	printf("\n");

	printf("���ʽ� ��ȣ : %d\n", LottoNum[6]);

	winNum(myLottoNum, LottoNum);
	

	return 0;
}

void selectionSort(int arr[], int arrSize)
{
	int minIndex = 0;

	for (int i = 0; i < arrSize - 1; i++)
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

void printArr(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		printf("%d ", arr[i]);
	}
}

void getInt(int arr[], int arrSize)
{
	for (int j = 0; j < arrSize; j++)
	{
		scanf_s("%d", &arr[j]);
		if (arr[j] > 45)
		{
			printf("45 ������ ���� �Է��� �ּ���.\n");
			j--;
		}
	}

	selectionSort(arr, arrSize);
}

void randomnumber(int arr[], int arrSize)
{
	srand((unsigned int)time(NULL));
	
	for (int i = 0; i < arrSize; i++)
	{
		
		arr[i] = rand() % 45 + 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				i--;
				break;
			}
		}
	}
}

void winNum(int arr1[], int arr2[])
{
	int winNum = 0;
	for (int i = 0; i < (sizeof(arr1) / sizeof(int)); i++)
	{
		for (int j = 0; j < (sizeof(arr2) / sizeof(int)); j++)
		{
			if (arr1[i] == arr2[j])
				winNum++;
		}
	}

	if (winNum == 7)
		printf("1���Դϴ�.\n");
	else if (winNum == 6)
		printf("2���Դϴ�.\n");
	else if (winNum == 5)
		printf("3���Դϴ�.\n");
	else if (winNum == 4)
		printf("4���Դϴ�.\n");
	else if (winNum == 3)
		printf("5���Դϴ�.\n");
	else
		printf("��÷�Դϴ�.\n");
}


