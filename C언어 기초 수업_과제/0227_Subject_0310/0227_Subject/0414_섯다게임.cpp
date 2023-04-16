#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <string.h>

struct firstCard
{
	int month;
	char word[3] = { 0 };
};



struct secondCard
{
	int month;
	char word[3] = { 0 };
};

struct player
{
	char name[256];
	int money = 10000;

	firstCard firstcard;
	secondCard secondcard;

	bool iswinner = false;
	char result[256];
	int resultn;
	int resultNum;
};

struct player list[100];
int playerNum;

void PlayerNum()
{
	printf("�÷��̾� �� : ");
	scanf_s("%d", &playerNum);
	printf("\n");
}

void playerInfo()
{
	for (int i = 0; i < playerNum; i++)
	{
		printf("%d��° �÷��̾� �̸� : ", i + 1);
		char temp[100] = { 0 };
		scanf_s("%s", temp, sizeof(temp));
		strcpy(list[i].name, temp);
	}
}

char light[3] = "��";
char month[3] = "��";

void cardDistribution()
{
	for (int i = 0; i < playerNum; i++)
	{
		list[i].firstcard.month = rand() % 10 + 1;
		if (list[i].firstcard.month == 1 || list[i].firstcard.month == 3 || list[i].firstcard.month == 8)
		{
			int temp = rand() % 2;
			if (temp == 0)
				strcpy(list[i].firstcard.word, light);
			else if (temp == 1)
				strcpy(list[i].firstcard.word, month);
		}
		else
			strcpy(list[i].firstcard.word, month);

		list[i].secondcard.month = rand() % 10 + 1;
		if (list[i].firstcard.month == list[i].secondcard.month)
		{
			if (list[i].secondcard.month == 1 || list[i].secondcard.month == 3 || list[i].secondcard.month == 8)
			{
				if (list[i].firstcard.word == "��")
				{
					strcpy(list[i].secondcard.word, month);
				}
				else
					strcpy(list[i].secondcard.word, light);
			}
			else
				strcpy(list[i].secondcard.word, month);
		}
		else
			strcpy(list[i].secondcard.word, month);
	}
}

