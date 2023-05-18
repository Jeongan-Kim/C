#include <iostream>

using namespace std;

int add(int a, int b) { return a + b; }
short add(short a, short b) { return a + b; }
float add(float a, float b) { return a + b; }
//이렇게 여러 자료형으로 오버로딩 함수를 만들고 싶을때 간단하게 쓰는 방법을 알아보자.

/*
Template 
같은 이름 함수를 여러 자료형으로 만들고 싶을때 쓰는 것
*/

template <typename T> 
T add(T a, T b) //오버로딩 함수 다 만들어놓지 않아도 쓸때마다 지정해서 쓸 수 있는 편리한 것.
{
	return a + b;
}

int main()
{
	add(10, 20);
	add(10.0f, 20.0f);
	add(20.1, 50.2);


	return 0;
}