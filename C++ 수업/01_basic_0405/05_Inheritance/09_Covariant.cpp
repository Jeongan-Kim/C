#include <iostream>
//공변 반환형(?)
using namespace std;

class A
{

public:
	virtual A* GetThisPointer() //나를 반환하는 것
	{ 
		cout << "A" << endl; 
		return this; //나를 가리키는 주소 반환
	}

	void Print() { cout << "A" << endl; }
};

class B :public A
{
public:
	B* GetThisPointer() override //B포인터는 A의 성질도 가지고 있다(?)
	{
		cout << "B" << endl;
		return this; //A클래스에서 오버라이딩을 했어도 A 멤버 함수가 사라지는 것이 아니기 떄문에 리턴값이 달라도 오류가 안난다.
	}

	void Print() { cout << "B" << endl; }
};

int main()
{
	B b;

	b.Print();
	cout << "Address : " << b.GetThisPointer() << endl; //B클래스의 객체 주소가 찍힘
	cout << "typeid : " << typeid(b.GetThisPointer()).name() << endl; //해당 자료형이 뭔지 문자열로 반환해줌

	/*
	B
	B
	Address : 000000D3CD8FF988
	typeid : class B * __ptr64
	*/
	A& ref = b;//ref자체는 A의 것이지만 b로 초기화를 해서, 값은 B의 주소가 나오지만 타입이나 소속은 A(?)
	ref.Print();
	cout << "Address : " << ref.GetThisPointer() << endl;
	cout << "typeid : " << typeid(ref.GetThisPointer()).name() << endl;

	/*
	A
	B
	Address : 000000D3CD8FF988
	typeid : class A * __ptr64
	*/
	return 0;
}