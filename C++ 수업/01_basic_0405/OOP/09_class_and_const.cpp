#include <iostream>
//const 멤버 알아보기.

using namespace std;

class Data
{
	int value1;
	mutable int value2;

public:
	Data() : value1(0) {}

	int& GetValue() { cout << "not const" << endl; return value1; }

	//int& GetValue1() const { cout << " comnst"; return value1; } //함수 자체에 const가 붙은 경우 const가 붙지 않은 변수를 쓰려고 하면 오류가 남.
	//우회적으로 수정할 수 있기 때문에.(?)
	const int& GetValue1() const { cout << "const"; return value1; } //오버로딩 함수. 상수함수라는 구분이 가능해서 .

	//void SetValue(int value) const { this->value1 = value; } //value가 상수화 돼서 수정 불가. 이때 수정할 수 있게 사용하는 키워드(mutable)가 있음
	void SetValue(int value) const { this->value2 = value; }
	const void SetValue2(int value) const { this->value2 = value; }
};

void Print(const Data& data) //수정을 막기 위해 const를 씀.
{
	data.GetValue1(); //이렇게 가져다가 쓰기만 할때 상수함수를 씀.
}

int main()
{
	Data data1;
	const Data data2; //const함수만 호출할 수 있는 함수 객체.
	
	data1.GetValue();
	//data2.GetValue(); 불가능.
	data2.GetValue1();

	Print(data2);

	return 0;
}