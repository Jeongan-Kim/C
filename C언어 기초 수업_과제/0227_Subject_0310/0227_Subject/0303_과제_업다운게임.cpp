#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	int my_selct_num;
	srand((unsigned int)time(NULL));
	int question_num = rand() % 100 + 1;
	
	printf("***Up&Down ������ �����մϴ�. 10�� ���� ���ڸ� ���� ������!***\n �� ���� 1�� 100 ������ �����Դϴ�.");
	int i = 0;
	for (; i < 10; i++)
	{
		printf("������ ���ڸ� ���ϼ���. : ");
		scanf_s("%d", &my_selct_num);

		if (my_selct_num > question_num)
			printf("DOWN!!\n");
		else if (my_selct_num < question_num)
			printf("UP!!\n");
		else if (my_selct_num == question_num)
		{
			printf("�����Դϴ�!\n");
			break;
		}
		else
			printf("�߸� �Է��Ͽ����ϴ�. 1�� 100 ������ ���ڸ� ������ �ּ���.");
	}

	if (i >= 10)
		printf("10�� ���� ������ ������ �� �߽��ϴ�. ����!\n");

	return 0;
}