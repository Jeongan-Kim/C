#include <iostream>
#include <vector>
#include <algorithm>
//관계 연산자
using namespace std;

class Won
{
	int value;
	int value1;

public:
	Won(int value = 0) : value(value){}
	auto Getvalue() const { return value; }
	void Setvalue(const int& value) { this->value = value; }


	friend ostream& operator << (ostream& out, const Won& won)
	{
		out << won.value;
		return out;
	}

	//== != < >
	bool operator==(const Won& rhs) const
	{
		return value == rhs.value && value1 == rhs.value1; //class안에 값이 2개면 둘다 확인해줘야 오류 안남
	}

	bool operator!=(const Won& rhs) const
	{
		return !(*this == rhs); //this 값이 여러 개이므로 한번에 확인하게 됨.
	}

	bool operator < (const Won& rhs) const
	{
		return value < rhs.value;
	}

	friend bool test(const Won& lhs, const Won& rhs);
};

bool test(const Won& lhs, const Won& rhs)
{
	return lhs.Getvalue() > rhs.Getvalue();
}

int main()
{
	Won w1(10), w2(20);

	if (w1 == w2)
		cout << "같다" << endl;
	else if (w1 != w2)
		cout << "다르다" << endl;

	//vector :동적 배열, new는 해제를 해줬어야 했는데 vector는 자동으로 해제가 됨.
	std::vector<Won> wons(20);

	int i = 1;
	for (auto& won : wons)
	{
		won.Setvalue(i);
		i++;
	}

	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;

	random_shuffle(wons.begin(), wons.end()); //알고리즘 헤더에 있는 셔플 함수

	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;

	sort(wons.begin(), wons.end()); //오름 차순으로 정렬됨.(객체지만 연산자 오버로딩을 한 상태라서 가능)
	
	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;

	sort(wons.begin(), wons.end(), test); //내림 차순으로(test함수를 이용)

	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;

	//람다식 함수 : 매개 변수에 함수를 넣는 것. 요청과 호출이 동시에 일어나지 않는 것(?) 엔터를 눌러야 실행이 되는 것.
	sort(wons.begin(), wons.end(), [](const Won& lhs, const Won& rhs)
		{
			return lhs.Getvalue() < rhs.Getvalue();
		}
	); //[]함수를 매개변수로 넣어줄 건데 함수가 없다는 의미로 비워놓음. 정의를 이 안에서 해버림.

	for (const auto& won : wons)
		cout << won << " ";
	cout << endl;
	return 0;
}
