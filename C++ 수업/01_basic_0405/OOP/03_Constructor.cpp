#include <iostream>

using namespace std;

//생성자. 복사 생성자. 이동 생성자.
//멤버 변수 초기화할때 주로 사용
class Fraction
{
public:
	Fraction() // 기본 생성자 : class랑 이름이 같다. / 객체가 생성되면 자동으로 딱 한번 만들어져서 호출되는 함수다.(내가 만들지 않아도)
	{
		cout << "Constructor!" << endl;
	}
	//생성자도 오버로딩이 가능함.

	Fraction(int a, int b)
	{
		cout << "Constructor2!" << endl;
	}

	//생성자도 default parameter를 해줄 수도 있지만 모호성 문제때문에 조심해야 함.
	//Fraction(int a = 7, int b = 8)
	//{
	//	cout << "Constructor2!" << endl;
	//}

	//복사 생성자
	Fraction(const Fraction& data) //외부에 존재하는 원본을 복사해서 호출하는 방식.(안전하게 const붙여서 가져오기)
	{
		cout << "Constructor3!" << endl;
	}

	//이동 생성자
	Fraction(Fraction&& data) noexcept //R value reference로 가져옴. 나 자체를 가져오는 것. noexcept는 예외처리 할 수 없다고 할때 써줌
	{
		cout << "Constructor4!" << endl;
	}

private:
	int numerator = 10;
	int denominator = 10;
};

int main()
{
	Fraction frac; //객체 생성.
	Fraction frac1(1, 2); //다른 생성자를 만들었을 때에는 기본 생성자가 무시됨.
	Fraction frac11(1.0, 3);
	//Fraction frac111{ 1.0, 3 }; 더 엄격한 경우라서 오류 남.(?)

	Fraction frac2(frac1); //복사 생성자 호출할때
	Fraction frac3(std::move(frac1)); //이동 생성자 호출할때
	return 0;
}