#include <iostream>

using namespace std;

class Test
{
	int a;
	int b;

public:
	//�⺻ ������
	Test(Test& data) :a(data.a), b(data.b) {}

	//���� ������
	Test(const Test& data) :a(data.a), b(data.b) {}

	//���� ���� ������
	Test& operator = (const Test& data)
	{
		a = data.a;
		b = data.b;
		return *this;
	}

	//�̵� ������
	Test(Test&& data) 
		:a(data.a), b(data.b)
	{
	}

	//�̵� ���� ������
	Test& operator = (Test&& data)
	{
		a = data.a;
		b = data.b;
		data.a = NULL;
		data.b = NULL;

		return *this;
	}

	//�Ҹ���
	~Test() {}
};

int main()
{

	return 0;
}