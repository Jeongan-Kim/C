#include <iostream>

using namespace std;

class Vehicle
{
	static int count; //모든 클래스가 공유하면서 count를 증가시킬 수 있게 static으로 선언.

public:
	Vehicle()
	{
		count++;
		if (5 < count)
		{
			cout << "이동 수단 개체 수가 5를 초과" << endl;
		}
	}

//	static int getCount() { return count; } //count 값을 생성자에서 직접 건드리기보다는 좀더 객체 지향적으로 getCount함수를 써도 된다.(취향 차이)

	virtual void movement() abstract; //순수 가상 함수

	virtual ~Vehicle() { count--; } //객체가 소멸되면 count를 감소되게끔.
};

int Vehicle::count = 0;

class airplane :public Vehicle
{
public:
	airplane() : Vehicle() {}

	void movement() { cout << "비행기 이동" << endl;}
};

class ship :public Vehicle
{
public:
	ship() : Vehicle() {}

	void movement() { cout << "배 이동" << endl; }
};

class car :public Vehicle
{
public:
	car() : Vehicle() {}

	void movement() { cout << "차 이동" << endl; }
};

int main()
{
	//순수 가상 함수가 자식 클래스에서 정의가 되면, 자식 클래스 객체가 생성될때 부모 객체도 생성이 가능해짐.
	//Vehicle v;불가
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