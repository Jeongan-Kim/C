#include <iostream>

using namespace std;

/*
연산자 오버로딩을 통해 만들어오기- 과제(3좌표가 각각 연산되도록) 예) (x1 + x2, y1 + y2, z1 + z2)

	단항 연산자 +, +vector = vextor, -vextor
	이항 연산자 +, vector + vector // + - * /
	이항 연산자 *, vector * 3
	증감 연산자
	- 전위 ++vector
	- 후위 vector++

*/

class Vector
{
public:
	Vector(int x, int y, int z) : x(x), y(y), z(z) {}

	void PrintVector()
	{
		cout << "(" << x << ", " << y << ", " << z << ")" << endl;
	}

	//단항 연산자 +
	Vector operator+() const
	{
		return *this;
	}

	//단항 연산자 -
	Vector operator-() const
	{
		return Vector{ -x, -y, -z };
	}


	//이항 연산자 +
	Vector operator+(const Vector& rhs)
	{
		return Vector{ x + rhs.x, y + rhs.y, z + rhs.z };
	}

	//이항 연산자 -
	Vector operator-(const Vector& rhs)
	{
		return Vector{ x - rhs.x, y - rhs.y, z - rhs.z };
	}


	//이항 연산자 *
	Vector operator*(const Vector& rhs)
	{
		return Vector{ x * rhs.x, x * rhs.y, x * rhs.z };
	}

	//이항 연산자 /
	Vector operator/(const Vector& rhs)
	{
		return Vector{ x / rhs.x, y / rhs.y, z / rhs.z };
	}

	//이항 연산자 * 3
	Vector operator*(const int n)
	{
		return Vector{ x * n, y * n, z * n };
	}


	//전위
	Vector& operator++() 
	{
		++x;
		++y;
		++z;
		return *this;
	}

	//후위
	Vector& operator++(int) //임시 객체를 만들어서 한 단계 전 값을 리턴해야 함.
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