#include <iostream>

using namespace std;

class A
{
public:
	void print() //�ѹ� ���� �� �Ͱ��� ���� ���� ��üȭ���� ���� �͸�üȭ����.
	{
		cout << "print" << endl; 
	}
};

int main()
{
	A().print(); // �̷��� �͸�üȭ�ϸ� �ѹ� ���̰� ������.
	return 0;
}