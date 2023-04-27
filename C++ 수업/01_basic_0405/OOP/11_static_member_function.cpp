#include <iostream>

using namespace std;

class Test
{
	int value;
	static int value2;

public:
	Test() {}
	void Temp1() { this->value; }
	void Temp1() const { this->value; } //상수함수라서 오버로딩 가능

	//static void Temp2() { this->value; } //static함수에서는 this call불가능. 단순히 이 클래스 안에 포함되었을 뿐.
	//그래서 같은 종류로 단순히 포함되기만한 변수만 사용 가능.
	static void Temp2() { value2; }

	int test;

};
int main()
{
	//Test::Temp1(); 함수를 호출할떄, 이런 방식은 불가능
	Test t1;
	t1.Temp1(); //이렇게 했어야 했는데,

	Test::Temp2(); //static함수는 이렇게 호출 가능. 일반 함수 취급을 한다고 생각하면 됨.
	//그래서 함수 포인터도 가능
	void (*ptr1)() = Test::Temp2;
	//void (*ptr2)() = Test::Temp1; //this call형식이기에 소유자를 알 수 없어서 이건 불가능

	/*
		멤버 포인터 : 실체를 만들고 사용해야 한다는 주의점이 있음.
	*/

	//변수의 경우.
	int Test::* ptr2 = &Test::test; //test의 포인터. 지금은 아직 실체가 없음.
	t1.*ptr2 = 10; //test를 t1라는 실체 안의 변수라고 알려주는 것.


	//함수의 경우.
	void(Test:: * ptr3)() = &Test::Temp1;
	(t1.*ptr3)();

	return 0;
}