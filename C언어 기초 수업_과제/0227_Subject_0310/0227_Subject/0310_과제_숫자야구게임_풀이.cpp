#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void RandomNum(int baseBall[]);
void BaseballGame(int baseBall[], int UserNum[]);
void PrintNum(int baseBall[]);

int main()
{
	int baseball[3];
	int usernum[3];

	RandomNum(baseball);
	BaseballGame(baseball, usernum);
	PrintNum(baseball);

	return 0;
}

void RandomNum(int baseBall[])
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 3; i++)
	{
		baseBall[i] = rand() % 9 + 1;

		for (int j = 0; j < i; j++)
		{
			if (baseBall[i] == baseBall[j])
				i--;
		}
	}
}

void BaseballGame(int baseBall[], int UserNum[])
{
	int chance = 0;

	while (chance != 10)
	{
		chance++;


		int strike = 0;
		int ball = 0;

		printf("숫자를 입력 하시오 : ");

		for (int i = 0; i < 3; i++)
		{
			scanf_s("%d", &UserNum[i]);
		}

		for (int i = 0; i < 3; i++)
		{
			if (baseBall[i] == UserNum[i])
				strike++;
			for (int j = 0; j < 3; j++)
			{
				if (baseBall[i] == UserNum[j])
					ball++;
			}

		}

		ball -= strike;

		printf("%d strike %d ball", strike, ball);

		if (strike == 3)
		{
			printf("이겼습니다!!\n");
			exit(0); //main 함수가 아예 끝나게끔 함, return은 void함수에서 그 함수 자체만 종료하는 것.
		}

	}

}

void PrintNum(int baseBall[])
{
	printf("실패!! 컴퓨터의 숫자는 : ");

	for (int i = 0; i < 3; i++)
		printf("%d", baseBall[i]);
}
