#include <iostream>

//()  괄호 연산자. 함수 호출, 묶어주기 등등 목적으로 씀
//객체를 함수처럼 사용하기 위해서 사용하는 오버로딩.

using namespace std;

class Counter
{
	int count = 0;

public:
	int operator()(int i) { return count += i; }
};

class Point
{
	int xpos, ypos;

public:
	Point(int x = 0, int y =0) : xpos(x), ypos(y) {}

	Point operator+(const Point& pos) const
	{
		return Point(xpos + pos.xpos, ypos + pos.ypos);
	}

	friend ostream& operator <<(ostream& os, const Point& pos)
	{
		os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
		return os;
	}
};

class Adder
{
public:
	int operator() (const int& n1, const int& n2)
	{
		return n1 + n2;
	}
	double operator() (const double& n1, const double& n2)
	{
		return n1 + n2;
	}
	Point operator() (const Point& n1, const Point& n2) //구조체 형태
	{
		return n1 + n2;
	}
	
};

int main()
{
	Counter ct;

	cout << ct(10) << endl; //함수 호출 형태로 객체를 쓸 수 있음 : Functor, Function Object
	cout << ct(20) << endl;
	cout << ct(30) << endl;

	cout << endl;

	Adder adder;

	cout << adder(1, 2) << endl;
	cout << adder(1.5, 1.7) << endl;
	cout << adder(Point(3, 4), Point(7, 9));
	return 0;
}