#include <iostream>

using namespace std;
//C와 C++의 함수 호출 방식이 다름.
//C++에서는 함수를 중복해서 쓸 수 있으나 매개변수로 차별을 줘야 함, 인자 타입을 보고 함수를 찾아주는 시스템
int add(int a, int b) {	return a + b;}
float add(float a, float b) {return a + b;}
int add(int a) { return a + 1; }
int add(int a, int b, int c) { return a + b + c; }

using integer = int; //int a == integer a
//integer add(integer a, integer b) { return a + b; } 위 첫번째 함수와 같은 모양이니까 쓸 수 없음.

void output(int value) {}
void output(unsigned int value){}
void output(float value){}

int main()
{ //여러 자료형, 함수를 쓸때 자료형을 계산하기 귀찮으니 auto가 잘 쓰임
	auto result1 = add(10, 20);
	auto result2 = add(10.1f, 20.0f);
	auto result3 = add(10, 20, 30);

	output(1); //모호성 오류가 생김(int 인지 unsigned 인지 모호하니까)
	output(1.0f);

	output('c'); //자신과 일치하는 함수를 찾지 못하면 형 변환을 해서 비슷한 걸 찾음
				//char, unsigned char, short, int 순으로 비슷한걸 찾음.

	return 0;
}