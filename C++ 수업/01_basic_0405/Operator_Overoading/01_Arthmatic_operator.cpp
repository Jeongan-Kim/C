#include <iostream>
//산술연산자 
//연산자 오버로딩 시 주의 사항 : 의도를 벗어나는 연산은 하지 않는 게 좋음. 우선순위는 변하지 않음.(+보다 *가 우선)

using namespace std;

//#pragma region 1. 전역함수에 의한 연산자 오버로딩
//class Won
//{
//public:
//	Won(int value) : value(value){}
//
//	int GetValue() const { return value; }
//
//private:
//	int value;
//
//	friend int operator+(const Won& lhs, const Won& rhs); //private지만 friend가 붙어서 전역함수처럼 쓰임, lhs 좌항, rhs 우항
//
//	//생성자를 통해 만들어줄 수도 있음
//	friend Won operator-(const Won& lhs, const Won& rhs) //함수 정의부를 클래스 안에서 써줘도 됨.
//	{
//		return lhs.value - rhs.value;
//	}
//};
//
//int main()
//{
//	Won l(10), r(10);
//
//	int result = l + r;
//	cout << result << endl;
//
//	Won result2(l - r); //객체 생성과 동시에 해도 되지만 결과는 getvalue로 가져와야 함
//	cout << result2.GetValue() << endl;
//
//	return 0;
//}
//
//int operator+(const Won& lhs, const Won& rhs)
//{
//	return lhs.value + rhs.value;
//}
//
///*
//	operator+(a, b);
//*/
//
//#pragma endregion

#pragma region 2. 멤버함수에 의한 연산자 오버로딩

class Won
{
public:
	Won(int value) : value(value) {}

	int GetValue() const { return value; }

	//l.opertaor+(r) 이런 방식이라고 이해만 하자.(진짜 이런 형태는 아님)
	int operator+(const Won& rhs)
	{
		return value + rhs.value;
	}
	
	Won operator-(const Won& rhs)
	{
		return value + rhs.value;
	}

private:
	int value;
};

int main()
{
	Won l(10), r(10);
	int result = l + r;
	cout << result << endl;

	Won result2 = l - r;
	cout << result2.GetValue() << endl; // 필기 확인하기

	return 0;
}
#pragma endregion

/*
연산자 오버로딩을 통해 만들어오기- 과제(3좌표가 각각 연산되도록) 예) (x1 + x2, y1 + y2, z1 + z2)

	단항 연산자 +, +vector = vextor, -vextor
	이항 연산자 +, vector + vector // + - * /
	이항 연산자 *, vector * 3
	증감 연산자
	- 전위 ++vector
	- 후위 vector++

*/

#pragma region 산술 연산자 오버로딩
class Vector
{
public:
	Vector(int x, int y, int z) : x(x), y(y), z(z) {}

	Vector operator+() const
	{
		//return Vector{ x, y, z };
		return *this; //this는 나 자신의 포인터(주소)이므로 *붙여서.
	}

	//전위, 후위
	Vector& operator++()
	{
		x += 1; //이렇게 쓰거나
		++y; //이렇게 쓰면 됨
		++z;
		return *this;
	}

	Vector& operator++(int) //구별하기 위해서 넣음 : dummy(아무 의미 없지만 구분하기 위해 쓰는 것)
	{
		//원본 값은 어딘 가 저장해 놓고 계산을 함.
		Vector temp = *this; //임시 변수에 원본값을 저장해 놓음
		++(*this); //이렇게 해도 됨
		return temp;//반환은 임시 변수에 저장해 놓은 이전 값을 넣음.
	}

private:
	int x;
	int y;
	int z;
};

#pragma endregion

/*

	지렁이 게임 : 먹이 먹으면 꼬리가 하나 늘어나고
	내 꼬리에 부딪히거나 벽에 부딪히면 게임 오버.
	(지렁이를 나타낼때 배열보다 list를 활용해 주는 게 더 좋음)
*/