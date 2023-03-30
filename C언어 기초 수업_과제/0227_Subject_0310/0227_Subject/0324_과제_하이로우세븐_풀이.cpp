#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



typedef struct
{
	int number;
	char shape[4];
}Trump;

enum CARDSHAPE
{
	DIA,
	HEART,
	SPADE,
	CLOVER
};

enum CARDNUM
{
	ACE = 1,
	JACK = 11,
	QUEEN,
	KING
};

Trump deck[52];

void Swap(int sour, int dest);
void Shuffle();
void CardPrint(int cardcount);

int main()
{
	srand((unsigned int)time(NULL));

	char shape[4][3] = { "◇", "♡", "♤", "♧" }; //윈도우+마침표 => 이모티콘

	for (int i = 0; i < 52; i++)
	{
		switch (i / 13)
		{
		case DIA:
			//deck[i].shape = "◇"; 이건 안됨. 변수에 상수를 넣어줘야 하는데, 문자를 넣는다는 것 자체가 불가능한 방법이므로 strcpy를 이용해서 주소로 들어가서 내용을 복사해 넣어야 함.
			strcpy(deck[i].shape, shape[0]); break; //복사해서 넣어주는 것. (?)
		case HEART:
			strcpy(deck[i].shape, shape[1]); break;
		case SPADE:
			strcpy(deck[i].shape, shape[2]); break;
		case CLOVER:
			strcpy(deck[i].shape, shape[3]); break;
		}

		deck[i].number = i % 13 + 1;
	}

	Shuffle();

	int money, input, betting, cardcount;
	money = 50000;
	cardcount = 0;
	
	printf("하이 로우 세븐!!!\n\n");

	while (1)
	{
		printf("현재 소지금 : %d\n\n", money);

		for (int i = 0; i < 5; i++)
		{
			CardPrint(cardcount + i);
		}
		printf("?\n");

		printf("베팅액 : ");
		scanf_s("%d", &betting);

		if (betting < 5000 || betting > money)
		{
			printf("금액을 확인해 주세요\n\n");
			continue;
		}

		printf("하이 : 0, 로우 : 1, 세븐 2\n");
		scanf_s("%d", &input);

		if (input < 0 || input > 2)
		{
			printf("다시 선택해 주세요\n\n");
			continue;
		}

		if (input == 0)
		{
			if (deck[cardcount + 5].number > 7)
			{
				printf("승리!!!\n");
				money += betting;
			}
			else
			{
				printf("패배!!!\n");
				money -= betting;
			}
		}

		else if (input == 1)
		{
			if (deck[cardcount + 5].number < 7)
			{
				printf("승리!!!\n");
				money += betting;
			}
			else
			{
				printf("패배!!!\n");
				money -= betting;
			}
		}

		else 
		{
			if (deck[cardcount + 5].number == 7)
			{
				printf("승리!!!\n");
				money += betting * 13;
			}
			else
			{
				printf("패배!!!\n");
				money -= betting;
			}
		}

		printf("히든 카드 : ");
		CardPrint(cardcount + 5);
		printf("\n\n");

		cardcount += 6;

		if (money < 5000)
		{
			printf("게임 종료!!\n");
			exit(1);
		}

		if (cardcount > 47)
		{
			printf("카드 셔플\n");
			cardcount = 0;
			Shuffle();
		}
	}

	return 0;
}

void Swap(int sour, int dest)
{
	Trump temp = deck[sour];
	deck[sour] = deck[dest];
	deck[dest] = temp;
}

void Shuffle()
{
	for (int i = 0; i < 1000; i++)
	{
		int sour = rand() % 52;
		int dest = rand() % 52;
		Swap(sour, dest);
	}
}

void CardPrint(int cardcount)
{
	switch (deck[cardcount].number)
	{
	case ACE:
		printf("%sA , ", deck[cardcount].shape); break;
	case JACK:
		printf("%sJ , ", deck[cardcount].shape); break;
	case QUEEN:
		printf("%sQ , ", deck[cardcount].shape); break;
	case KING:
		printf("%sK , ", deck[cardcount].shape); break;
	default:
		printf("%s%d, ", deck[cardcount].shape, deck[cardcount].number); break;
	}
}
