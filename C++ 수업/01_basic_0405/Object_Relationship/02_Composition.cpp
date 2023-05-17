#include <iostream>
//구성 관계
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
	Point2D position1; // 다른 클래스지만 이 클래스가 소멸되면 같이 사라짐.
	Point2D* position2;

public:
	//composition
	Monster(int x, int y)
	{
		position1.x = x; //클래스 전체와 다른 클래스 부분이 엮임.
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
	Monster mon1(10, 20);  // 다른 클래스지만 이 클래스가 소멸되면 position1도 같이 사라짐.

	Point2D point;
	Monster mon2(&point); //이렇게 하면 point 객체는 사라지지 않게 됨.

	return 0;
}