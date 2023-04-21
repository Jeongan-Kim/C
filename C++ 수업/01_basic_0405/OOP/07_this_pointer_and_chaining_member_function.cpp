#include <iostream>

using namespace std;

/*
	this pointer : 객체 자신을 가리키는 용도로 사용되는 포인터.
	self reference형태.
	자료형이 정해져 있지 않음
*/

//class Test
//{
//	int num;
//
//public:
//	Test(int n) : num(n)
//	{
//		cout << "num : " << num << endl;
//		cout << "num address : " << &num << endl; //같은 주소가 나옴.
//		cout << "this address : " << this << endl; // Test 자기 자신을 가리키는 포인터
//	}
//
//	void ShowTestData()
//	{
//		cout << num << endl;
//	}
//
//	Test* GetThisPointer() //이렇게 반환하기도 함.
//	{
//		return this;
//	}
//};
//
//class Test2
//{
//	int a;
//	int b;
//	int c;
//
//public:
//	Test2() {}
//	~Test2() {} //기본적으로 들어가 있지만 안쓰더라도 이렇게 써주는 경우도 있음. 쓸일이 있을 수 있으므로.,
//
//	auto /*this call*/ GetA()
//	{
//		cout << this << endl;
//		return a;
//	}
//
//	//void SetA(const int& a) { a = a; } a가 어떤 건지 구분이 안가서 이렇게 못 쓴다고 했음
//	void SetA(const int& a) { this->a = a; } //그래서 this 포인터를 이용해서 이렇게 쓸 수 있음.
//};
//
//int main()
//{
//	Test t1(100);
//	Test* ptr1 = t1.GetThisPointer(); //this를 저장한 것.
//	cout << ptr1 << endl;
//	ptr1->ShowTestData();
//
//
//	Test t2(200);
//	Test* ptr2 = t2.GetThisPointer(); //this를 저장한 것.
//	cout << ptr2 << endl;
//	ptr2->ShowTestData();
//
//
//	return 0;
//}


#pragma region chaining member function

//자기 자신을 연쇄적으로 호출하는 함수

class Calc
{
	int value;

public:
	Calc(int value) : value(value) {}

	//void Add(int value) { this->value += value; }
	//void Sub(int value) { this->value -= value; }
	//void Mul(int value) { this->value *= value; }
	//void Div(int value) { this->value /= value; }
	//void Mod(int value) { this->value %= value; }

	//연쇄적으로 편리하게 쓰기 위해, 반환값이 나 자체인 셀프 리턴 형식으로 함수를 적는다.
	Calc& Add(int value) { this->value += value; return *this; } //*this 참조값을 통해 나 자신의 주소 안으로 들어온다는 의미.
	Calc& Sub(int value) { this->value -= value; return *this; }
	Calc& Mul(int value) { this->value *= value; return *this; }
	Calc& Div(int value) { this->value /= value; return *this; }
	Calc& Mod(int value) { this->value %= value; return *this; }
};

int main()
{
	//Calc calc(10);
	//calc.Add(5);
	//calc.Sub(2); // 원래는 이런식으로 여러 문장을 써야 함.

	cout << "a" << "b" << "c" << "d" << "e" << endl; //이것도 일종의 chaining

	Calc calc(10);
	calc.Add(5).Div(2).Mod(3).Mod(4).Sub(1);

	//익명개체를 호출해서 연쇄적 계산하는 것도 가능(이름 선언을 안해준다는 것)
	//ananimous object
	Calc(20).Add(1).Add(2); //그러나 이것은 1회용이고 사용은 불가능함. 이름이 없기 때문에.

	return 0;
}
#pragma endregion


/*
   <과제>

   C++로 만들기
   화살표 타이핑 게임
   주어진 시간 안에 화살표 차례대로 누르기
   
*/