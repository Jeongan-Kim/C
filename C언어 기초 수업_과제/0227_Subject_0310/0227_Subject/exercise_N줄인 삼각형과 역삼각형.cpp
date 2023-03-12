#include <stdio.h>

int main()
{
	// N 줄인 삼각형과 역삼각형을 출력한다. 단, 사용자로 부터 임의의 N을 입력 받는다. 아래는 N = 3 일 때의 출력 예시 이다.
// * *** *****
// ***** *** *
	int line = 0;
	printf("만들 삼각형과 역삼각형을 몇 줄로 하고 싶습니까? : ");
	scanf_s("%d", &line);

	printf("<삼각형 모양>\n");
	for (int i = 0; i < line; i++)
	{
		for(int j = 1; j <= 2 * i + 1; j++)
			printf("*");
		printf("\n");
	}

	printf("\n");

	printf("<역삼각형 모양>\n");
	for (int i = 0; i < line; i++)
	{
		for (int j = 1; j <= (line * 2 - 1) - i * 2; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}