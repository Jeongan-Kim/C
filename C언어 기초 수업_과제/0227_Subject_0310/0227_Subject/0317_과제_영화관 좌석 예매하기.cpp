#include <stdio.h>

/*
��ȭ�� �ڸ� �����ϴ� ���α׷�(�ڸ� ���Ž� A���� �¼� ��ȣ �Է�)
�����ϸ� �� �¼��� xǥ�� �ǰ�,
���� �ڸ��� �����ϸ� ���� �Ϸ�Ǿ��ٴ� �޼����� �ߴ� ��.
*/

int main()
{
	printf("���ϴ� �¼��� ��� �ּ���.\n");

	int seat[8][13];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			seat[i][j] = j + 1;
		}
	}

	while (true)
	{
		for (int i = 0; i < 8; i++)
		{
			printf("%c�� ", i + 65);
			for (int j = 0; j < 13; j++)
			{
				if (seat[i][j] == 0)
					printf("x ");
				else
					printf("%d ", seat[i][j]);
			}
			printf("\n");
		}

		char mySelect1 = 0;
		int mySelect2 = 0;
		int answer;

		while (true)
		{
			scanf_s(" %c", &mySelect1, sizeof(mySelect1)); //�� ĭ ����� �ʰ� getchar�Լ��� ���� �� ������ ������?
			scanf_s("%d", &mySelect2);
				

			if (seat[(int)mySelect1 - 65][mySelect2 - 1] != 0)
			{
				printf("�����Ͻ� �¼��� %c�� %d��° �¼��Դϴ�. ����Ǿ����ϴ�.\n", mySelect1, mySelect2);
				seat[(int)mySelect1 - 65][mySelect2 - 1] = 0;
				break;
			}
			else if (seat[(int)mySelect1 - 65][mySelect2 - 1] == 0)
			{
				printf("�̹� ���ŵ� �¼��Դϴ�. �ٸ� �¼����� ������ �ּ���.\n");
			}
		}

		printf("�߰� ���Ÿ� �����Ͻðڽ��ϱ�? [1. ��  2.�ƴϿ�] => ");
		scanf_s("%d", &answer);
		printf("\n");
		switch (answer)
		{
		case 1:
			printf("���ϴ� �¼��� ��� �ּ���.\n");
			break;
		case 2:
			printf("�����մϴ�.\n");
			return 0;
		}
	}


	return 0;
}
