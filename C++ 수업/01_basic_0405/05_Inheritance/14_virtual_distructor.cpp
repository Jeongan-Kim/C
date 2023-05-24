#include <iostream>
//���� �Ҹ���
using namespace std;

class Base
{
public:
	Base() { cout << "Base()" << endl; }
	virtual ~Base() { cout << "~Base()" << endl; } // �ڽ� Ŭ������ �Ҹ��ڰ� ���е��� �ʰ� ȣ����� �ʵ��� virtual Ű���� �ٿ���� ��.
};

class Derived : public Base
{
	int* arr = nullptr; //�����͸� ���� �����Ҵ��� �ϴ� Ŭ������ ���� ����

public:
	~Derived() 
	{
		//TODO : �������� �۾�
		cout << "~Derived()" << endl;
	}
};

int main()
{
	Base b;

	Base* base = new Derived; //�θ�Ŭ���� �����ͷ� �ڽ� Ŭ������ ������ ��(��ĳ���� ����)
	//�̷� ��� �ڽ� Ŭ������ �Ҹ��ڰ� ���еǾ� �����Ҵ� ���� �۾��� �����ְ� ��. 
	//-> �θ�Ŭ������ �Ҹ��ڸ� ���� �Ҹ��ڷ� ����� �ִ� �� ����.
	//Ŭ������ ����� �����̸� �Ҹ��ڿ� virtual Ű���带 �ٿ�����.
	delete base; // ��ü ��ü�� �����Ҵ��� ���̹Ƿ� delete�� ������ ���ִ� ��.

	/*
	Base()
	Base()

	~Base()
	~Base()

---------------

	Base()
	Base()
	~Derived()
	~Base()
	~Base()
	*/
	return 0;
}