#include <iostream>
//구체적인 자료형을 묶어서 다룰 수 있음.(일반화 프로그래밍)
//동일한 알고리즘을 적용시킬때 사용.
// <> 이 자체를 템플릿이라고 보면 됨.

using namespace std;

//int GetMax(int x, int y) { return x > y ? x : y; }
//int GetMax(short x, short y) { return x > y ? x : y; }
//int GetMax(double x, double y) { return x > y ? x : y; }
//int GetMax(float x, float y) { return x > y ? x : y; }

//이렇게 여러 개 쓰면 귀찮으니 템플릿 이용

template <typename T>
T GetMax(T x, T y) { return x > y ? x : y; }

class Won
{
	int value = 0;

public:
	Won(int value = 0) : value(value) {}

	bool operator > (const Won& rhs)
	{
		return value > rhs.value;
	}

	friend ostream& operator << (ostream& out, const Won& won) //출력 연산자 오버로딩 함수는 전역함수로만 쓸 수 있었음
	{
		cout << won.value;
		return out;
	}
};

int main()
{
	cout << GetMax(1, 2) << endl;
	cout << GetMax(1.0, 2.0) << endl;
	cout << GetMax(1.1f, 2.2f) << endl;
	cout << GetMax(1u, 2u) << endl;//usigned int
	cout << GetMax(1ll, 2ll) << endl; //long long

	//cout << GetMax(1, 2.0f) << endl; //자료형이 다르면 안됨

	cout << GetMax<int>(1, 2.0f) << endl; //이렇게 int형으로 들어가게 하면 오류 안남

	cout << GetMax(Won(6), Won(2)) << endl; //객체 자체도 템플릿을 사용해서 쓸 수 있음(연산자 오버로딩을 한 후에)
	return 0;
}