#include <iostream>
//형 변환 연산자
using namespace std;

class Won
{
	int value = 0;
public:
	Won(int value = 0) :value(value) {}

	operator int()
	{
		return value;
	}
};

void Print(int val)
{
	cout << val << endl;
}

class Point
{
private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

public:
	Point(float x, float y, float z)
		:x(x), y(y), z(z)
	{}

	operator float* ()
	{
		return &x;
	}
};

void PrintPoint(float points[3])
{
	cout << points[0] << endl;
	cout << points[1] << endl;
	cout << points[2] << endl;
}
int main()
{
	Won w(10);
	Print(w); 
	//객체 출력하려고 할때 자료형이 맞지 않아 원래는 오류남. 이럴때 클래스 내부에서 클래스 자체를 형 변환해줌.

	Point p(1.0f, 1.0f, 3.0f);
	PrintPoint(p);
	return 0;
}


//과제 시간 구하기

class Hour
{

};

class Minute
{

};

class Second
{

};

class MilliSecond
{

};

//메인에서 프린트로 찍었을때 
/*
Hour h(1);
PrintHour(h); //1시간
PrintMinute(h); //60
PrintSecond(h); //60*60
PrintMilliSecond(h); //60*60*60
*/

//리듬게임 만들기 QWER 눌러서 음표 맞추기.