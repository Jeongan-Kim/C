#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MYNUM 6
#define LOTTONUM 7 //수를 고정
void Lotto();

int main()
{
	Lotto();
	return 0;
}

void Lotto()
{
	srand((unsigned int)time(NULL)); //while 문 밖에 두는 게 더 랜덤함

	while (true)
	{
		int num[MYNUM];
		int lotto[LOTTONUM];
		int count = 0;
		int bonus = 0;

		for (int i = 0; i < LOTTONUM; i++)
		{
			lotto[i] = rand() % 45 + 1;

			for (int j = 0; j < i; j++)
			{
				if (lotto[i] == lotto[j])
					i--;
			}
		}

		printf("로또 번호를 입력해주세요 : ");

		for (int i = 0; i < MYNUM; i++)
			scanf_s("%d", &num[i]);

		for (int i = 0; i < LOTTONUM; i++)
		{
			for (int j = 0; j < MYNUM; j++)
			{
				if (lotto[i] == num[j])
					count++;
			}
		}

		for (int i = 0; i < MYNUM; i++)
		{
			if (lotto[LOTTONUM - 1] == num[i])
				bonus++;
		}
		printf("\n");

		printf("이번 주 당첨 번호 : ");
		for (int i = 0; i < LOTTONUM; i++)
		{
			printf("%d ", lotto[i]);
		}
		printf("\n");

		printf("내가 적은 번호 : ");
		for (int i = 0; i < MYNUM; i++)
		{
			printf("%d ", num[i]);
		}

		if (count == 6 && bonus != 1)
		{
			printf("1등 입니다!!");
			break;
		}
		else if (count == 6 && bonus == 1)
		{
			printf("2등 입니다!!");
			break;
		}
		else if (count == 5)
		{
			printf("3등 입니다!!");
			break;
		}
		else if (count == 4)
		{
			printf("4등 입니다!!");
			break;
		}
		else if (count == 3)
		{
			printf("5등 입니다!!");
			break;
		}
		else
			printf("다음에 다시 도전해 주세요.");

	}
}
