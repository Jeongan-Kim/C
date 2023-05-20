#include <iostream>

using namespace std;

//�ռ� ��� �� ������ ����
//�����Լ� ���̺��� ���� �����Ǽ� �������̵� ������ �����.
class A
{
public:
	void Print() { cout << "A" << endl; }
	virtual void Print1() { cout << "A1" << endl; } //�����Լ� ���̺� ���ʴ�� virtual �Լ��� �ּҰ� �����.
	virtual void Print2() { cout << "A2" << endl; }
	virtual void Print3() { cout << "A3" << endl; }
	virtual void Print4() final { cout << "A4" << endl; }
};

class B : public A
{
public:
	void Print() { cout << "B" << endl; }
	virtual void Print1() { cout << "B1" << endl; } //�����Լ��� �������̵� �����̹Ƿ�, A�� print1�� �ּҸ� ���� ����� �����.(�ּҰ� ������)
	virtual void Print2() { cout << "B2" << endl; }
	virtual void Print3() final { cout << "B3" << endl; }
//	virtual void Print4() final { cout << "B4" << endl; }
};

class C : public B
{
public:
	void Print() { cout << "C" << endl; }
	virtual void Print1() { cout << "C1" << endl; }
	virtual void Print2() final { cout << "C2" << endl; }
//	virtual void Print3() final { cout << "B3" << endl; }
//	virtual void Print4() final { cout << "B4" << endl; }
};

class D : public C
{
public:
	void Print() { cout << "D" << endl; }
	virtual void Print1() { cout << "D1" << endl; }
//	virtual void Print2() final { cout << "D2" << endl; }
//	virtual void Print3() final { cout << "B3" << endl; }
//	virtual void Print4() final { cout << "B4" << endl; }
};


int main()
{
	A a;
	a.Print1();

	B b;
	b.Print1();

	C c;
	c.Print1();

	D d;
	d.Print1();

	cout << endl;

	A& refB = b; //�ֻ��� �θ� Ŭ������ �̿��ؼ� �ڽ� Ŭ������ �����ڸ� ����
	A& refC = c;
	A& refD = d;

	cout << "###### A" << endl;

	a.Print();
	a.Print1();
	a.Print2();
	a.Print3();
	a.Print4();


	cout << "###### B" << endl;

	refB.Print(); //virtual�� ���� �ʾƼ� �θ� Ŭ����(�ֻ���)�� �Լ��� ����
	refB.Print1();
	refB.Print2();
	refB.Print3();
	refB.Print4(); //final�� ������ ���� �θ�Ŭ������ ���� ����, ���� �������� �������̵��� ��� �Լ��� ����.

	cout << "###### C" << endl;

	refC.Print();
	refC.Print1();
	refC.Print2();
	refC.Print3();
	refC.Print4();

	cout << "###### D" << endl;

	refD.Print();
	refD.Print1();
	refD.Print2();
	refD.Print3();
	refD.Print4();

	//���� : �����Լ��� �ּҰ� ���Ƽ� �׷���. �����Լ��� �����Լ� ���̺�(��� �Լ��� �ּҸ� �������̵� �Լ� �ּҷ� ��ü ���ִ� ���� ���� ��)�� �̿���.

	D d1;
	D d2;
	//����� ���ʿ� ��ġ ��� F11�����鼭 �ϳ��� Ȯ���� �� �ְ�, �ڵ� �� ���� �ǿ��� �ּ� �� Ȯ�� ����.
	//d1�� d2�� �ּҰ� ���� ���� Ȯ���� �� �ִ�.
	return 0;
}

//������� �����(�ٽ�)
/*
* ���α׷� �����
	Vehicle -> �Լ� movement�� ������ Vehicle(�θ�Ŭ����) ����
	�̸� ��� �޴� airplane, car, ship�� ���� movement (�������̵�)�Լ��� ȣ������ ��
	(����� �̵�), (���� �̵�), (���� �̵�) �̷� ������ ��µǰ� �����,
	��� �̵� ������ ������ 5�� �ʰ��� ���,
	��ü ���� �� "�̵� ���� ���� 5�� �ʰ��մϴ�"�� ���.

*/

//class Vehicle
//{
//	virtual void movement() {}
//};
//
//class Car :public Vehicle
//{
//	void movement() overriding {(�����̵�, ��� ���) }
//};
//
//int main()
//{
//
//	a.movement(); -> �ټ� �� ������ ���� ��� �ϱ�.(���� �ȵǰԵ� �غ���, �ȵǸ� ��� ������.)
//
//	return 0;
//}