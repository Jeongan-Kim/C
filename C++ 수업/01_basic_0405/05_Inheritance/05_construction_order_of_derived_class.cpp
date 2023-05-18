#include <iostream>

using namespace std;

//생성자가 자식 클래스에서 어떤 순서로 만들어지는지 알아보자

class Parent
{
	int a;

public:
	Parent()
		:a(10)//멤버 초기화 리스트가 있던 없던, 매개 변수가 없으면 디폴트 생성자.
	{
		cout << "Base Constructor" << endl;
	}
};

class Child : public Parent
{
	double b;

public:
	Child()
		:/*Parent()*/ b(10.0) //부모 클래스 객체가 만들어지고 자식 클래스가 만들어지는 순서
	{
		cout << "Derived Constructor" << endl;
	}
};

class A			   { public: A() { cout << "A constructor" << endl; } };
class B : public A { public: B() { cout << "B constructor" << endl; } };
class C : public B { public: C() { cout << "C constructor" << endl; } };
class D : public C { public: D() { cout << "D constructor" << endl; } };

int main()
{
	Child child;

	cout << endl;

	D d;
	return 0;
}