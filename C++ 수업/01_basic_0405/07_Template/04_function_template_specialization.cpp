#include <iostream>
//템플릿 특수화 : 이덕에 템플릿도 다형성의 특성 중 하나로 봄
//특정 자료형에 대해 예외 처리를 하고자 할때.
using namespace std;

template<typename T>
T GetMax(T x, T y)
{
	return (x > y) ? x : y;
}

//char 자료형일때에만 예외로 처리하고 싶을때.
template<> //아무것도 안적어줌.
char GetMax(char x, char y)
{
	cout << "warning : comparing chars" << endl; //오버라이딩 하듯이 
	return (x > y) ? x : y;
}

template<class T>
class Storage
{
	T value

public:
	Storage(T value)
		:value(value)
	{}

	void Print()
	{
		cout << value << endl;
	}
};

template<>
void Storage<double>::Print()
{
	cout << "double : " << value << endl;
}

int main()
{
	cout << GetMax<int>(1, 2) << endl;
	cout << GetMax<float>(1.1f, 2.2f) << endl;
	cout << GetMax<char>('a', 'b') << endl;
	cout << GetMax('a', 'b') << endl; //특수 경우에는 매개변수가 없으므로 이렇게 써도 됨

	Storage<int> s1(5);
	s1.Print();

	Storage<double> s2(10);
	s2.Print();

	return 0;
}