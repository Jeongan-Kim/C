#include <iostream>

using namespace std;

//�����ڰ� �ڽ� Ŭ�������� � ������ ����������� �˾ƺ���

class Parent
{
	int a;

public:
	Parent()
		:a(10)//��� �ʱ�ȭ ����Ʈ�� �ִ� ����, �Ű� ������ ������ ����Ʈ ������.
	{
		cout << "Base Constructor" << endl;
	}
};

class Child : public Parent
{
	double b;

public:
	Child()
		:/*Parent()*/ b(10.0) //�θ� Ŭ���� ��ü�� ��������� �ڽ� Ŭ������ ��������� ����
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