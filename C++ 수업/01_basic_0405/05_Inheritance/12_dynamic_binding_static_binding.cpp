#include <iostream>
//�Լ��� ȣ��ɶ� �Լ� �ּҸ� ������ �ִ� ����(���ε�)
/*
	static binding(���� ���ε�, Early binding) : ������ Ÿ�ӿ� ȣ��� �Լ��� �����. �������� �������� ����.
	dynamic binding(���� ���ε�, late binding) : ��Ÿ�ӿ� ȣ��� �Լ��� �����. �������� ����. ��ü ���� Ư�� �� �������� Ư¡���ε� ��
*/

using namespace std;

//�Ϲ����� ���� �Լ��� ������ �����غ���.
int add(int x, int y) { return x + y; }
int subract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }

int main()
{
	//���� ���ε�(�ִ� �״�� �� �Լ��� ȣ���ؼ� ����ϴ� ���)
	int x, y;
	cin >> x >> y;
	int op;
	cout << "0 : add, 1 : subtract, 2 : multiply" << endl;
	cin >> op;

	int result;
	switch(op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subract(x, y); break;
	case 2: result = multiply(x, y); break;
	}

	cout << result << endl;


	//���� ���ε�(���� �� ������ ����, �ּ� ���� ��ü�� ���� Ÿ�ӿ� ��)
	//�Լ� �����Ϳ� �־� ����, �ʿ��ҋ� ������ ��

	int(*funcptr)(int, int) = nullptr;
	//�ϳ��� �Լ� �����Ϳ� ���� �Լ��� �ٲ� �־�� �� �� �־ ����.

	switch (op)
	{
	case 0: funcptr = add; break;
	case 1: funcptr = subract; break;
	case 2: funcptr = multiply; break;
	}

	return 0;
}