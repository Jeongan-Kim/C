#include <stdio.h>

/*
영화관 자리 예매하는 프로그램(자리 예매시 A열의 좌석 번호 입력)
예매하면 그 좌석이 x표시 되고,
같은 자리를 예매하면 예매 완료되었다는 메세지가 뜨는 것.
*/

int main()
{
	printf("원하는 좌석을 골라 주세요.\n");

	int seat[8][13];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			seat[i][j] = j + 1;
		}
	}

	while (true)
	{
		for (int i = 0; i < 8; i++)
		{
			printf("%c열 ", i + 65);
			for (int j = 0; j < 13; j++)
			{
				if (seat[i][j] == 0)
					printf("x ");
				else
					printf("%d ", seat[i][j]);
			}
			printf("\n");
		}

		char mySelect1 = 0;
		int mySelect2 = 0;
		int answer;

		while (true)
		{
			scanf_s(" %c", &mySelect1, sizeof(mySelect1)); //한 칸 띄우지 않고 getchar함수를 쓰면 왜 오류가 나는지?
			scanf_s("%d", &mySelect2);
				

			if (seat[(int)mySelect1 - 65][mySelect2 - 1] != 0)
			{
				printf("선택하신 좌석은 %c열 %d번째 좌석입니다. 예약되었습니다.\n", mySelect1, mySelect2);
				seat[(int)mySelect1 - 65][mySelect2 - 1] = 0;
				break;
			}
			else if (seat[(int)mySelect1 - 65][mySelect2 - 1] == 0)
			{
				printf("이미 예매된 좌석입니다. 다른 좌석으로 예매해 주세요.\n");
			}
		}

		printf("추가 예매를 진행하시겠습니까? [1. 네  2.아니오] => ");
		scanf_s("%d", &answer);
		printf("\n");
		switch (answer)
		{
		case 1:
			printf("원하는 좌석을 골라 주세요.\n");
			break;
		case 2:
			printf("종료합니다.\n");
			return 0;
		}
	}


	return 0;
}
