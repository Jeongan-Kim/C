#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRSIZE 5

int getInt(void)
{
	printf("숫자를 입력해 주세요 : ");
	int n;
	scanf_s("%d", &n);

	return n;
}

int add(int x, int y)
{
	return x + y;
}

void ShowNumber(int num)
{
	printf("들어온 값은 : %d\n", num);
}

void test()
{
	printf("11111111111111\n");

	return;

	printf("222222222222222\n");
}

int Compare(int num1, int num2)
{
	if (num1 > num2)
		return num1;
	else
		return num2;
}

void Recursive(int num)
{
	if (num == 0)
		return;
	printf("Hello to myself\n");
	Recursive(num - 1);
}

int Factorial(int n)
{
	if (n == 0)
		return 1;

	return n * Factorial(n - 1);
}

int get_2(void)
{
	return 2;
}

void randomnumber()
{
	srand((unsigned int)time(NULL));
	int number[10] = { 0 };

	for (int i = 0; i < 10; i++)
	{
		number[i] = rand() % 10 + 1; //1~10 중에 랜덤으로 뽑아서 초기화하기

		for (int j = 0; j < i; j++) //i번째 난수와 작은 수들을 차례로 비교해서 같으면 다시 뽑게 하는 과정
		{
			if (number[i] == number[j])
			{
				i--;
				break;
			}

		}
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", number[i]);
	}
}

int main(void)
{
	//int x1 = 0;
	//int y1 = 0;

	//x1 = getInt();
	//y1 = getInt();

	//printf("%d + %d = %d\n", x1, y1, add(x1, y1));

	//int num = getInt();
	//ShowNumber(num);

	//test();

	//printf("둘 중 더 큰 수는? %d\n", Compare(x1, y1));

	//Recursive(3);

	//int n;
	//scanf_s("%d", &n);

	//printf("%d", Factorial(n));

	int floor[40];
	float farr[3];
	double darr[5];

	int arr1[3] = { 1, 2, 3 };
	int arr2[3] = { 0 };
	int arr3[5] = { 1, 2, 3 };
	int arr4[ARRSIZE] = { 0 };
	int arr5[] = { 1, 2, 3 };

	char arr6[5] = { 'A', 'B', 'C' }; //////////////////
	int a = 1;
	printf("%c, %c, %c\n", arr6[0], arr6[a], arr6[get_2()]);

	printf("%c입니다.", arr6[4]); ////////////////////////

	printf("\n");

	int arr7[3] = { 0, 1, 2 };
	printf("%d %d %d\n", arr7[0], arr7[1], arr7[2]);
	printf("%p %p %p\n", &arr7[0], &arr7[1], &arr7[2]);

	printf("%d\n", sizeof(arr7));
	printf("%d\n", sizeof(arr7) / sizeof(int)); //3

	int size = sizeof(arr7) / sizeof(int);

	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr7[i]);
	}

	printf("\n");

	randomnumber();


	return 0;
}