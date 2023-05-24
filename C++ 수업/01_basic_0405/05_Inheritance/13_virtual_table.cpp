#include <iostream>
//가상함수 테이블(클래스마다 한 개만 가지고 있음, 여러 객체가 있어도 하나를 공유하는 것, 오버라이딩되면 갱신되는 형태)
//함수 포인터 배열의 형태. 멤버 함수 호출에 사용되는 일종의 데이터이기때문에 메모리가 있다(?)
//가상함수 테이블에서 주소를 저장하는 함수포인터가 동적 바인딩 형식임.
/*
    class Base                                     Base my_base;
    *__vfptr         --------------------------->  -Base virtual-table
    virtual func1()  <---------------------------  -func1()
    virtual func2()  <---------------------------  -func2()
                 ^
                 |
                 \
                  \________________________________
                                                   \
    class Derived : public Base                     \   Derived my_derived;
    *__vfptr (inherited) --------------------------->\  -Derived virtual_table
    virtual func1()      <----------------------------\--func1() //오버라이딩 하지 않을 멤버 함수에는 virtual 키워드를 붙이지 말자.(공간 낭비)
                                                       \-func2()
*/

using namespace std;

class A
{
	int a;

public:
	void func() {};
};

class Base
{
public:
    virtual void func1() { cout << "func1" << endl; }
    virtual void func2() { cout << "func2" << endl; }
};

class Derived : public Base
{
public:
    virtual void func1() { cout << "Derived::func1" << endl; } //부모 클래스 오버라이딩
    void func3() { cout << "func3" << endl; } //자식 클래스만의 함수
};

int main()
{
	{
		A a;
		a.func();

		A aa;
		aa.func();

		//클래스의 함수는 코드 영역에 존재하다가, 객체들이 생기면 모두가 공유하게 된다.
		//a::func();//그래서 이렇게는 불가능했었음
	}

    Base* bptr = new Base();
    bptr->func1();

    Derived* dptr = new Derived();
    dptr->func1();
    dptr->func2();
    dptr->func3();

	return 0;
}