#include <iostream>
//���� ��ȯ��(?)
using namespace std;

class A
{

public:
	virtual A* GetThisPointer() //���� ��ȯ�ϴ� ��
	{ 
		cout << "A" << endl; 
		return this; //���� ����Ű�� �ּ� ��ȯ
	}

	void Print() { cout << "A" << endl; }
};

class B :public A
{
public:
	B* GetThisPointer() override //B�����ʹ� A�� ������ ������ �ִ�(?)
	{
		cout << "B" << endl;
		return this; //AŬ�������� �������̵��� �߾ A ��� �Լ��� ������� ���� �ƴϱ� ������ ���ϰ��� �޶� ������ �ȳ���.
	}

	void Print() { cout << "B" << endl; }
};

int main()
{
	B b;

	b.Print();
	cout << "Address : " << b.GetThisPointer() << endl; //BŬ������ ��ü �ּҰ� ����
	cout << "typeid : " << typeid(b.GetThisPointer()).name() << endl; //�ش� �ڷ����� ���� ���ڿ��� ��ȯ����

	/*
	B
	B
	Address : 000000D3CD8FF988
	typeid : class B * __ptr64
	*/
	A& ref = b;//ref��ü�� A�� �������� b�� �ʱ�ȭ�� �ؼ�, ���� B�� �ּҰ� �������� Ÿ���̳� �Ҽ��� A(?)
	ref.Print();
	cout << "Address : " << ref.GetThisPointer() << endl;
	cout << "typeid : " << typeid(ref.GetThisPointer()).name() << endl;

	/*
	A
	B
	Address : 000000D3CD8FF988
	typeid : class A * __ptr64
	*/
	return 0;
}