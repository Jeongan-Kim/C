#include <stdio.h>


int main()
{
	char alphabet;
	printf("��ҹ��ڸ� �ٲٰ� ���� ���ĺ��� �Է��ϼ��� : ");
	scanf_s(" %c", &alphabet);

	int ASCII_number = alphabet;

	if (ASCII_number >= 97 && ASCII_number <= 122)
	{
		int ASCII_number1 = ASCII_number - 32;
		char alphabet1 = ASCII_number1;
		printf(" %c", alphabet1);
	}
	else if (ASCII_number >= 65 && ASCII_number <= 90)
	{
		int ASCII_number2 = ASCII_number + 32;
		char alphabet2 = ASCII_number2;
		printf(" %c", alphabet2);
	}
	else
		printf("�߸� �Է��Ͽ����ϴ�.");

	return 0;
}