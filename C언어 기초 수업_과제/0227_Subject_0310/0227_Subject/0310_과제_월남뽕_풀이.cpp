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
		card[i] = i % 13 + 1;//1 2 3 ... 13 1 2 3 ... 13    첫번쨰 방법

		//card[i] = i / 4 + 1; 1111 2222 3333 ....13131313   두번째 방법
	}

	//for (int i = 0; i < 4; i++)							세번째 방법
	//{
	//	for (int j = 0; j < 13; i++)
	//	{
	//		card[i * 13 + j] = j + 1;
	//	}
	//}

	for (int i = 0; i < 1000; i++)  //카드 섞어주기
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

		printf("내 소지금 : %d\n", money);
		printf("배팅 금액 : ");
		scanf_s("%d", &betting);

		if (betting < 1000 || betting > money)
		{
			printf("배팅 금액을 확인해 주세요!!\n\n");
			continue;
		}

		if (card[cardcount + 0] < card[cardcount + 2] &&
			card[cardcount + 2] < card[cardcount + 1])
		{
			printf("승리!!\n");
			printf("히든 카드 : %d\n", card[cardcount + 2]);
			money += betting;
		}
		else
		{
			printf("패배!!\n");
			printf("히든 카드 : %d\n", card[cardcount + 2]);
			money -= betting;
		}
		cardcount += 3;

		if (cardcount > 49 || money < 1000)
		{
			printf("게임 종료");
			break;
		}
	}

	return 0;
}