#include <iostream>

using namespace std;

//앞서 배운 것 복습도 같이
//가상함수 테이블이 따로 생성되서 오버라이딩 정보를 저장됨.
class A
{
public:
	void Print() { cout << "A" << endl; }
	virtual void Print1() { cout << "A1" << endl; } //가상함수 테이블에 차례대로 virtual 함수의 주소가 저장됨.
	virtual void Print2() { cout << "A2" << endl; }
	virtual void Print3() { cout << "A3" << endl; }
	virtual void Print4() final { cout << "A4" << endl; }
};

class B : public A
{
public:
	void Print() { cout << "B" << endl; }
	virtual void Print1() { cout << "B1" << endl; } //가상함수의 오버라이딩 형태이므로, A의 print1의 주소를 덮어 씌우고 저장됨.(주소가 같아짐)
	virtual void Print2() { cout << "B2" << endl; }
	virtual void Print3() final { cout << "B3" << endl; }
//	virtual void Print4() final { cout << "B4" << endl; }
};

class C : public B
{
public:
	void Print() { cout << "C" << endl; }
	virtual void Print1() { cout << "C1" << endl; }
	virtual void Print2() final { cout << "C2" << endl; }
//	virtual void Print3() final { cout << "B3" << endl; }
//	virtual void Print4() final { cout << "B4" << endl; }
};

class D : public C
{
public:
	void Print() { cout << "D" << endl; }
	virtual void Print1() { cout << "D1" << endl; }
//	virtual void Print2() final { cout << "D2" << endl; }
//	virtual void Print3() final { cout << "B3" << endl; }
//	virtual void Print4() final { cout << "B4" << endl; }
};


int main()
{
	A a;
	a.Print1();

	B b;
	b.Print1();

	C c;
	c.Print1();

	D d;
	d.Print1();

	cout << endl;

	A& refB = b; //최상위 부모 클래스를 이용해서 자식 클래스의 참조자를 만듬
	A& refC = c;
	A& refD = d;

	cout << "###### A" << endl;

	a.Print();
	a.Print1();
	a.Print2();
	a.Print3();
	a.Print4();


	cout << "###### B" << endl;

	refB.Print(); //virtual이 붙지 않아서 부모 클래스(최상위)의 함수가 찍힘
	refB.Print1();
	refB.Print2();
	refB.Print3();
	refB.Print4(); //final로 막혀서 직전 부모클래스의 값이 찍힘, 가장 마지막에 오버라이딩한 멤버 함수가 찍힘.

	cout << "###### C" << endl;

	refC.Print();
	refC.Print1();
	refC.Print2();
	refC.Print3();
	refC.Print4();

	cout << "###### D" << endl;

	refD.Print();
	refD.Print1();
	refD.Print2();
	refD.Print3();
	refD.Print4();

	//이유 : 가상함수의 주소가 같아서 그렇다. 가상함수는 가상함수 테이블(멤버 함수의 주소를 오버라이딩 함수 주소로 교체 해주는 등의 일을 함)을 이용함.

	D d1;
	D d2;
	//디버깅 왼쪽에 위치 찍고 F11누르면서 하나씩 확인할 수 있고, 자동 및 로컬 탭에서 주소 값 확인 가능.
	//d1과 d2의 주소가 같은 것을 확인할 수 있다.
	return 0;
}

//리듬게임 만들기(다시)
/*
* 프로그램 만들기
	Vehicle -> 함수 movement를 가지는 Vehicle(부모클래스) 정의
	이를 상속 받는 airplane, car, ship이 각각 movement (오버라이딩)함수를 호출했을 때
	(비행기 이동), (차량 이동), (수상 이동) 이런 식으로 출력되게 만들고,
	모든 이동 수단의 총합이 5를 초과할 경우,
	객체 생성 시 "이동 수단 수가 5를 초과합니다"를 출력.

*/

//class Vehicle
//{
//	virtual void movement() {}
//};
//
//class Car :public Vehicle
//{
//	void movement() overriding {(수상이동, 등등 출력) }
//};
//
//int main()
//{
//
//	a.movement(); -> 다섯 번 찍히면 오류 찍게 하기.(생성 안되게도 해보고, 안되면 경고만 찍히게.)
//
//	return 0;
//}