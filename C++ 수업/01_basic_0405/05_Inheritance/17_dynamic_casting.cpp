#include <iostream>

using namespace std;
/*
	dynamic cast
	- ������ �ٿ�ĳ���ÿ� ���
	- ��Ÿ�ӿ� ������ �����(�����ٴ� ������ ����)
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

	Derived2* baseToD2 = dynamic_cast<Derived2*>(b); //�̷��� �ϸ� ���������� ����ȯ���� �ʰ�, ��Ÿ�ӿ� ������ ��Ƴ� �� ����.
	baseToD2->k = 888;
}

int main()
{
	Derived1 d1;
	Base* base = &d1; //�� ĳ���� 

	Derived1* baseToD1 = static_cast<Derived1*>(base); //�ٿ� ĳ����(���������� �ϴ� ����ȯ -> ����)
	//d1Ŭ������ �����̹Ƿ� j ������ �ִµ�
	baseToD1->Print();

	DoSomething(&d1); //���� ���Ŀ��� d2Ŭ������ �ڵ�� ������ �����

	cout << d1.j << endl; //d1�� d2�� ���������� ����ȯ�� �ż�, k�� �����϶�� �ߴµ�, j�� ����Ǿ� ���� ��.

	//�׷��� ���̳��� ĳ������ ����ؼ� �����ϰ� �� �� ����

	return 0;
}