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

		printf("�����ϼ���. [1. ����, 2. ����, 3. ��] => ");
		scanf_s("%d", &my_Attack);

		if (my_Attack == 1)
			printf("���� ���� : ����\n");
		else if (my_Attack == 2)
			printf("���� ���� : ����\n");
		else if (my_Attack == 3)
			printf("���� ���� : ��\n");
		else
		{
			printf("�߸� �Է��Ͽ����ϴ�.\n");
			break;
		}

		if (computer_Attack == 1)
			printf("��ǻ���� ���� : ����\n");
		else if (computer_Attack == 2)
			printf("��ǻ���� ���� : ����\n");
		else if (computer_Attack == 3)
			printf("��ǻ���� ���� : ��\n");


		if (my_Attack == computer_Attack)
			printf("�����ϴ�.\n");
		else if ((my_Attack == 1 && computer_Attack == 3) || (my_Attack == 2 && computer_Attack == 1) || (my_Attack == 3 && computer_Attack == 2))
			printf("�̰���ϴ�.\n");
		else
			printf("�����ϴ�.\n");

	}
	


	return 0;
}