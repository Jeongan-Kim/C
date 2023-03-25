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

void shuffle(int n)//n번 섞기
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
	printf("***하이로우세븐 게임 시작!***\n");
	int money = 10000;
	while (true)
	{
		if (money <= 0)
			break;
			
		for (int i = 0; i < 52; i++) //트럼프 카드 초기화
		{
			if (i / 13 == 0)
				trump[i] = { "◆", i % 13 + 1 };
			else if (i / 13 == 1)
				trump[i] = { "♥", i % 13 + 1 };
			else if (i / 13 == 2)
				trump[i] = { "♠", i % 13 + 1 };
			else if (i / 13 == 3)
				trump[i] = { "♣", i % 13 + 1 };
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
				printf("더 이상 배팅하실 수 있는 금액이 없습니다. 게임을 종료합니다.\n");
				break;
			}

			printf("다음 뽑힌 카드 6장 중 5장 카드를 보고 히든 카드를 예상해 보세요.\n => ");
			Card pickCard[6];//뽑은 카드 6장
			int pickCardIndex;

			for (int i = 0; i < 6; i++) //랜덤하게 카드 뽑기(중복 없애기)
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
			
			printf("\n배팅하실 금액을 입력하세요. (현재 가진 금액 : %d) => ", money); //배팅하기
			while (true)
			{
				scanf_s("%d", &bettingMoney);
				if (money < bettingMoney)
				{
					printf("소지하고 있는 금액보다 많은 돈을 배팅하실 수 없습니다. 다시 입력해 주세요.\n");
				}
				else
					break;
			}

			printf("\n[1. 하이(8 ~ K)   2. 로우(A ~ 6), 3. 세븐] => "); //정답 예측하기
			while (true)
			{
				int answer;
				scanf_s("%d", &answer);
				if (answer > 0 && answer < 4)
				{
					if (pickCard[5].num > 7 && answer == 1)
					{
						printf("히든 카드 : %s %d, 정답입니다!\n", pickCard[5].shape, pickCard[5].num);
						money += bettingMoney;
					}
					else if (pickCard[5].num < 7 && answer == 2)
					{
						printf("히든 카드 : %s %d, 정답입니다!\n", pickCard[5].shape, pickCard[5].num);
						money += bettingMoney;
					}
					else if (pickCard[5].num == 7 && answer == 3)
					{
						printf("히든 카드 : %s %d, 정답입니다!\n", pickCard[5].shape, pickCard[5].num);
						money += bettingMoney * 13;
					}
					else
					{
						printf("히든 카드 : %s %d, 틀렸습니다!\n", pickCard[5].shape, pickCard[5].num);
						money -= bettingMoney;
					}
					printf("현재 소지 금액 : %d\n\n", money);
					break;
				}
				else
					printf("잘못 입력하였습니다. 다시 입력해 주세요.\n");
			}



		}
	}

	return 0;
}

