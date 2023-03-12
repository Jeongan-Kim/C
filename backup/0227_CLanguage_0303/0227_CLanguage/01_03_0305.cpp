#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main()
{
	////난수 생성
	//printf("%d, ", rand() % 10);

	//srand((unsigned int)time(NULL));

	//printf(" % d, ", rand() % 10);

	////while문

	//bool study = true;
	//while (study)
	//{
	//	printf("Hello World!\n");
	//	
	//	printf("공부 중인가요? [네 : 1, 아니오 : 0] -> ");
	//	int answer = -1;
	//	scanf_s("%d", &answer);

	//	if (answer == 0)
	//	{
	//		study = false;
	//	}
	//}



	//char key;
	//while (true)
	//{
	//	printf("이동키 입력 : ");
	//	key = _getch();

	//	if (key == 'q')
	//		break;

	//	switch (key)
	//	{
	//	case'w':printf("상\n"); break;
	//	case's':printf("하\n"); break;
	//	case'a':printf("좌\n"); break;
	//	case'd':printf("우\n"); break;
	//	default: printf("잘못누름\n"); break;
	//	}
	//}


	//const int secretCode = 123123;

	//int password = 0;
	//int tryCount = 0;

	//do
	//{
	//	if (tryCount >= 3)
	//	{
	//		printf("3회 실패, 계정 잠금!\n");
	//		break;
	//	}
	//	printf("비밀번호 입력 (3회 실패 시 잠금, 현재 실패 횟수 : %d)\n", tryCount);
	//	scanf_s("%d", &password);

	//	tryCount++;
	//} while (password != secretCode);

	//for (int i = 0; i < 5; i++)
	//{
	//	printf("for문 명령어 %d번 반복중\n", i);
	//}

	//printf("\n");

	//for (int i = 5; i; i--)
	//{
	//	printf("for문 명령어 %d번 반복중\n", i);
	//}

	//for (;;)
	//{
	//	printf("무한루프\n");
	//}

	int num1, num2;
	for (; int count = scanf_s("%d %d", &num1, &num2);)
	{
		printf("%d\n", count);
		while (getchar() != '\n');
	}

	//for (int i = 0, j = 0; i < 10 && j < 10; i++, j += 2)
	//{
	//	printf("%d ", i);
	//	printf("%d\n", j);
	//}

	//for (int i = 1; i <= 10; i++)
	//{
	//	if (i % 3 == 0)
	//		break;

	//	printf("%d ", i);
	//}

	//printf("\n");


	//for (int i = 1; i <= 10; i++)
	//{
	//	if (i % 3 == 0)
	//		continue;

	//	printf("%d ", i);
	//}

	//printf("\n");

	//for (int c = 'A'; c <= 'Z'; c++)
	//	printf("%c ", c);

	//printf("\n");

	//for (int c = 'Z'; c >= 'A'; c--)
	//	printf("%c ", c);

	//printf("\n");

	//int total = 0;
	//int num = 0;

	//printf("0부터 num까지의 덧셈 구하기. num : ");
	//scanf_s("%d", &num);

	//for (int i = 0; i <= num; i++)
	//{
	//	total += i;
	//}
	//printf("0부터 %d까지의 덧셈 = %d\n", num, total);

//for (int i = 0; i < 5; i++)
//{
//	for (int j = 0; j < 5; j++)
//	{
//		printf("*");
//	}
//	printf("\n");
//}
//
//for (int i = 2; i < 10; i++)
//{
//	printf("***구구단 %d단 시작!***\n", i);
//
//	for (int j = 1; j < 10; j++)
//	{
//		printf("%d * %d = %d\n", i, j, i * j);
//	}
//	printf("***구구단 %d단 끝!***\n\n", i);
//}
	return 0;
}