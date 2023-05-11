#include <iostream>

/*
	RVO - Return value Optimization : 이름이 없는 경우 최적화가 가능

	NRVO - Named Return Value Optimization : 이름이 있는 경우, 이름있는 객체 생성 함수처럼 최적화가 힘듦
*/

using namespace std;

class Test
{
	int value1;
	int value2;

public:
	static int count; //밖에서 초기화를 해야 쓸 수 있었음

public:
	Test(int value)
		: value1(value), value2(count++)
	{
		cout << "constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	//복사 생성자
	Test(const Test& rhs)
		: value1(rhs.value1), value2(count++)
	{
		cout << "copy constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	//소멸자
	~Test()
	{
		cout << "destructor : " << this->value1 << ", " << this->value2 << endl;
	}
};

int Test::count = 1;

Test MakeRVO(int value)
{
	return Test(value); //반환하는 값이 아무 이름이 없으면 RVO
	//임시 객체의 생성이나 소멸이 일어나지 않는 것
}

Test MakeNRVO(int value)
{
	Test test(value); //이름 있는 임시 객체가 만들어지면서 복사 생성자가 만들어짐
	return 0;
}

int main()
{
	cout << " ---RVO---" << endl;
	Test t1 = MakeRVO(1);

	cout << " ---NRVO---" << endl;
	Test t2 = MakeNRVO(2);

	/*
	 ---RVO---
	constructor : 1, 1
	 ---NRVO---
	constructor : 2, 2
	constructor : 0, 3
	destructor : 2, 2
	destructor : 0, 3
	destructor : 1, 1
	*/
	//근데 이러한 현상은 요즘은 일어나지 않음. 디버그 모드에서만 일어남.(복사 생성자가 만들어지지 않음.)
	return 0;
}