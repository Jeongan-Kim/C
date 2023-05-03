#include <iostream>
//��������� 
//������ �����ε� �� ���� ���� : �ǵ��� ����� ������ ���� �ʴ� �� ����. �켱������ ������ ����.(+���� *�� �켱)

using namespace std;

//#pragma region 1. �����Լ��� ���� ������ �����ε�
//class Won
//{
//public:
//	Won(int value) : value(value){}
//
//	int GetValue() const { return value; }
//
//private:
//	int value;
//
//	friend int operator+(const Won& lhs, const Won& rhs); //private���� friend�� �پ �����Լ�ó�� ����, lhs ����, rhs ����
//
//	//�����ڸ� ���� ������� ���� ����
//	friend Won operator-(const Won& lhs, const Won& rhs) //�Լ� ���Ǻθ� Ŭ���� �ȿ��� ���൵ ��.
//	{
//		return lhs.value - rhs.value;
//	}
//};
//
//int main()
//{
//	Won l(10), r(10);
//
//	int result = l + r;
//	cout << result << endl;
//
//	Won result2(l - r); //��ü ������ ���ÿ� �ص� ������ ����� getvalue�� �����;� ��
//	cout << result2.GetValue() << endl;
//
//	return 0;
//}
//
//int operator+(const Won& lhs, const Won& rhs)
//{
//	return lhs.value + rhs.value;
//}
//
///*
//	operator+(a, b);
//*/
//
//#pragma endregion

#pragma region 2. ����Լ��� ���� ������ �����ε�

class Won
{
public:
	Won(int value) : value(value) {}

	int GetValue() const { return value; }

	//l.opertaor+(r) �̷� ����̶�� ���ظ� ����.(��¥ �̷� ���´� �ƴ�)
	int operator+(const Won& rhs)
	{
		return value + rhs.value;
	}
	
	Won operator-(const Won& rhs)
	{
		return value + rhs.value;
	}

private:
	int value;
};

int main()
{
	Won l(10), r(10);
	int result = l + r;
	cout << result << endl;

	Won result2 = l - r;
	cout << result2.GetValue() << endl; // �ʱ� Ȯ���ϱ�

	return 0;
}
#pragma endregion

/*
������ �����ε��� ���� ��������- ����(3��ǥ�� ���� ����ǵ���) ��) (x1 + x2, y1 + y2, z1 + z2)

	���� ������ +, +vector = vextor, -vextor
	���� ������ +, vector + vector // + - * /
	���� ������ *, vector * 3
	���� ������
	- ���� ++vector
	- ���� vector++

*/

#pragma region ��� ������ �����ε�
class Vector
{
public:
	Vector(int x, int y, int z) : x(x), y(y), z(z) {}

	Vector operator+() const
	{
		//return Vector{ x, y, z };
		return *this; //this�� �� �ڽ��� ������(�ּ�)�̹Ƿ� *�ٿ���.
	}

	//����, ����
	Vector& operator++()
	{
		x += 1; //�̷��� ���ų�
		++y; //�̷��� ���� ��
		++z;
		return *this;
	}

	Vector& operator++(int) //�����ϱ� ���ؼ� ���� : dummy(�ƹ� �ǹ� ������ �����ϱ� ���� ���� ��)
	{
		//���� ���� ��� �� ������ ���� ����� ��.
		Vector temp = *this; //�ӽ� ������ �������� ������ ����
		++(*this); //�̷��� �ص� ��
		return temp;//��ȯ�� �ӽ� ������ ������ ���� ���� ���� ����.
	}

private:
	int x;
	int y;
	int z;
};

#pragma endregion

/*

	������ ���� : ���� ������ ������ �ϳ� �þ��
	�� ������ �ε����ų� ���� �ε����� ���� ����.
	(�����̸� ��Ÿ���� �迭���� list�� Ȱ���� �ִ� �� �� ����)
*/