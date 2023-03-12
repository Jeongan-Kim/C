#include <stdio.h>
// 임의의 자연수 N 을 입력 받아 N 을 소인수 분해 한 결과를 출력하여라. 예를 들어서  N = 18 일 경우 N = 18 = 2 * 3 * 3

int main()
{
	//int user_num;
	//printf("소인수 분해하고 싶은 자연수를 입력하세요. : ");
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
	printf("소인수 분해하고 싶은 자연수를 입력하세요. : ");
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