#include <stdio.h>

/*
지역(local) 변수
전역(global) 변수 : main 위에 쓰는 변수
*/

//전역 변수
int global; // 프로그램 전체가 유효 범위, 안정성을 높히기 위해서는 사용하지 않는 게 좋음, 초기화 하지 않으면 자동으로 0으로 됨

char var1 = 'G';

void LocalCount();
void StaticCount();

int main()
{
	printf("초기화 하지 않은 global 값 : %d\n", global);

	printf("main에서의 var1 : %c\n", var1);
	//지역 변수 : 특정 지역에서만 사용할 수 있는 변수, 괄호 안에 있으면 지역 변수라고 보면 됨.
	{
		char var1 = 'L';
		printf("{}에서의 var1 : %c\n", var1); // 출력할 때 가장 가까운 지역에서 선언된 값을 우선으로 함.(소괄호도 동일)
	}

	printf("main에서의 var1 : %c\n", var1); //값이 바뀐 게 아니라 지역 밖에서는 지역 안의 정의가 가려짐.

	for (int i = 0; i < 5; i++)
	{
		LocalCount();
		StaticCount();
	}
	return 0;
}

void LocalCount()
{
	int count = 1;

	printf("local count : %d\n", count);
	count++;
}

void StaticCount()
{
	static int count = 1; //static : 정적 변수, 프로그램 종료 시에 소멸됨. 맨 처음 선언해 줘야 하는 전역 변수와 다르게 선언한 순간 생겨남. 전역 변수보다 안정적.
	//static은 최초 선언 시에만 초기화가 됨.
	printf("static count : %d\n", count);
	count++;
}
