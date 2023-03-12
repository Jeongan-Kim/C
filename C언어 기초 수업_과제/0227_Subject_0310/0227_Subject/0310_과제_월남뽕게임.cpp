#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void arrSort(int arr[3]);

int main()
{
	int trumpPick[3];
	int trumpNum = 52;
	int money = 50000;
	int mySelect;
	int myPay;

	printf("*** 월남뽕 게임을 시작합니다! ***\n");

	int trump[4][13] = { 0 };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			trump[i][j] = j + 1;
		}
	}

	srand((unsigned int)time(NULL));

	
	while (true)
	{

		if (trumpNum < 3)
			false;
		else if (money < 1000)
			false;
		else
			true;

		

		for (int i = 0; i < 3; i++)
		{
			int shape = rand() % 3;
			int number = rand() % 13;

			if (trump[shape][number] == 0)
			{
				i--;
				continue;
			}
			else
				trumpPick[i] = trump[shape][number];

			for (int j = 0; j < i; j++)
			{
				if (trumpPick[i] == trumpPick[j])
					i--;
				else if (abs(trumpPick[i] - trumpPick[j]) < 2)
					i--;
			}
			trumpNum -= 3;
			trump[shape][number] == 0;
		}

		printf("주어진 수 : %d %d '?'\n", trumpPick[0], trumpPick[1]);
		arrSort(trumpPick);

		printf("물음표에 들어갈 수는 어떤 수 일까요? [ (1) %d와 %d 사이의 수  (2) %d보다 작거나 %d보다 큰 수 ]\n", trumpPick[0], trumpPick[1], trumpPick[0], trumpPick[1]);

		while (true)
		{
			scanf_s("%d", &mySelect);
			if (mySelect < 3 && mySelect > 0)
				break;
			else
				printf("잘못 입력하셨습니다.\n");
		}

		printf("배팅할 금액을 입력하세요.(1000원 이상)  현재 남은 금액 : %d \n입력 : ", money);
		while (true)
		{
			scanf_s("%d", &myPay);
			if (myPay < 1000)
			{
				printf("1000원 이상 배팅하셔야 합니다. 다시 입력해 주세요.\n");
			}
			else if (myPay > money)
			{
				printf("가진 금액보다 큰 금액을 배팅하셨습니다. 다시 입력해 주세요.\n");
			}
			else
				break;
		}

		printf("%d를 배팅하셨습니다. 배팅 후 남은 금액 : %d\n\n", myPay, money - myPay);

		if (trumpPick[0] < trumpPick[2] && trumpPick[2] < trumpPick[1])
		{
			if (mySelect == 1)
			{
				money += myPay;
				printf("정답입니다! 배팅한 금액을 돌려 드립니다. 현재 남은 금액 : %d\n\n", money);
			}
			else
			{
				money -= myPay;
				printf("틀렸습니다! 배팅한 금액을 잃었습니다. 현재 남은 금액 : %d\n\n", money);
			}
		}
		else if (trumpPick[1] < trumpPick[2] || trumpPick[2] < trumpPick[0])
		{
			if (mySelect == 2)
			{
				money += myPay;
				printf("정답입니다! 배팅한 금액을 돌려 드립니다. 현재 남은 금액 : %d\n\n", money);
			}
			else
			{
				money -= myPay;
				printf("틀렸습니다! 배팅한 금액을 잃었습니다. 현재 남은 금액 : %d\n\n", money);
			}
		}


		if (money < 1000)
		{
			printf("가진 금액이 1000원 미만이므로 더 이상 게임에 참가하실 수 없습니다.\n");
			break;
		}
		else if (trumpNum < 3)
		{
			printf("더 이상 게임을 진행할 카드가 없습니다.\n");
			break;
		}

	}
	return 0;
}



void arrSort(int arr[3])
{
	if (arr[0] > arr[1])
	{
		int temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}
}
