#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int bingo[5][5];

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			bingo[i][j] = rand() % 25 + 1;
			if (i == 0 && j == 0)
				continue;
			else
			{
				for (int a = 0, b = 0; a <= i; b++)
				{	
					if (b == 5)
					{
						a++;
						b = 0;
					}

					if (a == i && b == j)
						break;

					if (bingo[i][j] == bingo[a][b])
					{
						j--;
						if (j < 0)
							j == 0;
						break;
					}

				}
			}
		}
	}

	int my_select;
	int bingo_count = 0;

	while (bingo_count < 3)
	{	
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (bingo[i][j] == 0)
					printf("x\t");
				else
					printf("%d\t", bingo[i][j]);
			}
			printf("\n");
		}

		printf("지우고 싶은 수를 말하세요. : ");		
		scanf_s("%d", &my_select);
		
		int a, b;
		int x_num = 0;
		int x_num2 = 0;
		int x_num3 = 0;
		int x_num4 = 0;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (bingo[i][j] == my_select)
				{
					bingo[i][j] = 0;
					a = i;
					b = j;
					break;
				}
			}
		}

		//bingo[a][b]의 가로 세로 빙고 확인
		for (int i = 0; i < 5; i++)
		{
			if (bingo[a][i] == 0)
				x_num++;

			if (bingo[i][b] == 0)
				x_num2++;

			if (x_num == 5)
				bingo_count++;
			if (x_num2 == 5)
				bingo_count++;
		}

		//bingo[a][b]의 대각선 빙고 확인
		if (a + b == 4)
		{
			for (int i = 0; i < 5; i++)
			{
				int j = 4 - i;
				if (bingo[i][j] == 0)
					x_num3++;

				if (x_num3 == 5)
					bingo_count++;
			}
		}

		//bingo[a][b]의 대각선 빙고 확인
		if(a == b)
		{
			for (int i = 0; i < 5; i++)
			{
				if (bingo[i][i] == 0)
					x_num4++;

				if (x_num4 == 5)
					bingo_count++;
			}
		}

		printf("\n빙고 : %d\n", bingo_count);
	}

	printf("3 빙고 이상으로 게임이 종료됩니다.");

	return 0;
}