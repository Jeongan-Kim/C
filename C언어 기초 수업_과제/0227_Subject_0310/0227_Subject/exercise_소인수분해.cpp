#include <stdio.h>
// ������ �ڿ��� N �� �Է� �޾� N �� ���μ� ���� �� ����� ����Ͽ���. ���� ��  N = 18 �� ��� N = 18 = 2 * 3 * 3

int main()
{
	//int user_num;
	//printf("���μ� �����ϰ� ���� �ڿ����� �Է��ϼ���. : ");
	//scanf_s("%d", &user_num);
	//printf("N = %d = ", user_num);

	//for (int i = 2; i <= user_num; )
	//{
	//	if (user_num % i == 0)
	//	{
	//		if (i < user_num)
	//		{
	//			user_num = user_num / i;
	//			printf("%d * ", i);
	//		}
	//		else if (i == user_num)
	//		{
	//			user_num = user_num / i;
	//			printf("%d", i);
	//		}
	//	}
	//	else if (user_num % i != 0)
	//	{
	//		i++;
	//	}
	//}
	
	int user_num;
	printf("���μ� �����ϰ� ���� �ڿ����� �Է��ϼ���. : ");
	scanf_s("%d", &user_num);
	printf("N = %d = ", user_num);

	for (int i = 2; i <= user_num; )
	{
		if (user_num % i == 0)
		{
			user_num = user_num / i;
			printf("%d ", i);

			if (user_num > 1)
				printf("* ");
		}
		else if (user_num % i != 0)
		{
			i++;
		}
	}
	return 0;
}