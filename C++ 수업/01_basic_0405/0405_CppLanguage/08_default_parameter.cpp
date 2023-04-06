#include <iostream>
//함수 선언 시 사용하는 기본적인 default 값.( 매개변수에 아무것도 입력 하지 않았을 때 입력되는 기본 값.)
//default para는 overloading과 같이 쓰면 위험함.
using namespace std;

void print(int x = 7) // 아무것도 안들어오면 7을 넣었다고 보자.
{
	cout << x << endl;
}

void print(int x, int y = 7) // 매개변수 하나에만 기본 값을 줘도 되는데, 앞 매개변수는 생략 가능하지만 뒤 매개변수를 생략하는 것은 안됨.
{
	cout << x << y << endl;
}

void test(int x = 10, int y = 10, int z = 10)
{

}

int main()
{
	print(); // 7
	//print(2); // 2인데, 두번째 print 함수에서 y를 생략하고 x에만 2를 넣은 것과 모호성 문제가 일어남

	test(10, 10, 3); // 바꿔 주고 싶은 자리의 매개변수만 바꿔 주고 나머지는 명시해줘야함.

	return 0;
}