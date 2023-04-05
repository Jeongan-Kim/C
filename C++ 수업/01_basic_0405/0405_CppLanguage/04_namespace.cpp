#include <iostream>

//std::cout : cout이라는 이름 공간 -> std
//jeongan::i
//seongho::i   정안 마을의 i, 성호 마을의 i

int ii = 10;

namespace A
{
	void exFunc()
	{
		std::cout << "A가 정의한 함수\n" << std::endl;
	}
}

namespace B
{
	void exFunc() //위 이름 공간에도 같은 함수 이름이 있지만 오류 없음
	{
		std::cout << "B가 정의한 함수\n" << std::endl;
	}
}

//이름 공간을 중첩해서 사용하는 경우
namespace myNamespace1
{
	int a;

	void doSomething(){}

	namespace AA
	{
		namespace BB
		{
			namespace CC
			{
				int c;
			}
		}
	}
}

namespace myNamespace1 // 위 이름 공간이랑 같은 공간. 분리된 느낌이라고 보면 됨.
{
	int hello;
}

namespace myNamespace2
{
	int a;
	void doSomething() {}

}

int main()
{
	A::exFunc();
	B::exFunc();

	myNamespace1::AA::BB::CC::c;

	{
		//이름 지정(::) 없이 함수를 호출할 수 있다.
		using namespace myNamespace1; // myNamespace1 공간을 호출할때에는 이름 지정을 안하겠다. 끄고 키는 특징이 있다.
		//using namespace myNamespace2; // 둘다 하면 a에 대해 모호성 문제(ambiguity)가 생김
		a = 10; //이름 지정을 안하는 건 myNamespace1 이다.

		myNamespace2::a = 20;
	}

	//using std::cin;
	//using std::cout; 
	//using std::endl;

	using namespace std; //이름 지정하기 귀찮으니까 시작할떄 쓰고 시작할거지만 위험할 수 있음.

	cout << "hello" << endl;


	int ii = 0;

	ii++; //두 ii 중에 지역변수인 ii
	cout << ii << endl;

	::ii++; //두 ii 중에 전역변수인 ii
	cout << ::ii << endl;


	return 0;
}