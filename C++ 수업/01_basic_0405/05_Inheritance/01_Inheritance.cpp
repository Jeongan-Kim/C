#include <iostream>
//����� �⺻
using namespace std;

class Mother
{
private: //������ ������ ��ӵ� �ȵ�.
	int a;

public:
	auto GetA() const
	{
		cout << "Mother" << endl;
		return a;
	}

	void SetA(const int& a) { this->a; }

protected: //�θ� �ڽĸ� �� �� �ִ� ������
	int b;
	int c;
};

class Child : public Mother //���� Ŭ������ ������� ����
{
	int b; //���� ��� ����
public:
	auto GetA() const
	{
//		a; //���� ������ ������ ��� �Ұ���
		c; //������ �ִ� �� ��� ����
		b; //child ���� b
		Mother::b; //���� Ŭ������ ���� b

		cout << "Child" << endl;
		return Mother::GetA(); //child �� �� �Լ��� �ƴ϶� ������ �� �Լ�
	}
};
int main()
{
	Child c;
	c.SetA(10); //child Ŭ�������� SetA�Լ��� ������ �θ� Ŭ������ �ֱ⿡ ȣ���� ����

	c.GetA(); //childŬ������ ��� �Լ�(�̸��� �����Ƿ� �θ� Ŭ������ ����Լ� GetA�� ���̵���.)
	c.Mother::GetA(); //�θ� Ŭ������ GetA�� ȣ���Ϸ��� ��������� �̸��� �˷���� ��.

	return 0;
}