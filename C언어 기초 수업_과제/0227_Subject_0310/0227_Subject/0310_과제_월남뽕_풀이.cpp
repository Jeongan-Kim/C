#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int money = 50000;
	int betting = 0;
	int card[52];
	int cardcount = 0;

	for (int i = 0; i < 52; i++)
	{
		card[i] = i % 13 + 1;//1 2 3 ... 13 1 2 3 ... 13    ù���� ���

		//card[i] = i / 4 + 1; 1111 2222 3333 ....13131313   �ι�° ���
	}

	//for (int i = 0; i < 4; i++)							����° ���
	//{
	//	for (int j = 0; j < 13; i++)
	//	{
	//		card[i * 13 + j] = j + 1;
	//	}
	//}

	for (int i = 0; i < 1000; i++)  //ī�� �����ֱ�
	{
		int sour = rand() % 52;
		int dest = rand() % 52;

		int temp = card[sour];
		card[sour] = card[dest];
		card[dest] = temp;
	}


	while (1)
	{
		if (card[cardcount + 0] > card[cardcount + 1])
		{
			int temp = card[cardcount + 0];
			card[cardcount + 0] = card[cardcount + 1];
			card[cardcount + 1] = temp;
		}

		printf("%d, %d, ?\n", card[cardcount + 0], card[cardcount + 1]);

		printf("�� ������ : %d\n", money);
		printf("���� �ݾ� : ");
		scanf_s("%d", &betting);

		if (betting < 1000 || betting > money)
		{
			printf("���� �ݾ��� Ȯ���� �ּ���!!\n\n");
			continue;
		}

		if (card[cardcount + 0] < card[cardcount + 2] &&
			card[cardcount + 2] < card[cardcount + 1])
		{
			printf("�¸�!!\n");
			printf("���� ī�� : %d\n", card[cardcount + 2]);
			money += betting;
		}
		else
		{
			printf("�й�!!\n");
			printf("���� ī�� : %d\n", card[cardcount + 2]);
			money -= betting;
		}
		cardcount += 3;

		if (cardcount > 49 || money < 1000)
		{
			printf("���� ����");
			break;
		}
	}

	return 0;
}