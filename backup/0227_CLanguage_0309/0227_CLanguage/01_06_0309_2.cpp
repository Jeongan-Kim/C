#include <stdio.h>

int arrOne[10];
int arrTwo[5][5];
float arrThree[3][3][3];

int arr1[2][3] = { 1, 2, 3, 4, 5, 6 };
int arr2[2][3] = { {1, 2, 3}, {4, 5, 6} };
int arr3[2][3] = { 1, 2, 3 };
int arr4[][3] = { 1, 2, 3 };
int arr5[][3] = { {1, 2}, {3, 4, 5}, {6} };

void printArr();

int main()
{
	printArr();

	int arr7[4][2];
	/*
	ㅁㅁ ㅁㅁ ㅁㅁ ㅁㅁ
	*/
	//arr0[4][2]
	//	arr1[4] = { arr2[2] = {1,2}, arr3[2] = {3,4}, arr4[2] = {5,6}, arr5[2] = {7,8} }



	printf("배열의 전체 바이트 크기 : %d바이트\n", sizeof(arr7));
	printf("배열의 1행 바이트 크기 : %d바이트\n", sizeof(arr7[0])); 

	printf("배열의 원소의 개수 : %d\n", sizeof(arr7)/sizeof(int)); 
	printf("배열의 행의 개수 : %d\n", sizeof(arr7)/sizeof(arr7[0]));
	printf("배열의 열의 개수 : %d\n", sizeof(arr7[0])/sizeof(arr7[0][0]));

	return 0;
}

void printArr()
{
	printf("*** arr1 ***\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", arr1[i][j]);
		printf("\n");
	}

	printf("\n");

	printf("*** arr2 ***\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", arr2[i][j]);
		printf("\n");
	}

	printf("\n");

	printf("*** arr3 ***\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", arr3[i][j]);
		printf("\n");
	}

	printf("\n");

	printf("*** arr4 ***\n");
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", arr4[i][j]);
		printf("\n");
	}

	printf("\n");

	printf("*** arr5 ***\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d ", arr5[i][j]);
		printf("\n");
	}




}
