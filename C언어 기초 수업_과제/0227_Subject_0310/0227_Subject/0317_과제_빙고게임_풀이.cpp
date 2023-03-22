#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bingo[5][5];

void Swap(int sour1, int dest1, int sour2, int dest2)
{
	int temp = bingo[sour1][dest1];
	bingo[sour1][dest1] = bingo[sour2][dest2];
	bingo[sour2][dest2] = temp;
}

void shuffle(int n) //n번 섞음
{
	for (int i = 0; i < n; i++)
	{
		int sour1 = rand() % 5;
		int dest1 = rand() % 5;
		int sour2 = rand() % 5;
		int dest2 = rand() % 5;

		Swap(sour1, dest1, sour2, dest2);
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	int input;
	int bingocount = 0;

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			bingo[x][y] = y * 5 + x;
		}
	}

	shuffle(1000);

	while (bingocount < 3)
	{
		printf("빙고 개수 : %d\n", bingocount);

		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				if (bingo[x][y] != -1)
					printf("%d\t", bingo[x][y]);
				else
					printf("X\t");
			}
			printf("\n");
		}

		scanf_s("%d", &input);

		if (input > 24 || input < 0)
		{
			printf("다시 입력해 주세요.\n");
			continue;
		}

		bool ischeck = false;

		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				if(input == bingo[x][y])
				{
					bingo[x][y] = -1;
					ischeck = true;
				}
			}
		}

		if (!ischeck) //?
		{
			printf("중복된 숫자입니다.\n");
			continue;
		}

		bingocount = 0;

		for (int y = 0; y < 5; y++)
		{
			int Xcount = 0;
			{
				for (int x = 0; x < 5; x++)
				{
					if (bingo[x][y] == -1)
						Xcount++;
				}
			}

			if (Xcount == 5) bingocount++;
		}

		for (int x = 0; x < 5; x++)
		{
			int Ycount = 0;
			{
				for (int y = 0; y < 5; y++)
				{
					if (bingo[x][y] == -1)
						Ycount++;
				}
			}

			if (Ycount == 5) bingocount++;
		}

		int Ccount = 0;
		int Ccount2 = 0;

		for (int i = 0; i < 5; i++)
		{
			if (bingo[i][i] == -1)
				Ccount++;
			if (bingo[i][4 - i] == -1)
				Ccount2++;
		}
		if (Ccount == 5) bingocount++;
		if (Ccount2 == 5) bingocount++;
	}

	printf("빙고 개수 : %d\n", bingocount);


	return 0;
}