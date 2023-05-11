#include <iostream>

using namespace std;

class Test
{
	int num1;
	int num2;

public:
	//클래스를 생성하면 기본으로 생성되는 함수(특수맴버 함수, special member function)
	// --생성자 다섯개 중 하나만 생기면 됨
	//기본 생성자
	//복사 생성자 : 내 객체가 그대로 들어와서 복사되는 형태
	//이동 생성자
	//복사 대입 연산자
	//이동 대입 연산자
	// 
	//소멸자
	Test(int n1, int n2) : num1(n1), num2(n2) //이렇게 만들어 주면 기본 생성자는 자동으로 사라짐.
	{}
};

class Fraction
{
	int numerator;
	int denominator;

public:
	Fraction(int num = 0, int den = 0)
		: numerator(num), denominator(den)
	{
		cout << "constructor" << endl;
	}

	//복사 생성자
	/*explicit*/ Fraction(const Fraction& fraction) //그대로 가져오니까 const, 내 자신이니까 & 붙여서
	{
		cout << "copy constructor" << endl;
	}
	//explicit를 앞에 붙이면 묵시적으로 복사생성자가 자동으로 만들어 주는 걸 막을 때

	//복사 대입 연산자
	Fraction& operator = (const Fraction& rhs)
	{
		cout << "copy assignment operator" << endl;
		return *this;
	}
};

Fraction CreateFraction() //이름 있는 객체 : 객체를 만드는 함수
{
	Fraction temp(5, 2); //생성자를 통해서 임시 객체를 만들어 준다음
	
	return temp; //반환함
}

int main()
{
	Test t1(1, 2);
	Test t2 = t1; //t2에 t1 복사되어 들어가면서(=) 생기는 동시에 복사 생성자가 자동 생성됨.
	//Test t2(t1); 이렇게도 가능

	Fraction frac(3, 5); //객체 하나 만들고
	Fraction copy1(frac); //copy initialization(복사 생성자)
	Fraction copy2 = frac; //이것도 복사 생성자

	copy2 = frac; //copy assignment operator(복사 대입 연산자) =

	{
		int a = 5; //복사
		int b = a; //복사 대입
	}

	CreateFraction(); //이때도 복사 생성자가 생김 -> 비효율적

	return 0;
}