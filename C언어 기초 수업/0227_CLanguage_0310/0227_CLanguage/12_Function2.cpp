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

/*
피보나치 수열

0 1 1 2 3 5 8 13 ...

0 + 1 = 1
1 + 1 = 2
1 + 2 =3

n = (n-1) + (n-2) //n은 각각을 인덱스 원소라고 생각했을 때
n-1 = (n-2) + (n-3)
*/

//int Fibonacci(int n)
//{
//	int f1 = 0, f2 = 1, f3;
//
//	if (n == 1)
//		printf("%d", f1);
//	else
//		printf("%d %d ", f1, f2);
//
//	for (int i = 2, i < n; i++)
//	{
//		f3 = f1 + f2;
//		printf("%d", f3);
//
//		f1 = f2;
//		f2 = f3;
//	}
//	//전체 또는 for 함수를 재귀 함수를 이용해서 바꿔 보기(과제), 피보나치 재귀
//}

int fibonaccirecu(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	return fibonaccirecu(n - 1) + fibonaccirecu(n - 2);
}

int main()
{
	Recursive(3);

	int n;
	scanf_s("%d", &n);

	printf("%d", Factorial(n));

	int m;
	scanf_s("%d", &m);

	for (int i = 0; i < m; i++)
	{
		printf("%d ", fibonaccirecu(i));
	}

	return 0;
}


//과제 :로또, 피보나치 재귀