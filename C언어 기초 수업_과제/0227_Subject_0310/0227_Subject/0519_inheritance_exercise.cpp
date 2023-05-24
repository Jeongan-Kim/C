#include <iostream>

using namespace std;
/*
* ���α׷� �����
	Vehicle -> �Լ� movement�� ������ Vehicle(�θ�Ŭ����) ����
	�̸� ��� �޴� airplane, car, ship�� ���� movement (�������̵�)�Լ��� ȣ������ ��
	(����� �̵�), (���� �̵�), (���� �̵�) �̷� ������ ��µǰ� �����,
	��� �̵� ������ ������ 5�� �ʰ��� ���,
	��ü ���� �� "�̵� ���� ���� 5�� �ʰ��մϴ�"�� ���.
*/

class Vehicle
{

	string name;

public:
	Vehicle() {} //�⺻ ������
	Vehicle(string name) : name(name) 
	{
		if (count >= 5)
		{
			cout << "�̵� ���� ���� 5�� �ʰ��Ͽ� ��ü�� ������ �� �����ϴ�." << endl;
			exit(0); //�̵� ���� 5 �ʰ� ��, ���� �޼��� ��� �� ���α׷� ����
		}
		count++;
	}
	virtual void movement() {}

protected:
	static int count;
};

int Vehicle::count = 0;

class Car :public Vehicle
{
public:
	Car(string name) : Vehicle(name) {}
	void movement() override 
	{
		cout << "���� �̵�" << endl;
		cout << "�̵� ������ ���� : " << Vehicle::count << endl << endl;
	}
};

class Airplane :public Vehicle
{
public:
	Airplane(string name) : Vehicle(name) {}
	void movement() override
	{
		cout << "����� �̵�" << endl;
		cout << "�̵� ������ ���� : " << Vehicle::count << endl << endl;
	}
};

class Ship :public Vehicle
{
public:
	Ship(string name) : Vehicle(name) {}
	void movement() override
	{
		cout << "���� �̵�" << endl;
		cout << "�̵� ������ ���� : " << Vehicle::count << endl << endl;
	}
};

class Subway :public Vehicle
{
public:
	Subway(string name) : Vehicle(name) {}
	void movement() override
	{
		cout << "����ö �̵�" << endl;
		cout << "�̵� ������ ���� : " << Vehicle::count << endl << endl;
	}
};

int main()
{
	Car("car1").movement(); //1 
	Airplane("airplane1").movement(); //2
	Ship("ship1").movement(); //3
	Subway("subway1").movement(); //4
	Car("car2").movement(); //5
	Airplane("airplane2").movement(); //6(�������� ��)

	return 0;
}