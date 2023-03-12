#include <stdio.h>


int main()
{
	char alphabet;
	printf("대소문자를 바꾸고 싶은 알파벳을 입력하세요 : ");
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
		printf("잘못 입력하였습니다.");

	return 0;
}