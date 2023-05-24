#include <iostream>
//함수가 호출될때 함수 주소를 연결해 주는 역할(바인딩)
/*
	static binding(정적 바인딩, Early binding) : 컴파일 타임에 호출될 함수가 연결됨. 빠르지만 유연하지 않음.
	dynamic binding(동적 바인딩, late binding) : 런타임에 호출될 함수가 연결됨. 느리지만 유연. 객체 지향 특성 중 다형성의 특징으로도 봄
*/

using namespace std;

//일반적인 연산 함수를 가지고 이해해보자.
int add(int x, int y) { return x + y; }
int subract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }

int main()
{
	//정적 바인딩(있는 그대로 쓸 함수를 호출해서 사용하는 방식)
	int x, y;
	cin >> x >> y;
	int op;
	cout << "0 : add, 1 : subtract, 2 : multiply" << endl;
	cin >> op;

	int result;
	switch(op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subract(x, y); break;
	case 2: result = multiply(x, y); break;
	}

	cout << result << endl;


	//동적 바인딩(전부 다 저장해 놓고, 주소 연결 자체가 실행 타임에 됨)
	//함수 포인터에 넣어 놓고, 필요할떄 가져다 씀

	int(*funcptr)(int, int) = nullptr;
	//하나의 함수 포인터에 여러 함수를 바꿔 넣어가며 쓸 수 있어서 편리함.

	switch (op)
	{
	case 0: funcptr = add; break;
	case 1: funcptr = subract; break;
	case 2: funcptr = multiply; break;
	}

	return 0;
}