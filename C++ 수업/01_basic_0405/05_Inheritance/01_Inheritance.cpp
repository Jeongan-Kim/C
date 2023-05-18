#include <iostream>
//상속의 기본
using namespace std;

class Mother
{
private: //프리빗 변수는 상속도 안됨.
	int a;

public:
	auto GetA() const
	{
		cout << "Mother" << endl;
		return a;
	}

	void SetA(const int& a) { this->a; }

protected: //부모 자식만 쓸 수 있는 변수들
	int b;
	int c;
};

class Child : public Mother //마더 클래스의 멤버들을 받음
{
	int b; //전역 멤버 변수
public:
	auto GetA() const
	{
//		a; //마더 프리빗 변수는 사용 불가능
		c; //마더에 있는 것 사용 가능
		b; //child 변수 b
		Mother::b; //마더 클래스의 변수 b

		cout << "Child" << endl;
		return Mother::GetA(); //child 의 겟 함수가 아니라 마더의 겟 함수
	}
};
int main()
{
	Child c;
	c.SetA(10); //child 클래스에는 SetA함수가 없지만 부모 클래스에 있기에 호출이 가능

	c.GetA(); //child클래스의 멤버 함수(이름이 같으므로 부모 클래스의 멤버함수 GetA는 하이딩됨.)
	c.Mother::GetA(); //부모 클래스의 GetA를 호출하려면 명시적으로 이름을 알려줘야 함.

	return 0;
}