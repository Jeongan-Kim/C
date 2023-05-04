#include <iostream>

using namespace std;

//* ->

class Number
{
	int num;

public:
	Number(int n) : num(n) {}

	void ShowData()
	{
		cout << num << endl;
	}

	//-> :객체 자체의 주소값을 반환
	Number* operator->()
	{
		return this;
	}

	//* :값을 찍어줌
	Number& operator*()
	{
		return *this;
	}

};

int main()
{
	Number num(20);
	num.ShowData();

	(*num) = 30; //num 자체를 포인터 형태로 쓸 수 있음.
	num->ShowData(); //num.operator->()->ShowData();

	//사실 이런 형태
	num.operator*() = 30;
	num.operator*().ShowData();


	return 0;
}