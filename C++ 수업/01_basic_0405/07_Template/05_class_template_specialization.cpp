#include <iostream>
//클래스 자체, 전체의 특수화

using namespace std;

template<class T>
class A
{
public:
	A(const T& input) {}

	void DoSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void Test() {}
};

template<> //특수화
class A<char> //char형으로 만들어 질때만 특수화하겠다.
{
public:
	A(const char& input) {}

	void DoSomething()
	{
		cout << "char type specialization" << endl;
	}

	//여기에는 Test함수가 없다. 이처럼 함수도 다르게 만들어 줄 수가 있다.
};

int main()
{
	A<int> aint(10);
	A<double> adouble(10.1);
	A<char> achar('a');

	aint.DoSomething();
	adouble.DoSomething();
	achar.DoSomething();

	aint.Test();
	adouble.Test();
	//achar.Test(); //얘는 없음

	return 0;
}