#include <stdio.h>


//길이가 같은 두 1차원 정수 배열 a, b가 매개변수로 주어집니다. a와 b의 내적을 return 하도록 solution 함수를 완성해주세요.
//이때, a와 b의 내적은 a[0] * b[0] + a[1] * b[1] + ... + a[n - 1] * b[n - 1] 입니다. (n은 a, b의 길이)
//제한사항
//a, b의 길이는 1 이상 1000 이하입니다.
//a, b의 모든 수는 - 1000 이상 1000 이하입니다.
//입출력 예
//a   b   result
//[1, 2, 3, 4][-3, -1, 0, 2] 3
//[-1, 0, 1][1, 0, -1] - 2
//입출력 예 설명
//입출력 예 #1
//a와 b의 내적은 1 * (-3) + 2 * (-1) + 3 * 0 + 4 * 2 = 3 입니다.
//입출력 예 #2
//a와 b의 내적은(-1) * 1 + 0 * 0 + 1 * (-1) = -2 입니다.


void solution(int a[], int size_a, int b[]);
void scanf(int a[], int size_a);

int main()
{
	//int a[3] = { -1, 0, 1 };
	//int b[3] = { 1, 0, -1 };
	int arr_size;
	int a[1000];
	int b[1000];

	printf("길이가 같은 두 1차원 정수 배열 a, b를 입력해 주세요.\n");
	printf("먼저 정수 배열의 길이를 결정하세요.(1~1000) : ");

	while (true)
	{
		scanf_s("%d", &arr_size);
		if (arr_size > 1000 || arr_size < 0)
		{
			printf("길이가 1 이상 1000 이하가 아닙니다. 다시 입력해 주세요.\n");
		}
		else
			break;
	}

	printf("a 배열(정수 범위 : -1000 ~ 1000) : ");
	scanf(a, arr_size);

	printf("\n");

	printf("b 배열(정수 범위 : -1000 ~ 1000) : ");
	scanf(b, arr_size);

	printf("\n");

	solution(a, arr_size, b);

	return 0;
}

void solution(int a[], int size_a, int b[])
{
	int inner_product = 0;
	printf("a와 b의 내적은 ");

	for (int i = 0; i < size_a; i++)
	{
		if (a[i] < 0)
			printf("(%d) ", a[i]);
		else 
			printf("%d ", a[i]);

		printf("* ");

		if (b[i] < 0)
			printf("(%d) ", b[i]);
		else
			printf("%d ", b[i]);

		if (i < size_a - 1)
			printf("+ ");

		inner_product += a[i] * b[i];
	}
	printf("= %d\n", inner_product);
	
}

void scanf(int a[], int size_a)
{
	for (int i = 0; i < size_a; i++)
	{
		scanf_s("%d", &a[i]);
		while (true)
		{
			if (a[i] > 1000 || a[i] < -1000)
				printf("정수 범위를 벗어난 수입니다. 다시 입력해 주세요.\n");
			else
				break;
		}
	}
}
