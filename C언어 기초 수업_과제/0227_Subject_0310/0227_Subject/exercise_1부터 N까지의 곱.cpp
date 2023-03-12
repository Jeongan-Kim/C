#include <stdio.h>

// 사용자로 부터 N값을 입력 받고 1 부터 N까지의 곱을 출력한다.
int main()
{
	int user_num;
	int answer = 1;
	printf("몇 까지의 곱을 구할까요? : ");
	scanf_s("%d", &user_num);

	for (int i = 1;i <= user_num ; i++)
	{
		answer = answer * i; //answer *= i
	}
	printf("1부터 %d까지의 곱 : %d", user_num, answer);
	return 0;
}