#include <iostream>

using namespace std;

/*
������ �����ε��� ���� ��������- ����(3��ǥ�� ���� ����ǵ���) ��) (x1 + x2, y1 + y2, z1 + z2)

	���� ������ +, +vector = vextor, -vextor
	���� ������ +, vector + vector // + - * /
	���� ������ *, vector * 3
	���� ������
	- ���� ++vector
	- ���� vector++

*/

class Vector
{
public:
	Vector(int x, int y, int z) : x(x), y(y), z(z) {}

	void PrintVector()
	{
		cout << "(" << x << ", " << y << ", " << z << ")" << endl;
	}

	//���� ������ +
	Vector operator+() const
	{
		return *this;
	}

	//���� ������ -
	Vector operator-() const
	{
		return Vector{ -x, -y, -z };
	}


	//���� ������ +
	Vector operator+(const Vector& rhs)
	{
		return Vector{ x + rhs.x, y + rhs.y, z + rhs.z };
	}

	//���� ������ -
	Vector operator-(const Vector& rhs)
	{
		return Vector{ x - rhs.x, y - rhs.y, z - rhs.z };
	}


	//���� ������ *
	Vector operator*(const Vector& rhs)
	{
		return Vector{ x * rhs.x, x * rhs.y, x * rhs.z };
	}

	//���� ������ /
	Vector operator/(const Vector& rhs)
	{
		return Vector{ x / rhs.x, y / rhs.y, z / rhs.z };
	}

	//���� ������ * 3
	Vector operator*(const int n)
	{
		return Vector{ x * n, y * n, z * n };
	}


	//����
	Vector& operator++() 
	{
		++x;
		++y;
		++z;
		return *this;
	}

	//����
	Vector& operator++(int) //�ӽ� ��ü�� ���� �� �ܰ� �� ���� �����ؾ� ��.
	{
		x++;
		y++;
		z++;
		return *this;
	}

private:
	int x;
	int y;
	int z;
};


int main()
{
	Vector v1(4, 4, 4), v2(2, 2, 2);

	Vector result1 = +v1;
	result1.PrintVector(); //(4, 4, 4)

	Vector result2 = -v1;
	result2.PrintVector(); //(-4, -4, -4)

	Vector result3 = v1 + v2;
	result3.PrintVector(); //(6, 6, 6)

	Vector result4 = v1 - v2;
	result4.PrintVector(); //(2, 2, 2)

	Vector result5 = v1 * v2;
	result5.PrintVector(); //(8, 8, 8)

	Vector result6 = v1 / v2;
	result6.PrintVector(); //(2, 2, 2)

	Vector result7 = v1 * 3;
	result7.PrintVector(); //(12, 12, 12)

	Vector result8 = ++v1;
	result8.PrintVector(); //(5, 5, 5)

	Vector result9 = v1++;
	result9.PrintVector(); //(6, 6, 6)

	return 0;
}