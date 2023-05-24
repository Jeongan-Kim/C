#include <iostream>
//�����Լ� ���̺�(Ŭ�������� �� ���� ������ ����, ���� ��ü�� �־ �ϳ��� �����ϴ� ��, �������̵��Ǹ� ���ŵǴ� ����)
//�Լ� ������ �迭�� ����. ��� �Լ� ȣ�⿡ ���Ǵ� ������ �������̱⶧���� �޸𸮰� �ִ�(?)
//�����Լ� ���̺��� �ּҸ� �����ϴ� �Լ������Ͱ� ���� ���ε� ������.
/*
    class Base                                     Base my_base;
    *__vfptr         --------------------------->  -Base virtual-table
    virtual func1()  <---------------------------  -func1()
    virtual func2()  <---------------------------  -func2()
                 ^
                 |
                 \
                  \________________________________
                                                   \
    class Derived : public Base                     \   Derived my_derived;
    *__vfptr (inherited) --------------------------->\  -Derived virtual_table
    virtual func1()      <----------------------------\--func1() //�������̵� ���� ���� ��� �Լ����� virtual Ű���带 ������ ����.(���� ����)
                                                       \-func2()
*/

using namespace std;

class A
{
	int a;

public:
	void func() {};
};

class Base
{
public:
    virtual void func1() { cout << "func1" << endl; }
    virtual void func2() { cout << "func2" << endl; }
};

class Derived : public Base
{
public:
    virtual void func1() { cout << "Derived::func1" << endl; } //�θ� Ŭ���� �������̵�
    void func3() { cout << "func3" << endl; } //�ڽ� Ŭ�������� �Լ�
};

int main()
{
	{
		A a;
		a.func();

		A aa;
		aa.func();

		//Ŭ������ �Լ��� �ڵ� ������ �����ϴٰ�, ��ü���� ����� ��ΰ� �����ϰ� �ȴ�.
		//a::func();//�׷��� �̷��Դ� �Ұ����߾���
	}

    Base* bptr = new Base();
    bptr->func1();

    Derived* dptr = new Derived();
    dptr->func1();
    dptr->func2();
    dptr->func3();

	return 0;
}