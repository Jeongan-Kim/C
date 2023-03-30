#include <stdio.h>

// 과제 => 달팽이 배열 : 인덱스 바꿔서 출력하는 아이디어를 이용해서 빙글빙글 돌게 찍기

int main()
{
	int snail[5][5] = { 0 };

	/*
	0	01 02 03 04 05
	1	16 17 18 19 06
	2	15 24 25 20 07
	3	14 23 22 21 08
	4	13 12 11 10 09

	1. i가 짝수일때 가로로 짝수 카운트가 짝수일때 역순으로
	2. 꺾인 카운트를 세어서 짝수일때 내려가고, 끝에 닿으면 꺾이게.

	++방향마다 배열 인덱스로 봤을때 얼마나 늘어나는지 생각해서 계산?
	*/

	int count = 0; // 방향 바뀌는 횟수
	int xcount = 0; //세로 횟수
	int ycount = 0; //가로 횟수
	int x = 0, y = 0;
	int num = 1; //달팽이 숫자

	while (num < 26)
	{
		switch (count) // 가로 : y가 커지거나 작아짐
		{
		case 0:
			if (ycount % 2 == 0) // 가로 순방향
			{
				while (1)
				{
					if (snail[x][y] != 0 || y > 4 || x > 4)
					{
						ycount++;
						count = 1;
						y--;
						x++;
						break;
					}
					snail[x][y] = num;
					printf("%d (%d, %d) [0, 0]\n", num, x, y);
					num++;
					y++;
					
				}

			}
			else if (ycount % 2 == 1)//가로 역방향
			{
				while (1)
				{
					if (snail[x][y] != 0 || y > 4 || x > 4)
					{
						ycount++;
						count = 1;
						y++;
						x--;
						break;
					}
					snail[x][y] = num;
					printf("%d (%d, %d) [0, 1]\n", num, x, y);
					num++;
					y--;
					
				}
			}
			
			break;
			
		case 1: // 세로 : x가 커지거나 작아짐
			if (xcount % 2 == 0) // 세로 순방향
			{
				while (1)
				{
					if (snail[x][y] != 0 || y > 4 || x > 4)
					{
						xcount++;
						count = 0;
						x--;
						y--;
						break;
					}
					snail[x][y] = num;
					printf("%d (%d, %d)  [1, 0]\n", num, x, y);
					num++;
					x++;
					
				}
			}
			else if (xcount % 2 == 1)//세로 역방향
			{
				while (1)
				{
					if (snail[x][y] != 0 || y > 4 || x > 4)
					{
						xcount++;
						count = 0;
						x++;
						y++;
						break;
					}
					snail[x][y] = num;
					printf("%d (%d, %d)  [1, 1]\n", num, x, y);
					num++;
					x--;
					
				}
			}
			break;
		}
			
		
		
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d\t", snail[i][j]);
		}
		printf("\n");
	}
	return 0;
}