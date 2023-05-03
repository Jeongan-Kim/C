#include <iostream>

using namespace std;

// << >> 입출력 stream

class Point
{
	int x;
	int y;

public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}

	auto Getx() const { return x; }
	auto Gety() const { return y; }

	void Print()
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}

	friend ostream& operator << (ostream& out, const Point& p) //ostream : 외부에서 값을 가져오는 것(출력)
	{
		out << "(" << p.x << ", " << p.y << ")" << endl;
		return out;
	}

	friend istream& operator >>(istream& in, Point& p) //istream : 외부에서 값을 가져오는 것(입력)
	{
		in >> p.x >> p.y;
		return in;
	}

};

int main()
{
	Point p1(0, 1), p2(5, 5);
	p1.Print();

	cout << p1 << ", " << p2 << endl; //이런게 원래는 안돼서 오버로딩 함수를 만들어줌.

	//입출력 stream은 chainng이 됨.

	Point p3, p4;
	cin >> p3 >> p4;
	cout << p3 << ", " << p4 << endl;

	return 0;
}