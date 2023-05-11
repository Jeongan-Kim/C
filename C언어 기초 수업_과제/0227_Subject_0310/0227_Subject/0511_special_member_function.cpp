#include <iostream>

using namespace std;

class Test
{
	int a;
	int b;

public:
	//기본 생성자
	Test(Test& data) :a(data.a), b(data.b) {}

	//복사 생성자
	Test(const Test& data) :a(data.a), b(data.b) {}

	//복사 대입 연산자
	Test& operator = (const Test& data)
	{
		a = data.a;
		b = data.b;
		return *this;
	}

	//이동 생성자
	Test(Test&& data) 
		:a(data.a), b(data.b)
	{
	}

	//이동 대입 연산자
	Test& operator = (Test&& data)
	{
		a = data.a;
		b = data.b;
		data.a = NULL;
		data.b = NULL;

		return *this;
	}

	//소멸자
	~Test() {}
};

int main()
{

	return 0;
}