#include <iostream>

using namespace std;

class Vehicle
{
	static int count; //��� Ŭ������ �����ϸ鼭 count�� ������ų �� �ְ� static���� ����.

public:
	Vehicle()
	{
		count++;
		if (5 < count)
		{
			cout << "�̵� ���� ��ü ���� 5�� �ʰ�" << endl;
		}
	}

//	static int getCount() { return count; } //count ���� �����ڿ��� ���� �ǵ帮�⺸�ٴ� ���� ��ü ���������� getCount�Լ��� �ᵵ �ȴ�.(���� ����)

	virtual void movement() abstract; //���� ���� �Լ�

	virtual ~Vehicle() { count--; } //��ü�� �Ҹ�Ǹ� count�� ���ҵǰԲ�.
};

int Vehicle::count = 0;

class airplane :public Vehicle
{
public:
	airplane() : Vehicle() {}

	void movement() { cout << "����� �̵�" << endl;}
};

class ship :public Vehicle
{
public:
	ship() : Vehicle() {}

	void movement() { cout << "�� �̵�" << endl; }
};

class car :public Vehicle
{
public:
	car() : Vehicle() {}

	void movement() { cout << "�� �̵�" << endl; }
};

int main()
{
	//���� ���� �Լ��� �ڽ� Ŭ�������� ���ǰ� �Ǹ�, �ڽ� Ŭ���� ��ü�� �����ɶ� �θ� ��ü�� ������ ��������.
	//Vehicle v;�Ұ�
	ship sh;
	airplane air;
	car car1;
	car car2;
	car car3;
	car car4;

	sh.movement();
	air.movement();
	car1.movement();
	car2.movement();
	car3.movement();
	car4.movement();


	return 0;
}