void result()
{
	for (int i = 0; i < playerNum; i++)
	{
		list[i].resultn = 0;
		if ((list[i].firstcard.month == 3 && list[i].secondcard.month == 8 && list[i].firstcard.word == "��" && list[i].secondcard.word == "��")
			|| (list[i].firstcard.month == 8 && list[i].secondcard.month == 3 && list[i].firstcard.word == "��" && list[i].secondcard.word == "��"))
		{
			char temp[100] = "���ȱ���";
			strcpy(list[i].result, temp);
			list[i].resultNum = 100;
			continue;
		}
		if((list[i].firstcard.month == 1 && list[i].secondcard.month == 3 && list[i].firstcard.word == "��" && list[i].secondcard.word == "��")
			|| (list[i].firstcard.month == 3 && list[i].secondcard.month == 8 && list[i].firstcard.word == "��" && list[i].secondcard.word == "��"))
		{
			char temp[100] = "����";
			strcpy(list[i].result, temp);
			list[i].resultNum = 91;
			continue;
		}
		if (list[i].firstcard.month == list[i].secondcard.month)
		{
			char temp[100] = "��";
			list[i].resultn = list[i].firstcard.month;
			strcpy(list[i].result, temp);
			list[i].resultNum = 80 + list[i].firstcard.month; //81~90
			continue;
		}
		if ((list[i].firstcard.month == 1 && list[i].secondcard.month == 2) || (list[i].firstcard.month == 2 && list[i].secondcard.month == 1))
		{
			char temp[100] = "�˸�";
			strcpy(list[i].result, temp);
			list[i].resultNum = 80;
			continue;
		}
		if ((list[i].firstcard.month == 1 && list[i].secondcard.month == 4) || (list[i].firstcard.month == 4 && list[i].secondcard.month == 1))
		{
			char temp[100] = "����";
			strcpy(list[i].result, temp);
			list[i].resultNum = 70;
			continue;
		}
		if ((list[i].firstcard.month == 1 && list[i].secondcard.month == 9) || (list[i].firstcard.month == 9 && list[i].secondcard.month == 1))
		{
			char temp[100] = "����";
			strcpy(list[i].result, temp);
			list[i].resultNum = 60;
			continue;
		}
		if ((list[i].firstcard.month == 1 && list[i].secondcard.month == 10) || (list[i].firstcard.month == 10 && list[i].secondcard.month == 1))
		{
			char temp[100] = "���";
			strcpy(list[i].result, temp);
			list[i].resultNum = 50;
			continue;
		}
		if ((list[i].firstcard.month == 4 && list[i].secondcard.month == 10) || (list[i].firstcard.month == 10 && list[i].secondcard.month == 4))
		{
			char temp[100] = "���";
			strcpy(list[i].result, temp);
			list[i].resultNum = 40;
			continue;
		}
		if ((list[i].firstcard.month == 4 && list[i].secondcard.month == 6) || (list[i].firstcard.month == 6 && list[i].secondcard.month == 4))
		{
			char temp[100] = "����";
			strcpy(list[i].result, temp);
			list[i].resultNum = 30;
			continue;
		}
		if ((list[i].firstcard.month + list[i].secondcard.month) % 10 == 9)
		{
			char temp[100] = "����";
			strcpy(list[i].result, temp);
			list[i].resultNum = 20;
			continue;
		}
		if ((list[i].firstcard.month + list[i].secondcard.month) % 10 < 9)
		{
			if ((list[i].firstcard.month == 2 && list[i].secondcard.month == 8) || (list[i].firstcard.month == 8 && list[i].secondcard.month == 2))
			{
				char temp[100] = "����";
				strcpy(list[i].result, temp);
				list[i].resultNum = 0;
				continue;
			}
			else if ((list[i].firstcard.month == 3 && list[i].secondcard.month == 7) || (list[i].firstcard.month == 7 && list[i].secondcard.month == 3))
			{
				char temp[100] = "����";
				strcpy(list[i].result, temp);
				list[i].resultNum = 0;
				continue;
			}
			char temp[100] = "��";
			list[i].resultn = (list[i].firstcard.month + list[i].secondcard.month) % 10;
			strcpy(list[i].result, temp);
			list[i].resultNum = 10 + list[i].resultn; //11~18
			continue;
		}
	}

	int max = 0;

	for (int i = 0; i < playerNum - 1; i++)
	{
		max = list[i].resultNum;
		for (int j = i + 1; j < playerNum; j++)
		{
			if (list[j].resultNum >= max)
			{
				max = list[j].resultNum;
			}
		}
	}

	for (int i = 0; i < playerNum; i++)
	{
		if (list[i].resultNum == max)
		{
			list[i].iswinner = true;
			list[i].money += 500;
		}
		else
		{
			list[i].iswinner = false;
			list[i].money -= 500;
		}
	}	
}

void resultPrint()
{
	system("cls");

	for (int i = 0; i < playerNum; i++)
	{
		if (list[i].iswinner == true)
			printf("%s  ", list[i].name);
	}
	printf("  �¸�!\n");

	for (int i = 0; i < playerNum; i++)
	{
		if (list[i].resultn != 0)
		{
			printf("%s	%d%s	%d%s	%d	%d%s\n",
				list[i].name,
				list[i].firstcard.month, list[i].firstcard.word,
				list[i].secondcard.month, list[i].secondcard.word,
				list[i].money, list[i].resultn, list[i].result);
		}
		else 
			printf("%s	%d%s	%d%s	%d	%s\n", 
			list[i].name,
			list[i].firstcard.month, list[i].firstcard.word,
			list[i].secondcard.month, list[i].secondcard.word,
			list[i].money, list[i].result);
	}
}

int continuecheck;

void continueCheck()
{
	printf("0. ���	1. ������ =>");
	scanf_s("%d", &continuecheck);
}

int nomoney()
{
	int exit = 1;
	for (int i = 0; i < playerNum; i++)
	{
		if (list[i].money == 0)
		{
			printf("%d��° ������ ������ ������ ���� �����ϴ�.\n", i + 1);
			exit = 0;
			continue;
		}
	}
	if (exit == 0)
		printf("������ �����մϴ�.\n");
	return exit;
}

int main()
{
	srand((unsigned int)time(NULL));
	PlayerNum();
	playerInfo();

	while (!(continuecheck))
	{
		cardDistribution();
		result();
		resultPrint();
		continueCheck();
		if (nomoney() == 0)
			break;
	}

	return 0;
}
