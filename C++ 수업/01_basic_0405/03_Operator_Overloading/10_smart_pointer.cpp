#include <iostream>
//smart pointer �� �������� ����
using namespace std;

class Point
{
	int xpos;
	int ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{
		cout << "Point ��ü ����" << endl;
	}
	~Point()
	{
		cout << "Point ��ü �Ҹ�" << endl;
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

	~SmartPtr() //��ü�� ������ ������ �ϰ� delete ������ ����� ��
	{
		delete posptr;
	}

private:
	Point* posptr;
};

int main()
{
	//Point* ptr = new Point �̷��� ������ �ϴ� �� ����Ʈ �����ͷ� ���ÿ� ����� �� �� ����
	SmartPtr sptr1(new Point(1, 2)); //������ ���ÿ� ������ ���� �־��ְٴ�(?)
	SmartPtr sptr2(new Point(2, 3));
	SmartPtr sptr3(new Point(4, 5));

	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	sptr1->SetPos(10, 20);

	//���α׷��� ����Ǹ鼭 �ڵ����� �Ҹ��ڿ� ���� delete��.
	return 0;
}