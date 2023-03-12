#include <stdio.h>

//자료형[행][열];

/*
 int arr[3];
 ㅁㅁㅇ
 => arr[2]

 2차원>
	int arr[3][5]

	ㅁㅁㅁㅁㅁ
	ㅁㅁㅁㅁㅁ
	ㅁㅁㅁㅇㅁ
	메모리에는 연속적으로 저장되어 있음

	=> arr[2][3] 2행 3열로 접근

3차원>
	int arr[3][5][7]

*/

//initialize
int arrOne[10]; //길이가 10인 배열
int arrTwo[5][5]; //가로 세로 길이가 5인 배열
float arrThree[3][3][3]; //가로 세로 높이가 3인 float형 배열

int arr1[2][3] = { 1, 2, 3, 4, 5, 6 };
int arr2[2][3] = { {1, 2, 3}, {4, 5, 6} };
//1 2 3
//4 5 6
int arr3[2][3] = { 1, 2, 3 };
int arr4[][3] = { 1, 2, 3 }; //행은 생략해서 작성 가능
int arr5[][3] = { {1, 2}, {3, 4, 5}, {6} };//3행 3열짜리
//int arr6[2][] = { 1, 2, 3, 4, 5, 6 }; 열은 생략이 안됨

void printArr();

int main()
{
	printArr();

	int arr7[4][2];

	printf("배열의 전체 바이트 크기 : %d바이트\n", sizeof(arr7));
	printf("배열의 1행 바이트 크기 : %d바이트\n", sizeof(arr7[0])); // arr7[0] 은 1행만 찍어준 것

	printf("배열의 원소의 개수 : %d\n", sizeof(arr7) / sizeof(int)); //sizeof(arr7[0][0])도 가능?
	printf("배열의 행의 개수 : %d\n", sizeof(arr7) / sizeof(arr7[0]));
	printf("배열의 열의 개수 : %d\n", sizeof(arr7[0]) / sizeof(arr7[0][0]));

	return 0;
}

#pragma region print_array
void printArr()
{
	//arr1
	printf("*** arr1 ***\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr1[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	//arr2
	printf("*** arr2 ***\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	//arr3
	printf("*** arr3 ***\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr3[i][j]);
		}
		printf("\n");
	}

	//arr4
	printf("*** arr4 ***\n");
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr4[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	//arr5
	printf("*** arr5 ***\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr5[i][j]);
		}
		printf("\n");
	}

	printf("\n");
}
#pragma endregion
