#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void string();

//void my_strlen;// 헤더 파일을 불러와서 쓰지 않고 함수를 내가 만들어보기.(4가지)

int main()
{
	string();
	char str[100] = "hello C language"; //문자 하나 초기화는 '', 문자열 초기화는 "". 문자열은 끝났다는 것을 컴퓨터에게 알려줘야 함.

	printf("strlen : %d\n", strlen(str)); //문자열의 길이를 재주는 함수(strlen) 공백은 포함하지만 마지막 NULL은 안새어줌.

	char str1[20];
	printf("strcpy : %s\n", strcpy(str1, str)); //str의 문자를 str1에 복사해서 넣어주라는 함수.

	str[0] = 'z';
	printf("strcmp : %d\n", strcmp(str, str1)); //문자열 비교 함수, -1, 0, 1, 앞 문자열이 더 큰 코드를 가지면 1.

	printf("strscat : %s\n", strcat(str, str1)); //str뒤에 str1오도록해줌, NULL제거하고 문자열 합치고 마지막에 NULL추가해줌.

	return 0;
}

void string() //문자열은 끝났다는 것을 컴퓨터에게 알려줘야 함. 그 방법은 여러가지가 있음
{
	char var1 = '\0';
	char var2 = 0;
	char var3 = (char)NULL;

	char notNULL = '0'; //아스키 코드가 실행됨.

	printf("%d %d %d\n", var1, var2, var3);
	printf("%d\n", notNULL);

	{
		char hello[] = { 'H', 'e', 'l', 'l', 'o' };

		for (int i = 0; i < 5; i++)
			printf("%c", hello[i]);

		printf("\n%s\n", hello); //문자열 print변수는 %s, 끝났다는 것을 안알려줘서 이상하게 나옴.

		hello[4] = '\0'; // 마지막에 끝났다는 NULL 문자를 줌.
		printf("\n%s\n", hello);
	}
	{
		char hello[] = "Hello"; // 문자열로 초기화하면 자동으로 배열의 마지막 값을 NULL로 지정해 준 것이됨.
		printf("\n%s\n", hello);
	}
}
