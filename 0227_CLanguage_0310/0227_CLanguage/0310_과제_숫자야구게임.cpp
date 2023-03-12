#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Scanf(int arr[], int arrSize);

int main()
{
	int baseballNum[3] = { 0 };
	int myNum[3] = { 0 };
	int failCount = 0;
	int strike;
	int ball;


	srand((unsigned int)time(NULL));
	for (int i = 0; i < 3; i++)
	{
		baseballNum[i] = rand() % 9 + 1;
		for (int j = 0; j < i; j++)
		{
			if (baseballNum[i] == baseballNum[j])
				i--;
		}
	}

	printf("*** 숫자 야구 게임을 시작합니다 ***\n");
	
	while (failCount < 10)
	{
		printf("예측한 수 3개를 입력해 주세요. 10번 시도 안에 맞히지 못 하면 집니다.\n 입력 : ");
		//scanf_s("%d %d %d", &myNum[0], &myNum[1], &myNum[2]);
	
		Scanf(myNum, sizeof(myNum) / sizeof(int));
		printf("내가 예측한 수 : %d %d %d\n", myNum[0], myNum[1], myNum[2]);

		strike = 0;
		ball = 0;

		for (int i = 0; i < 3; i++)
		{

			for (int j = 0; j < 3; j++)
			{
				if (myNum[i] == baseballNum[j])
				{
					if (i == j)
						strike++;
					else if(i != j)
						ball++;
				}
			}

		}
		if (strike == 3)
		{
			printf("정답입니다! 축하합니다.\n");
			break;
		}
		else if (strike < 3)
			failCount++;

		printf("결과 : %d strike\t%d ball\t\t 시도 횟수 : %d\n\n", strike, ball, failCount);
	}

	if (failCount == 10)
		printf("10번 동안 답을 맞히지 못 했습니다. 다시 도전해 보세요.");
	return 0;
}

void Scanf(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		scanf_s("%d", &arr[i]);
		if (arr[i] > 10 || arr[i] < 0)
		{
			printf("1~9의 수를 입력해 주세요.\n");
			i--;
		}
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				printf("서로 다른 수를 입력해 주세요.\n");
				i--;
			}
		}
	}
}
