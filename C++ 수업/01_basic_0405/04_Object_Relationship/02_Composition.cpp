#include <iostream>
//���� ����
using namespace std;

class Point2D
{
public:
	int x;
	int y;
};

class Monster
{
	string name;
	Point2D position1; // �ٸ� Ŭ�������� �� Ŭ������ �Ҹ�Ǹ� ���� �����.
	Point2D* position2;

public:
	//composition
	Monster(int x, int y)
	{
		position1.x = x; //Ŭ���� ��ü�� �ٸ� Ŭ���� �κ��� ����.
		position1.y = y;
	}
	//Aggregation
	Monster(Point2D* point)
	{
		this->position2 = point;
	}
};

int main()
{
	Monster mon1(10, 20);  // �ٸ� Ŭ�������� �� Ŭ������ �Ҹ�Ǹ� position1�� ���� �����.

	Point2D point;
	Monster mon2(&point); //�̷��� �ϸ� point ��ü�� ������� �ʰ� ��.

	return 0;
}