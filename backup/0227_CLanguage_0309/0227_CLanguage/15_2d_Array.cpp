#include <stdio.h>

//�ڷ���[��][��];

/*
 int arr[3];
 ������
 => arr[2]

 2����>
	int arr[3][5]

	����������
	����������
	����������
	�޸𸮿��� ���������� ����Ǿ� ����

	=> arr[2][3] 2�� 3���� ����

3����>
	int arr[3][5][7]

*/

//initialize
int arrOne[10]; //���̰� 10�� �迭
int arrTwo[5][5]; //���� ���� ���̰� 5�� �迭
float arrThree[3][3][3]; //���� ���� ���̰� 3�� float�� �迭

int arr1[2][3] = { 1, 2, 3, 4, 5, 6 };
int arr2[2][3] = { {1, 2, 3}, {4, 5, 6} };
//1 2 3
//4 5 6
int arr3[2][3] = { 1, 2, 3 };
int arr4[][3] = { 1, 2, 3 }; //���� �����ؼ� �ۼ� ����
int arr5[][3] = { {1, 2}, {3, 4, 5}, {6} };//3�� 3��¥��
//int arr6[2][] = { 1, 2, 3, 4, 5, 6 }; ���� ������ �ȵ�

void printArr();

int main()
{
	printArr();

	int arr7[4][2];

	printf("�迭�� ��ü ����Ʈ ũ�� : %d����Ʈ\n", sizeof(arr7));
	printf("�迭�� 1�� ����Ʈ ũ�� : %d����Ʈ\n", sizeof(arr7[0])); // arr7[0] �� 1�ุ ����� ��

	printf("�迭�� ������ ���� : %d\n", sizeof(arr7) / sizeof(int)); //sizeof(arr7[0][0])�� ����?
	printf("�迭�� ���� ���� : %d\n", sizeof(arr7) / sizeof(arr7[0]));
	printf("�迭�� ���� ���� : %d\n", sizeof(arr7[0]) / sizeof(arr7[0][0]));

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
