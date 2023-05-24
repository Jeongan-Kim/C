#include <iostream>
//가상 소멸자
using namespace std;

class Base
{
public:
	Base() { cout << "Base()" << endl; }
	virtual ~Base() { cout << "~Base()" << endl; } // 자식 클래스의 소멸자가 은닉되지 않고 호출되지 않도록 virtual 키워드 붙여줘야 함.
};

class Derived : public Base
{
	int* arr = nullptr; //포인터를 만들어서 동적할당을 하는 클래스를 만들 것임

public:
	~Derived() 
	{
		//TODO : 동적해제 작업
		cout << "~Derived()" << endl;
	}
};

int main()
{
	Base b;

	Base* base = new Derived; //부모클래스 포인터로 자식 클래스를 선언해 줌(업캐스팅 형태)
	//이럴 경우 자식 클래스의 소멸자가 은닉되어 동적할당 해제 작업을 안해주게 됨. 
	//-> 부모클래스의 소멸자를 가상 소멸자로 만들어 주는 게 좋음.
	//클래스를 상속할 생각이면 소멸자에 virtual 키워드를 붙여주자.
	delete base; // 객체 자체를 동적할당한 것이므로 delete는 별도로 해주는 것.

	/*
	Base()
	Base()

	~Base()
	~Base()

---------------

	Base()
	Base()
	~Derived()
	~Base()
	~Base()
	*/
	return 0;
}