#include <iostream>

/*
	RVO - Return value Optimization : �̸��� ���� ��� ����ȭ�� ����

	NRVO - Named Return Value Optimization : �̸��� �ִ� ���, �̸��ִ� ��ü ���� �Լ�ó�� ����ȭ�� ����
*/

using namespace std;

class Test
{
	int value1;
	int value2;

public:
	static int count; //�ۿ��� �ʱ�ȭ�� �ؾ� �� �� �־���

public:
	Test(int value)
		: value1(value), value2(count++)
	{
		cout << "constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	//���� ������
	Test(const Test& rhs)
		: value1(rhs.value1), value2(count++)
	{
		cout << "copy constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	//�Ҹ���
	~Test()
	{
		cout << "destructor : " << this->value1 << ", " << this->value2 << endl;
	}
};

int Test::count = 1;

Test MakeRVO(int value)
{
	return Test(value); //��ȯ�ϴ� ���� �ƹ� �̸��� ������ RVO
	//�ӽ� ��ü�� �����̳� �Ҹ��� �Ͼ�� �ʴ� ��
}

Test MakeNRVO(int value)
{
	Test test(value); //�̸� �ִ� �ӽ� ��ü�� ��������鼭 ���� �����ڰ� �������
	return 0;
}

int main()
{
	cout << " ---RVO---" << endl;
	Test t1 = MakeRVO(1);

	cout << " ---NRVO---" << endl;
	Test t2 = MakeNRVO(2);

	/*
	 ---RVO---
	constructor : 1, 1
	 ---NRVO---
	constructor : 2, 2
	constructor : 0, 3
	destructor : 2, 2
	destructor : 0, 3
	destructor : 1, 1
	*/
	//�ٵ� �̷��� ������ ������ �Ͼ�� ����. ����� ��忡���� �Ͼ.(���� �����ڰ� ��������� ����.)
	return 0;
}