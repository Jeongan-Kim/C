#include <iostream>

using namespace std;
/*
* 프로그램 만들기
	Vehicle -> 함수 movement를 가지는 Vehicle(부모클래스) 정의
	이를 상속 받는 airplane, car, ship이 각각 movement (오버라이딩)함수를 호출했을 때
	(비행기 이동), (차량 이동), (수상 이동) 이런 식으로 출력되게 만들고,
	모든 이동 수단의 총합이 5를 초과할 경우,
	객체 생성 시 "이동 수단 수가 5를 초과합니다"를 출력.
*/

class Vehicle
{

	string name;

public:
	Vehicle() {} //기본 생성자
	Vehicle(string name) : name(name) 
	{
		if (count >= 5)
		{
			cout << "이동 수단 수가 5를 초과하여 객체를 생성할 수 없습니다." << endl;
			exit(0); //이동 수단 5 초과 시, 오류 메세지 출력 후 프로그램 종료
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
		cout << "차량 이동" << endl;
		cout << "이동 수단의 총합 : " << Vehicle::count << endl << endl;
	}
};

class Airplane :public Vehicle
{
public:
	Airplane(string name) : Vehicle(name) {}
	void movement() override
	{
		cout << "비행기 이동" << endl;
		cout << "이동 수단의 총합 : " << Vehicle::count << endl << endl;
	}
};

class Ship :public Vehicle
{
public:
	Ship(string name) : Vehicle(name) {}
	void movement() override
	{
		cout << "수상 이동" << endl;
		cout << "이동 수단의 총합 : " << Vehicle::count << endl << endl;
	}
};

class Subway :public Vehicle
{
public:
	Subway(string name) : Vehicle(name) {}
	void movement() override
	{
		cout << "지하철 이동" << endl;
		cout << "이동 수단의 총합 : " << Vehicle::count << endl << endl;
	}
};

int main()
{
	Car("car1").movement(); //1 
	Airplane("airplane1").movement(); //2
	Ship("ship1").movement(); //3
	Subway("subway1").movement(); //4
	Car("car2").movement(); //5
	Airplane("airplane2").movement(); //6(오류나야 함)

	return 0;
}