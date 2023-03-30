#include <stdio.h>

// ���� => ������ �迭 : �ε��� �ٲ㼭 ����ϴ� ���̵� �̿��ؼ� ���ۺ��� ���� ���

int main()
{
	int snail[5][5] = { 0 };

	/*
	0	01 02 03 04 05
	1	16 17 18 19 06
	2	15 24 25 20 07
	3	14 23 22 21 08
	4	13 12 11 10 09

	1. i�� ¦���϶� ���η� ¦�� ī��Ʈ�� ¦���϶� ��������
	2. ���� ī��Ʈ�� ��� ¦���϶� ��������, ���� ������ ���̰�.

	++���⸶�� �迭 �ε����� ������ �󸶳� �þ���� �����ؼ� ���?
	*/

	int count = 0; // ���� �ٲ�� Ƚ��
	int xcount = 0; //���� Ƚ��
	int ycount = 0; //���� Ƚ��
	int x = 0, y = 0;
	int num = 1; //������ ����

	while (num < 26)
	{
		switch (count) // ���� : y�� Ŀ���ų� �۾���
		{
		case 0:
			if (ycount % 2 == 0) // ���� ������
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
			else if (ycount % 2 == 1)//���� ������
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
			
		case 1: // ���� : x�� Ŀ���ų� �۾���
			if (xcount % 2 == 0) // ���� ������
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
			else if (xcount % 2 == 1)//���� ������
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