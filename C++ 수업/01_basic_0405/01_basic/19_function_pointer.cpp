#include <iostream>
#include <functional>

using namespace std;

//함수 포인터 쓰는 여러가지 방법

bool func(const int& x) //L-value reference
{
	return x > 0;
}

typedef myint int; //myint를 int처럼 쓰겠다!

typedef bool(*funcPtr)(const int&);

using funcType = bool(*)(const int&);

int main()
{
	bool (*pf)(const int&) = func; //함수 포인터 쓰는 방법 리턴값 (포인터 이름)(매개변수 형태)

	funcPtr f = func;
	
	funcType f2 = func;

	std::function<bool(const int&)> f3 = func; //functional 헤더 파일을 쓰면 쓸 수 있는 것.

	return 0;
}