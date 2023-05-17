#include <iostream>

using namespace std;

class Test
{
	int value;
	static int value2;

public:
	Test() {}
	void Temp1() { this->value; }
	void Temp1() const { this->value; } //����Լ��� �����ε� ����

	//static void Temp2() { this->value; } //static�Լ������� this call�Ұ���. �ܼ��� �� Ŭ���� �ȿ� ���ԵǾ��� ��.
	//�׷��� ���� ������ �ܼ��� ���ԵǱ⸸�� ������ ��� ����.
	static void Temp2() { value2; }

	int test;

};
int main()
{
	//Test::Temp1(); �Լ��� ȣ���ҋ�, �̷� ����� �Ұ���
	Test t1;
	t1.Temp1(); //�̷��� �߾�� �ߴµ�,

	Test::Temp2(); //static�Լ��� �̷��� ȣ�� ����. �Ϲ� �Լ� ����� �Ѵٰ� �����ϸ� ��.
	//�׷��� �Լ� �����͵� ����
	void (*ptr1)() = Test::Temp2;
	//void (*ptr2)() = Test::Temp1; //this call�����̱⿡ �����ڸ� �� �� ��� �̰� �Ұ���

	/*
		��� ������ : ��ü�� ����� ����ؾ� �Ѵٴ� �������� ����.
	*/

	//������ ���.
	int Test::* ptr2 = &Test::test; //test�� ������. ������ ���� ��ü�� ����.
	t1.*ptr2 = 10; //test�� t1��� ��ü ���� ������� �˷��ִ� ��.


	//�Լ��� ���.
	void(Test:: * ptr3)() = &Test::Temp1;
	(t1.*ptr3)();

	return 0;
}