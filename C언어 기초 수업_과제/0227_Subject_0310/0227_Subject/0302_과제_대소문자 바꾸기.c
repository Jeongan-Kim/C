#include <stdio.h>

int main()
{
	char a;
	printf("��ҹ��ڸ� �ٲٰ� ���� ���ĺ��� �Է��ϼ��� : ");
	scanf_s(" %c", &a);

	int i=a;

	if (a >= 97)
	{
		int b1 = a - 32;
		char c1 = b1;
		printf(" %c", c1);
	}
	else
	{
		int b2 = a + 32;
		char c2 = b2;
		printf(" %c", c2);
	}

	return 0;
}