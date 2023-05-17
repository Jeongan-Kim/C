#include <iostream>

using namespace std;

/*
L-value R-value

int a = 10;
L-value : 나중에 다시 접근이 가능한 값
R-value : 식이 끝나면 접근이 불가능한 값
*/

int Test1(int& a) //원본값이 복사되어 들어가서 원본값을 바꾸겠다.(copy)
{
	return a; //원본 값이 수정됨.
}

int Test2(int&& a) //원본값이 없으므로 이 안에서만 쓰고 말겠다.(move)
{
	return a;
}

int main()
{
	int val = 5;
	int& r = val; //r-value reference, &는 별명이므로 원본이 어딘가 있다는 의미, 공간도 없고 같은 것을 가리킬 뿐(?), 포인터랑 같은 의미라고 보면 됨
	int* ptr = &val;
	//reference는 공간이 안잡히고 할당도 안해줘도 되지만 포인터와 같은 역할을 한다는 게 중요함.

	r = 10;

	cout << val << endl;
	cout << r << endl;

	//int& r2; 불가능
	//int& r3 = 10; 불가능

	const int& r4 = 10; // 상수화 되어서 다시 r4에 접근할 일이 없기에 가능

	//&&은 &두개의 의미가 아니라 &&처럼 생긴 것. &와 &&는 프로그래머의 의도를 표현하기 위해 사용함.

	int&& rr = 10; //const int rr이라고 보면됨.

	return 0;
}
