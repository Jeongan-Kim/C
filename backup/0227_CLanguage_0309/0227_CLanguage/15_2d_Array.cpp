#include <stdio.h>

//切戟莫[楳][伸];

/*
 int arr[3];
 けけし
 => arr[2]

 2託据>
	int arr[3][5]

	けけけけけ
	けけけけけ
	けけけしけ
	五乞軒拭澗 尻紗旋生稽 煽舌鞠嬢 赤製

	=> arr[2][3] 2楳 3伸稽 羨悦

3託据>
	int arr[3][5][7]

*/

//initialize
int arrOne[10]; //掩戚亜 10昔 壕伸
int arrTwo[5][5]; //亜稽 室稽 掩戚亜 5昔 壕伸
float arrThree[3][3][3]; //亜稽 室稽 株戚亜 3昔 float莫 壕伸

int arr1[2][3] = { 1, 2, 3, 4, 5, 6 };
int arr2[2][3] = { {1, 2, 3}, {4, 5, 6} };
//1 2 3
//4 5 6
int arr3[2][3] = { 1, 2, 3 };
int arr4[][3] = { 1, 2, 3 }; //楳精 持繰背辞 拙失 亜管
int arr5[][3] = { {1, 2}, {3, 4, 5}, {6} };//3楳 3伸促軒
//int arr6[2][] = { 1, 2, 3, 4, 5, 6 }; 伸精 持繰戚 照喫

void printArr();

int main()
{
	printArr();

	int arr7[4][2];

	printf("壕伸税 穿端 郊戚闘 滴奄 : %d郊戚闘\n", sizeof(arr7));
	printf("壕伸税 1楳 郊戚闘 滴奄 : %d郊戚闘\n", sizeof(arr7[0])); // arr7[0] 精 1楳幻 啄嬢層 依

	printf("壕伸税 据社税 鯵呪 : %d\n", sizeof(arr7) / sizeof(int)); //sizeof(arr7[0][0])亀 亜管?
	printf("壕伸税 楳税 鯵呪 : %d\n", sizeof(arr7) / sizeof(arr7[0]));
	printf("壕伸税 伸税 鯵呪 : %d\n", sizeof(arr7[0]) / sizeof(arr7[0][0]));

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
