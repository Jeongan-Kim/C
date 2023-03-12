#include <stdio.h>

/*
Variable(변수)
-변할 수 있는 데이터

Constant(상수)
-변하지 않는 데이터(절대적)
*/

int main()
{
	//변수 선언 방법 : Datatype name;
	int a; //int(integer, 정수)는 변수의 타입, 선언(declaration)
	a = 10; //initialize(초기화), =(대입 연산자) : 같다는 의미가 아니라 대입

	
	printf("%d\n", a);

	a = 11; //변수는 바뀔 수 있으므로 새로 선언, 새로 할 때에는 int 사용하지 않음

	printf("%d\n", a);

	int b = 20; //선언과 동시에 초기화
	printf("%d\n", b);
	/*
	b를 초기화할 때
	b=20이 맞다
	int b = 20이라고 하면 변수 선언을 두 번한 것이라 오류

	*/
	b = 30;

	int result;
	result = a + b;
	printf("결과 : %d\n", result);

	//변수 표기법
	//헝가리안 표기법(요즘엔 많이 안씀)
	int i_age;
	int intweight;

	//요즘 쓰는 방법, hp와 count가 따로 쓰는 말이므로 3가지 방법으로 쓸 수 있다.
	int hpCount; //카멜 표기법(변수를 쓸때)
	int HpCount; //파스칼 표기법(함수를 쓸때)
	int hp_count; //스네이크 표기법

	int a1;
	//int 1a; 변수 앞에 숫자 불가
	//int 1 a; 변수 사이 띄어쓰기 불가
	//int for, int if (나중에 배우지만 이런 단어도 못 씀)

	return 0;
}