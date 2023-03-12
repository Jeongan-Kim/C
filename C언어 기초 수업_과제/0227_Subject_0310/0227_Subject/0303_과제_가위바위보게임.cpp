#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int my_Attack = 0;

	while (true)
	{

		srand((unsigned int)time(NULL));
		int computer_Attack = rand() % 3 + 1;

		printf("선택하세요. [1. 가위, 2. 바위, 3. 보] => ");
		scanf_s("%d", &my_Attack);

		if (my_Attack == 1)
			printf("나의 공격 : 가위\n");
		else if (my_Attack == 2)
			printf("나의 공격 : 바위\n");
		else if (my_Attack == 3)
			printf("나의 공격 : 보\n");
		else
		{
			printf("잘못 입력하였습니다.\n");
			break;
		}

		if (computer_Attack == 1)
			printf("컴퓨터의 공격 : 가위\n");
		else if (computer_Attack == 2)
			printf("컴퓨터의 공격 : 바위\n");
		else if (computer_Attack == 3)
			printf("컴퓨터의 공격 : 보\n");


		if (my_Attack == computer_Attack)
			printf("비겼습니다.\n");
		else if ((my_Attack == 1 && computer_Attack == 3) || (my_Attack == 2 && computer_Attack == 1) || (my_Attack == 3 && computer_Attack == 2))
			printf("이겼습니다.\n");
		else
			printf("졌습니다.\n");

	}
	


	return 0;
}