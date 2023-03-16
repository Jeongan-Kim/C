#include <stdio.h>
#include <string.h>

void palindrome(char arr[]);

int main()
{
	char word[100];
	printf("회문 유무를 확인하고 싶은 말을 쓰세요. : ");
	gets(word);

	printf("\n");

	palindrome(word);

	return 0; 
}

void palindrome(char arr[])
{
	int sameNum = strlen(arr) / 2;
	int answer = 0;
	
	for (int i = 0; i < sameNum; i++)
	{
		if (arr[i] != arr[strlen(arr) - i - 1])
			answer = 1;			
	}

	if (answer == 0)
		printf("회문입니다.\n");
	else
		printf("회문이 아닙니다.\n");
}
