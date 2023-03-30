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

	for (int i = 0; i <= 25; i++)
	{
		if (i < 5)
			snail[0][i] = i + 1;
		else if (i > 5 && i <= 9)
			snail[i % 5][4] = i;
		else if (i >= 10 && i <= 13)
			snail[4][13 - i] = i;
		else if (i / 5 >= 2 && i / 5);
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