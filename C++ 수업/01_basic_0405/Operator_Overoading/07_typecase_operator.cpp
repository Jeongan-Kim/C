#include <iostream>
//�� ��ȯ ������
using namespace std;

class Won
{
	int value = 0;
public:
	Won(int value = 0) :value(value) {}

	operator int()
	{
		return value;
	}
};

void Print(int val)
{
	cout << val << endl;
}

class Point
{
private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

public:
	Point(float x, float y, float z)
		:x(x), y(y), z(z)
	{}

	operator float* ()
	{
		return &x;
	}
};

void PrintPoint(float points[3])
{
	cout << points[0] << endl;
	cout << points[1] << endl;
	cout << points[2] << endl;
}
int main()
{
	Won w(10);
	Print(w); 
	//��ü ����Ϸ��� �Ҷ� �ڷ����� ���� �ʾ� ������ ������. �̷��� Ŭ���� ���ο��� Ŭ���� ��ü�� �� ��ȯ����.

	Point p(1.0f, 1.0f, 3.0f);
	PrintPoint(p);
	return 0;
}


//���� �ð� ���ϱ�

class Hour
{

};

class Minute
{

};

class Second
{

};

class MilliSecond
{

};

//���ο��� ����Ʈ�� ������� 
/*
Hour h(1);
PrintHour(h); //1�ð�
PrintMinute(h); //60
PrintSecond(h); //60*60
PrintMilliSecond(h); //60*60*60
*/

//������� ����� QWER ������ ��ǥ ���߱�.