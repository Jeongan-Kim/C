#include <stdio.h>

/*
	재귀 함수
	-점화식

	4! = 4 3 2 1 = 4*3!
*/
void Recursive(int num) //재귀 함수
{
	if (num == 0)
		return; //break는 반복문에서만 사용하니 헷갈리지 말것

	printf("Hello to myself\n");
	Recursive(num - 1); // 내 안에서 다시 나를 호출하는 것 (무한 함수이기에 종료 조건이 필요함)
}

int Factorial(int n)
{
	/*
		n*(n-1)*(n-2)*(n-1)* ... *(n-(n-2))*2*1
		=>n*(n-1)!		
	*/

	if (n == 0)
		return 1;

	return n * Factorial(n - 1); //자기 자신을 호출함으로써 반복되면서 값이 줄어서 실제 팩토리얼 함수처럼 실행됨.
}

int main()
{
	Recursive(3);

	int n;
	scanf_s("%d", &n);

	printf("%d", n, Factorial(n));

	return 0;
}