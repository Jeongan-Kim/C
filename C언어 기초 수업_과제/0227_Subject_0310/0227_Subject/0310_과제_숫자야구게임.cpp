#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Scanf(int arr[], int arrSize);

int main()
{
	int baseballNum[3] = { 0 };
	int myNum[3] = { 0 };
	int failCount = 0;
	int strike;
	int ball;


	srand((unsigned int)time(NULL));
	for (int i = 0; i < 3; i++)
	{
		baseballNum[i] = rand() % 9 + 1;
		for (int j = 0; j < i; j++)
		{
			if (baseballNum[i] == baseballNum[j])
				i--;
		}
	}

	printf("*** ���� �߱� ������ �����մϴ� ***\n");
	
	while (failCount < 10)
	{
		printf("������ �� 3���� �Է��� �ּ���. 10�� �õ� �ȿ� ������ �� �ϸ� ���ϴ�.\n �Է� : ");
		//scanf_s("%d %d %d", &myNum[0], &myNum[1], &myNum[2]);
	
		Scanf(myNum, sizeof(myNum) / sizeof(int));
		printf("���� ������ �� : %d %d %d\n", myNum[0], myNum[1], myNum[2]);

		strike = 0;
		ball = 0;

		for (int i = 0; i < 3; i++)
		{

			for (int j = 0; j < 3; j++)
			{
				if (myNum[i] == baseballNum[j])
				{
					if (i == j)
						strike++;
					else if(i != j)
						ball++;
				}
			}

		}
		if (strike == 3)
		{
			printf("�����Դϴ�! �����մϴ�.\n");
			break;
		}
		else if (strike < 3)
			failCount++;

		printf("��� : %d strike\t%d ball\t\t �õ� Ƚ�� : %d\n\n", strike, ball, failCount);
	}

	if (failCount == 10)
		printf("10�� ���� ���� ������ �� �߽��ϴ�. �ٽ� ������ ������.");
	return 0;
}

void Scanf(int arr[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		scanf_s("%d", &arr[i]);
		if (arr[i] > 10 || arr[i] < 0)
		{
			printf("1~9�� ���� �Է��� �ּ���.\n");
			i--;
		}
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j])
			{
				printf("���� �ٸ� ���� �Է��� �ּ���.\n");
				i--;
			}
		}
	}
}
