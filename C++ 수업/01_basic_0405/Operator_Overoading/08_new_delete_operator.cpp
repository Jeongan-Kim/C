#include <iostream>
//new : ���� �迭 �Ҵ�. �޸𸮰� ����. 

using namespace std;

class Point
{
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{}

	friend ostream& operator <<(ostream& os, const Point& pos)
	{
		os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
		return os;
	}

	void* operator new(size_t size) //Ŭ������ �°� �� ��ȯ�� �Ǿ�� ��. �޸� ������ �˾ƾ� ��.
	{
		//�����Ϸ��� ���� �� ����Ʈ�� ũ��� �Ҵ��ؼ� �޾ƿ��� ������.
		void* adr = new char[size];
		return adr; 
		//�����Ϸ��� �޸� ������ �ʱ�ȭ���༭ ��ü�� �ϼ��ǰ�, Ŭ������ �°� ����ȯ���� ����. �����ڱ��� ȣ�����شٴ� ���� new���� ������.
	}

	void operator delete (void* adr) //�Ҵ� �����ϴ� ��
	{
		delete[] adr;
	}
};

int main()
{
	Point* ptr = new Point(3, 4); //static���� �ۿ� ������� ����.
	
	//��� �Լ��� ��ü�� ������ ������ ȣ���� �� �� �ִµ�, new �� delete�����ε������ڴ� static �Լ� ���� ���̶� �����ϴ�. 
	//Point p; �̷��� ��ü�� ������ 
	return 0;
}