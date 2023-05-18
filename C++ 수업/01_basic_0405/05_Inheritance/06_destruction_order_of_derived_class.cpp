#include <iostream>

using namespace std;
//소멸자가 자식 클래스에서 어떤 순서로 만들어지는지 알아보자

class A //클래스 크기는 4바이트
{
	int a;
public:
	A() { cout << "A constructor" << endl; }
	~A() { cout << "A distructor " << endl; }
};

class B : public A
{   //A를 상속 받았으니 int a도 있다고 생각하고 클래스 크기는 더블 두개로 16바이트(내부 단편화 문제, 패딩(padding) 바이트 방식으로 저장하기 때문에)
	//메모리 한 줄에 앞에서 채워 저장하고 뒤에 남는 부분을 패딩이라고 함
	double b;
public:
	B() { cout << "B constructor" << endl; }
	~B() { cout << "B distructor " << endl; }
};


int main()
{
	B b;
	//생성은 부모가 먼저, 소멸은 자식이 먼저(LIFO 형식)
	/*
		A constructor
		B constructor
		B distructor
		A distructor
	*/

	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	return 0;
}

struct S //48바이트( 줄이면 32바이트까지 줄일 수 있다)(최대한 효율적으로 작은 것 부터 쓰도록 연습하자)
{
	char c1;
	double d1;
	int i1;
	int i2;
	short s1;
	short s2;
	double d2;
	char c2;
	char c3;
};