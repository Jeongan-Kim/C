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

	printf("*** ������ ������ �����մϴ�! ***\n");

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

		printf("�־��� �� : %d %d '?'\n", trumpPick[0], trumpPick[1]);
		arrSort(trumpPick);

		printf("����ǥ�� �� ���� � �� �ϱ��? [ (1) %d�� %d ������ ��  (2) %d���� �۰ų� %d���� ū �� ]\n", trumpPick[0], trumpPick[1], trumpPick[0], trumpPick[1]);

		while (true)
		{
			scanf_s("%d", &mySelect);
			if (mySelect < 3 && mySelect > 0)
				break;
			else
				printf("�߸� �Է��ϼ̽��ϴ�.\n");
		}

		printf("������ �ݾ��� �Է��ϼ���.(1000�� �̻�)  ���� ���� �ݾ� : %d \n�Է� : ", money);
		while (true)
		{
			scanf_s("%d", &myPay);
			if (myPay < 1000)
			{
				printf("1000�� �̻� �����ϼž� �մϴ�. �ٽ� �Է��� �ּ���.\n");
			}
			else if (myPay > money)
			{
				printf("���� �ݾ׺��� ū �ݾ��� �����ϼ̽��ϴ�. �ٽ� �Է��� �ּ���.\n");
			}
			else
				break;
		}

		printf("%d�� �����ϼ̽��ϴ�. ���� �� ���� �ݾ� : %d\n\n", myPay, money - myPay);

		if (trumpPick[0] < trumpPick[2] && trumpPick[2] < trumpPick[1])
		{
			if (mySelect == 1)
			{
				money += myPay;
				printf("�����Դϴ�! ������ �ݾ��� ���� �帳�ϴ�. ���� ���� �ݾ� : %d\n\n", money);
			}
			else
			{
				money -= myPay;
				printf("Ʋ�Ƚ��ϴ�! ������ �ݾ��� �Ҿ����ϴ�. ���� ���� �ݾ� : %d\n\n", money);
			}
		}
		else if (trumpPick[1] < trumpPick[2] || trumpPick[2] < trumpPick[0])
		{
			if (mySelect == 2)
			{
				money += myPay;
				printf("�����Դϴ�! ������ �ݾ��� ���� �帳�ϴ�. ���� ���� �ݾ� : %d\n\n", money);
			}
			else
			{
				money -= myPay;
				printf("Ʋ�Ƚ��ϴ�! ������ �ݾ��� �Ҿ����ϴ�. ���� ���� �ݾ� : %d\n\n", money);
			}
		}


		if (money < 1000)
		{
			printf("���� �ݾ��� 1000�� �̸��̹Ƿ� �� �̻� ���ӿ� �����Ͻ� �� �����ϴ�.\n");
			break;
		}
		else if (trumpNum < 3)
		{
			printf("�� �̻� ������ ������ ī�尡 �����ϴ�.\n");
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
