#include <iostream>

using namespace std;
//�Ҹ��ڰ� �ڽ� Ŭ�������� � ������ ����������� �˾ƺ���

class A //Ŭ���� ũ��� 4����Ʈ
{
	int a;
public:
	A() { cout << "A constructor" << endl; }
	~A() { cout << "A distructor " << endl; }
};

class B : public A
{   //A�� ��� �޾����� int a�� �ִٰ� �����ϰ� Ŭ���� ũ��� ���� �ΰ��� 16����Ʈ(���� ����ȭ ����, �е�(padding) ����Ʈ ������� �����ϱ� ������)
	//�޸� �� �ٿ� �տ��� ä�� �����ϰ� �ڿ� ���� �κ��� �е��̶�� ��
	double b;
public:
	B() { cout << "B constructor" << endl; }
	~B() { cout << "B distructor " << endl; }
};


int main()
{
	B b;
	//������ �θ� ����, �Ҹ��� �ڽ��� ����(LIFO ����)
	/*
		A constructor
		B constructor
		B distructor
		A distructor
	*/

	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	return 0;
}

struct S //48����Ʈ( ���̸� 32����Ʈ���� ���� �� �ִ�)(�ִ��� ȿ�������� ���� �� ���� ������ ��������)
{
	char c1;
	double d1;
	int i1;
	int i2;
	short s1;
	short s2;
	double d2;
	char c2;
	char c3;
};