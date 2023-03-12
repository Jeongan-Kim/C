#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	int my_selct_num;
	srand((unsigned int)time(NULL));
	int question_num = rand() % 100 + 1;
	
	printf("***Up&Down 게임을 시작합니다. 10번 내로 숫자를 맞혀 보세요!***\n 이 수는 1과 100 사이의 숫자입니다.");
	int i = 0;
	for (; i < 10; i++)
	{
		printf("예상한 숫자를 말하세요. : ");
		scanf_s("%d", &my_selct_num);

		if (my_selct_num > question_num)
			printf("DOWN!!\n");
		else if (my_selct_num < question_num)
			printf("UP!!\n");
		else if (my_selct_num == question_num)
		{
			printf("정답입니다!\n");
			break;
		}
		else
			printf("잘못 입력하였습니다. 1과 100 사이의 숫자를 예상해 주세요.");
	}

	if (i >= 10)
		printf("10번 동안 정답을 맞히지 못 했습니다. 실패!\n");

	return 0;
}