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

	char shape[4][3] = { "��", "��", "��", "��" }; //������+��ħǥ => �̸�Ƽ��

	for (int i = 0; i < 52; i++)
	{
		switch (i / 13)
		{
		case DIA:
			//deck[i].shape = "��"; �̰� �ȵ�. ������ ����� �־���� �ϴµ�, ���ڸ� �ִ´ٴ� �� ��ü�� �Ұ����� ����̹Ƿ� strcpy�� �̿��ؼ� �ּҷ� ���� ������ ������ �־�� ��.
			strcpy(deck[i].shape, shape[0]); break; //�����ؼ� �־��ִ� ��. (?)
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
	
	printf("���� �ο� ����!!!\n\n");

	while (1)
	{
		printf("���� ������ : %d\n\n", money);

		for (int i = 0; i < 5; i++)
		{
			CardPrint(cardcount + i);
		}
		printf("?\n");

		printf("���þ� : ");
		scanf_s("%d", &betting);

		if (betting < 5000 || betting > money)
		{
			printf("�ݾ��� Ȯ���� �ּ���\n\n");
			continue;
		}

		printf("���� : 0, �ο� : 1, ���� 2\n");
		scanf_s("%d", &input);

		if (input < 0 || input > 2)
		{
			printf("�ٽ� ������ �ּ���\n\n");
			continue;
		}

		if (input == 0)
		{
			if (deck[cardcount + 5].number > 7)
			{
				printf("�¸�!!!\n");
				money += betting;
			}
			else
			{
				printf("�й�!!!\n");
				money -= betting;
			}
		}

		else if (input == 1)
		{
			if (deck[cardcount + 5].number < 7)
			{
				printf("�¸�!!!\n");
				money += betting;
			}
			else
			{
				printf("�й�!!!\n");
				money -= betting;
			}
		}

		else 
		{
			if (deck[cardcount + 5].number == 7)
			{
				printf("�¸�!!!\n");
				money += betting * 13;
			}
			else
			{
				printf("�й�!!!\n");
				money -= betting;
			}
		}

		printf("���� ī�� : ");
		CardPrint(cardcount + 5);
		printf("\n\n");

		cardcount += 6;

		if (money < 5000)
		{
			printf("���� ����!!\n");
			exit(1);
		}

		if (cardcount > 47)
		{
			printf("ī�� ����\n");
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
