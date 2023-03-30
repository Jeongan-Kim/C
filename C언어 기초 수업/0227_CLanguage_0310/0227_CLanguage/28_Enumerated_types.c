#include <stdio.h>

//상수에 이름을 부여하는 것

void myEnum();

int main()
{
	myEnum();
	return 0;
}

void myEnum()
{
	{ //매크로 상수로 하는 법
	#define RED 0
	#define ORG 1
	#define YEL 2

		int c = 0;

		printf("숫자 입력 : ");
		scanf_s("%d", &c);

		if (c == RED)
			printf("red\n");
		else if(c == ORG)
			printf("orange\n");
		else if(c == YEL)
		printf("yellow\n");
	}
	{
		enum color
		{
			Red, //0   
			Orange, //1 
			//Orange = 10( 또는 a 아스키코드로)//아무거나 값을 지정해 주면 그걸 기준으로 1만큼 더하고 빼면서 알아서 잡힘
			Yellow //2 => 하나씩 증가하면서 저장됨. 
		};

		int c = 0;

		printf("숫자 입력 : ");
		scanf_s("%d", &c);

		if (c == Red)
			printf("red\n");

		if (c == Orange)
			printf("orange\n");

		if (c == Yellow)
			printf("yellow\n");

		for (c = Red; c <= Yellow; c++) //C에서만 가능, 숫자로 뽑아서 볼 수도 있음, 산술 연산이 가능
			printf("%d, ", c);
	}
}


// 과제 => 달팽이 배열 : 인덱스 바꿔서 출력하는 아이디어를 이용해서 빙글빙글 돌게 찍기