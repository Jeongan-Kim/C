#include <iostream>
//다형성 : 오버로딩, 오버라이딩이 있음.
//오버라이딩 : 부모클래스에서 물려 받은 것을 재정의하는 것.(함수 이름과 매개변수 등이 같은데 다른 기능을 함. 부모클래스의 멤버함수가 하이딩됨. 오버로딩된 것들도 다 가려짐)
using namespace std;

class A /*final*/ // final : 더이상 이 클래스를 상속하지 않게 하는 키워드(함수에만 써서 특정 함수만 상속 불가하게 할 수도 있음)
{
public:
	virtual void Print(int x) { cout << "A" << endl; } //virtual 함수 : 가상 함수 -> 상속해줄 클래스에서 오버라이딩할 것을 명시해 주는 것.(안써도 상관은 없음)
	//그래도 쓰는 이유는 자식 클래스에서 오버라이딩할때 실수로 같게 쓰지 않았을 때 오류처리해주는 것.
	//최상위 부모클래스에서만 써주면 됨,(부모 -> 자식 1-> 자식2, 이럴때 자식 1에서는 자식 2로 상속할떄 virtual을 안써도 된다는 의미) 

	int i = 0;
};

class B /*final*/:public A
{
public:
	void Print(int x) override /*final*/ { cout << "B" << endl; } //상속 받은 함수를 
	//override를 붙이면 오버라이딩한다는 것을 명시적으로 보여주고 원본 함수가 있는지 확인도 할 수 있음, 생략 가능
};

class C : public B
{
public:
	void Print(int x) override { cout << "C" << endl; }
};

int main()
{
	A a;
	B b;

	a.Print(1);
	b.Print(2);


	//가상함수 배우면서 더 자세히 알아볼 것임.
	A* aptr = new B();
//	B* bptr = aptr; //이렇게는 불가능. (upcasting 문제)(함수 오버라이딩할때 생기는 문제)

	B* bb = new B();
	A* aa = bb; 
	return 0;
}