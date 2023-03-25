#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define trump_num 52

struct Card
{
	char shape[3];
	int num;
};

Card trump[trump_num];

void Swap(int num1, int num2)
{
	Card temp = trump[num1];
	trump[num1] = trump[num2];
	trump[num2] = temp;
}

void shuffle(int n)//n�� ����
{
	for (int i = 0; i < n; i++)
	{
		int num1 = rand() % 52;
		int num2 = rand() % 52;

		Swap(num1, num2);
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	printf("***���̷ο켼�� ���� ����!***\n");
	int money = 10000;
	while (true)
	{
		if (money <= 0)
			break;
			
		for (int i = 0; i < 52; i++) //Ʈ���� ī�� �ʱ�ȭ
		{
			if (i / 13 == 0)
				trump[i] = { "��", i % 13 + 1 };
			else if (i / 13 == 1)
				trump[i] = { "��", i % 13 + 1 };
			else if (i / 13 == 2)
				trump[i] = { "��", i % 13 + 1 };
			else if (i / 13 == 3)
				trump[i] = { "��", i % 13 + 1 };
		}

		shuffle(1000);

		int bettingMoney;
		int count = 0;


		while (true)
		{
			if (count > 46)
				break;
			else if (money <= 0)
			{
				printf("�� �̻� �����Ͻ� �� �ִ� �ݾ��� �����ϴ�. ������ �����մϴ�.\n");
				break;
			}

			printf("���� ���� ī�� 6�� �� 5�� ī�带 ���� ���� ī�带 ������ ������.\n => ");
			Card pickCard[6];//���� ī�� 6��
			int pickCardIndex;

			for (int i = 0; i < 6; i++) //�����ϰ� ī�� �̱�(�ߺ� ���ֱ�)
			{
				pickCardIndex = rand() % 52;
				if (trump[pickCardIndex].num != 0)
				{
					pickCard[i] = trump[pickCardIndex];
					trump[pickCardIndex].num = 0;
					count++;

					if (pickCard[i].num >= 11 && i < 5)
					{
						switch (pickCard[i].num)
						{
						case 11:
							pickCard[i].num = (char)74;
							break;
						case 12:
							pickCard[i].num = (char)81;
							break;
						case 13:
							pickCard[i].num = (char)75;
							break;
						default:
							break;
						}
						printf("%s %c  ", pickCard[i].shape, pickCard[i].num);
					}
					else if (pickCard[i].num < 11 && i < 5)
						printf("%s %d  ", pickCard[i].shape, pickCard[i].num);
				}
				else
					i--;
			}
			
			printf("\n�����Ͻ� �ݾ��� �Է��ϼ���. (���� ���� �ݾ� : %d) => ", money); //�����ϱ�
			while (true)
			{
				scanf_s("%d", &bettingMoney);
				if (money < bettingMoney)
				{
					printf("�����ϰ� �ִ� �ݾ׺��� ���� ���� �����Ͻ� �� �����ϴ�. �ٽ� �Է��� �ּ���.\n");
				}
				else
					break;
			}

			printf("\n[1. ����(8 ~ K)   2. �ο�(A ~ 6), 3. ����] => "); //���� �����ϱ�
			while (true)
			{
				int answer;
				scanf_s("%d", &answer);
				if (answer > 0 && answer < 4)
				{
					if (pickCard[5].num > 7 && answer == 1)
					{
						printf("���� ī�� : %s %d, �����Դϴ�!\n", pickCard[5].shape, pickCard[5].num);
						money += bettingMoney;
					}
					else if (pickCard[5].num < 7 && answer == 2)
					{
						printf("���� ī�� : %s %d, �����Դϴ�!\n", pickCard[5].shape, pickCard[5].num);
						money += bettingMoney;
					}
					else if (pickCard[5].num == 7 && answer == 3)
					{
						printf("���� ī�� : %s %d, �����Դϴ�!\n", pickCard[5].shape, pickCard[5].num);
						money += bettingMoney * 13;
					}
					else
					{
						printf("���� ī�� : %s %d, Ʋ�Ƚ��ϴ�!\n", pickCard[5].shape, pickCard[5].num);
						money -= bettingMoney;
					}
					printf("���� ���� �ݾ� : %d\n\n", money);
					break;
				}
				else
					printf("�߸� �Է��Ͽ����ϴ�. �ٽ� �Է��� �ּ���.\n");
			}



		}
	}

	return 0;
}

