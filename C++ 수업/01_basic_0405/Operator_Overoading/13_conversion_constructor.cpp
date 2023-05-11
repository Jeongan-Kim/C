#include <iostream>
//묵시적 형변환 호출
using namespace std;

class Fraction
{
	int numerator;
	int denominator;

public:
	Fraction(int num, int den)
		:numerator(num), denominator(den)
	{
		cout << "constructor" << endl;
	}

	Fraction(const Fraction& other)
		:numerator(other.numerator), denominator(other.denominator) 
	{
		cout << "copy constructor" << endl;
	}

	//변환 생성자
	Fraction(int a) //매개 변수가 딱 하나 있 으면 변환 생성자(다른 자료형으로 형변환하고 싶을 때 사용)
		:numerator(a), denominator(1)
	{
		cout << "conversion constructor" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction frac)
	{
		cout << frac.numerator << " / " << frac.denominator << endl;
		return out;
	}

};

void PrintFraction(Fraction frac) //이때도 복사돼서 매개변수로 객체가 들어가므로 복사 생성자가 생김
{
	//이때도 매개 변수가 어떤 int 같은 자료형이 아니라 객체로 들어오는 거지만, 자료형이 다른 게 들어와도
	//자동으로 형변환이 일어남
	//막아주려면 함수 앞에 explicit을 붙여주자.
	cout << frac << endl;
}
int main()
{
	Fraction frac1(10, 20);
	Fraction frac2(frac1);

	Fraction frac3(1); //자료형이 올바름
	Fraction frac4('A'); //자료형이 char형으로 다르지만 자동으로 묵시적 형변환이 일어나서 들어감
	Fraction frac5(3.14f); //이또한 형변환이 일어나지만 자료값이 잘리긴 함.

	PrintFraction(frac1);
	PrintFraction(frac2);
	PrintFraction(frac3);
	PrintFraction(frac4);
	PrintFraction(frac5);

	cout << endl;
	
	//이렇게 자료형이 맞지 않는 게 들어가서 실행 되는 게 가능한데, 막아주려면 함수 앞에 explicit을 붙여줌
	PrintFraction(1);
	PrintFraction('A');
	PrintFraction(3.14f);

	return 0;
}