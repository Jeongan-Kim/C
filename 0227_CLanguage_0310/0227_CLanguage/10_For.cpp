//#define _CRT_SECURE_NO_WARNINGS  //scanf 오류 안나게 해주는 것
//#pragma warning(disable:4996) 
#include <stdio.h>

//명령문 실행 횟수를 정해주고 싶을때 사용하는 함수 for
/*
	for(초기식; 조건식; 증감식(갱신))  //조건식은 조건이면서 bool함수라고 봐도 됨
	{
		명령문;
	}
*/
int main()
{
	//for (int i = 0; i < 5; i++) //0부터 시작하는 것에 익숙해지기, 변수 선언은 괄호 안에서 한번만 할 수 있음. 괄호가 지역이라고 보면 편함
	//{
	//	printf("for문 명령어 %d번 반복중\n", i);
	//}

	//printf("\n");

	////bool => false : 0, true : 1    0외에는 true로 판단하기도 함.

	//for (int i = 5; i; i--) //조건식은 true나 false로만 판단됨. i가 0이되면 false로 판단하여 멈춤
	//{
	//	printf("for문 명령어 %d번 반복중\n", i);
	//}

	//for (;;)
	//{
	//	printf("무한루프\n");

	//}

	//printf("\n");

	//버퍼값 안에 입력되면서 입력받은 갯수를 출력하면서 for문이 돌아가는 약간 억지스러운 함수
	//char num1, num2; 
	//for (; int count = scanf_s("%c %c", &num1, sizeof(num1), &num2, sizeof(num2));) 
	//{
	//	printf("%d\n", count);
	//	while (getchar() != '\n'); 
	//}

	//for (int i = 0, j = 0; i < 10 && j < 10; i++, j += 2)
	//{
	//	printf("%d ", i);
	//	printf("%d\n", j);
	//}

	//printf("\n");

	////3의 배수를 만나면 멈추기
	//for (int i = 1; i <= 10; i++)
	//{
	//	if (i % 3 == 0)
	//		break; //반복문 안에서만 사용할 수 있는 키워드

	//	printf("%d ", i);
	//}

	//printf("\n");

	////3의 배수를 만나면 명령을 실행하지 않고 맨 윗줄로 다시 돌아감
	//for (int i = 1; i <= 10; i++)
	//{
	//	if (i % 3 == 0)
	//		continue;  //반복문 안에서만 사용할 수 있는 키워드

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

	/*
		중첩 for문 // i가 1번 돌때, j가 전부 돎
	*/
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	//
	////구구단
	//for (int i = 2; i < 10; i++)
	//{
	//	printf("***구구단 %d단 시작!***\n", i);
	//	
	//	for (int j = 1; j < 10; j++)
	//	{
	//		printf("%d * %d = %d\n", i, j, i * j);
	//	}
	//	printf("***구구단 %d단 끝!***\n", i);
	//}

	//다이아몬드 크기가 바뀌어도 찍히게

	/*

	공백 1씩 감소
	별은 2배 -1 형태로 늘어남

	*/

	int num;
	printf("다이아몬드 크기 입력 : ");
	scanf_s("%d", &num);

	for (int i = 0; i < (num / 2 + 1); i++)
	{
		for (int j = i; j < (num / 2 + 1); j++)
		{
			printf(" ");
		}
		for (int k = 0; k < (i * 2 + 1); k++)// 0*0, 1*2, 2*3
		{
			printf("*");
		}
		printf("\n");
	}

	for (int i = (num / 2 + 1) - 1; i > 0; i--)
	{
		for (int j = i; j <= (num / 2 + 1); j++)
		{
			printf(" ");
		}
		for (int k = 0; k < ((i - 1) * 2 + 1); k++)
		{
			printf("*");
		}
		printf("\n");

		//abs 절댓값 함수
		printf(" 1 : %d\n", abs(1));
		printf("-1 : %d\n", abs(-1));


	return 0;
}

/*
	*
	**
	***
	****
	*****


	*****
	****
	***
	**
	*


	*****
	 ****
	  ***
	   **
		*

		*
	   **
	  ***
	 ****
	*****

	  *
	 ***
	*****
	 ***
	  *


*/