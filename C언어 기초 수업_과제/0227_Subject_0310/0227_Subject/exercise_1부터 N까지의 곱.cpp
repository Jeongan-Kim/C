#include <stdio.h>

// ����ڷ� ���� N���� �Է� �ް� 1 ���� N������ ���� ����Ѵ�.
int main()
{
	int user_num;
	int answer = 1;
	printf("�� ������ ���� ���ұ��? : ");
	scanf_s("%d", &user_num);

	for (int i = 1;i <= user_num ; i++)
	{
		answer = answer * i; //answer *= i
	}
	printf("1���� %d������ �� : %d", user_num, answer);
	return 0;
}