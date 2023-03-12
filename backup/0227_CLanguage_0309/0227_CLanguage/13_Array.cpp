#include <stdio.h>
#include < stdlib.h>
#include <time.h>

#define ARRSIZE 5

int get_2(void)
{
	return 2;
}

//난수를 중복없이 찍는 방법
void randomnumber();

int main()
{
	int floor101, floor102, floor103, floor104;
	int floor201, floor202, floor203, floor204; //너무 많은 변수를 설정하기 귀찮으니 사용하는 것이 '배열'

	//배열 : 같은 자료형의 변수를 만들어야 할때, 많은 양의 데이터를 다룰 때.
	int floor[40]; //int형 배열 40개 생성, [ ] : index
	float farr[3];
	double darr[5]; //5개 짜리 더블형 변수가 생성.

	//배열 초기화(3개라면 0번째, 1번째, 2번째로 3개가 되는 것)
	int arr1[3] = { 1, 2, 3 }; // 각각 변수를 초기화한 것.
	int arr2[3] = { 0 }; //모두 0으로 초기화.
	int arr3[5] = { 1, 2, 3 }; // 1, 2, 3, 0, 0으로 초기화 됨.
	int arr4[ARRSIZE] = { 0 };
	int arr5[] = { 1, 2, 3 }; // 초기화된 값만 가지고 arr5의 크기가 3으로 잡힘

	char arr6[5] = { 'A', 'B', 'C' }; //초기화 안 된 나머지는 그냥 0, 0으로 초기화
	int a = 1;
	printf("%c, %c, %c\n", arr6[0], arr6[a], arr6[get_2()]);

	printf("%c", arr6[3]); //이 때, 5는 여섯번째 원소를 읽으라고 했으므로 범위가 벗어난 것임.

	printf("\n");

	int arr7[3] = { 0, 1, 2 }; //int 형 3개가 연속으로 들어갔으므로 12byte
	printf("%d %d %d\n", arr7[0], arr7[1], arr7[2]);
	printf("%p %p %p\n", &arr7[0], &arr7[1], &arr7[2]);//16진수로 각 수가 어디에 저장되어 있는지 주소를 알 수 있음.

	printf("%d\n", sizeof(arr7)); //전체 사이즈
	printf("%d\n", sizeof(arr7) / sizeof(int)); //하나의 사이즈

	int size = sizeof(arr7) / sizeof(int);

	for (int i = 0; i < size; i++) //수 배열 각각 인덱스를 한 번에 출력하는 반복문
	{
			printf("%d ", arr7[i]);
	} 

	randomnumber();

	return 0;
}

void randomnumber()
{
	srand((unsigned int)time(NULL)); // 랜덤함수의 시드값을 지정해주는 함수, 반복문 안에 돌리면 같은 값이 뽑힘, 왜냐면 시드가 초단위인데 반복문은 그보다 더 빨리 돌아서 같은 값이 나옴.
	int number[10] = { 0 };

	for (int i = 0; i < 10; i++)
	{
		number[i] = rand() % 10 + 1;

		for (int j = 0; j < i; j++)
		{
			if (number[i] == number[j])
			{
				i--; //i가 ++될 것이므로 하나 줄여서 다시 뽑아오도록
				break;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", number[i]);
	}
}

/*
	로또 만들기
	1 2 3 4 5 6 B(보너스)
	다 맞히면 일등
	... 5등까지 출력하기


*/
