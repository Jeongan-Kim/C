#include <stdio.h>

int main()
{
	// N ���� �ﰢ���� ���ﰢ���� ����Ѵ�. ��, ����ڷ� ���� ������ N�� �Է� �޴´�. �Ʒ��� N = 3 �� ���� ��� ���� �̴�.
// * *** *****
// ***** *** *
	int line = 0;
	printf("���� �ﰢ���� ���ﰢ���� �� �ٷ� �ϰ� �ͽ��ϱ�? : ");
	scanf_s("%d", &line);

	printf("<�ﰢ�� ���>\n");
	for (int i = 0; i < line; i++)
	{
		for(int j = 1; j <= 2 * i + 1; j++)
			printf("*");
		printf("\n");
	}

	printf("\n");

	printf("<���ﰢ�� ���>\n");
	for (int i = 0; i < line; i++)
	{
		for (int j = 1; j <= (line * 2 - 1) - i * 2; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}