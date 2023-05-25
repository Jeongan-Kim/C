#include <iostream>

using namespace std;
/*
	dynamic cast
	- 안전한 다운캐스팅에 사용
	- 런타임에 오류를 잡아줌(느리다는 단점이 있음)
*/

class Base
{
public:
	int i = 0;
	virtual void Print() { cout << "Base" << endl; }
};

class Derived1 :public Base
{
public:
	int j = 1;
	virtual void Print() override { cout << "Derived1" << endl; }
};

class Derived2 :public Base
{
public:
	int k = 2;
	virtual void Print() override { cout << "Derived2" << endl; }
};

void DoSomething(Base* b)
{
	//Derived2* baseToD2 = static_cast<Derived2*>(b);
	//baseToD2->k = 888;

	Derived2* baseToD2 = dynamic_cast<Derived2*>(b); //이렇게 하면 강제적으로 형변환하지 않고, 런타임에 오류를 잡아낼 수 있음.
	baseToD2->k = 888;
}

int main()
{
	Derived1 d1;
	Base* base = &d1; //업 캐스팅 

	Derived1* baseToD1 = static_cast<Derived1*>(base); //다운 캐스팅(강제적으로 하는 형변환 -> 위험)
	//d1클래스의 정보이므로 j 변수가 있는데
	baseToD1->Print();

	DoSomething(&d1); //여기 이후에서 d2클래스의 코드로 내용이 변경됨

	cout << d1.j << endl; //d1을 d2로 강제적으로 형변환이 돼서, k를 변경하라고 했는데, j가 변경되어 버린 것.

	//그래서 다이나믹 캐스팅을 사용해서 안전하게 할 수 있음

	return 0;
}