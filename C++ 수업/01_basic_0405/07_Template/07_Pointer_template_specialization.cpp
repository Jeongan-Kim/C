#include <iostream>

using namespace std;

template<class T>
class A
{
	T value;

public:
	A(const T& value) :value(value) {}

	void Print()
	{
		cout << value << endl;
	}
};

//포인터 멤버인 경우에만 특수화
template<class T>
class A<T*>
{
	T* value;

public:
	A(T* value) :value(value) {}

	void Print()
	{
		cout << *value << endl;
	}
};

int main()
{
	A<int> Aint(123);
	Aint.Print();

	int temp = 456;
	A<int*> Aptr(&temp);
	Aptr.Print(); //원래는 주소값이 찍힘
	//포인터의 경우에도 값이 찍히게끔 하고 싶을때. 포인터인 경우 특수화가 가능


	return 0;
}