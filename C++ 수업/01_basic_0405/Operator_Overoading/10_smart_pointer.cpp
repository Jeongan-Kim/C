#include <iostream>
//smart pointer 의 개념적인 이해
using namespace std;

class Point
{
	int xpos;
	int ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{
		cout << "Point 객체 생성" << endl;
	}
	~Point()
	{
		cout << "Point 객체 소멸" << endl;
	}

	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	friend ostream& operator << (ostream& os, const Point& pos)
	{
		os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
		return os;
	}
};

class SmartPtr
{

public:
	SmartPtr(Point* ptr) : posptr(ptr) {}

	Point& operator*() const
	{
		return *posptr;
	}

	Point* operator->() const
	{
		return posptr;
	}

	~SmartPtr() //객체가 없지만 가정을 하고 delete 과정을 만들어 줌
	{
		delete posptr;
	}

private:
	Point* posptr;
};

int main()
{
	//Point* ptr = new Point 이렇게 만들어야 하는 데 스마트 포인터로 동시에 만들어 줄 수 있음
	SmartPtr sptr1(new Point(1, 2)); //생성과 동시에 포인터 값을 넣어주겟다(?)
	SmartPtr sptr2(new Point(2, 3));
	SmartPtr sptr3(new Point(4, 5));

	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	sptr1->SetPos(10, 20);

	//프로그램이 종료되면서 자동으로 소멸자에 의해 delete됨.
	return 0;
}