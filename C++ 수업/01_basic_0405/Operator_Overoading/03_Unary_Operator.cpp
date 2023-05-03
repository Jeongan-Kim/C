#include <iostream>

using namespace std;

//단항 연산자 + - !

class Won
{
	int value;
public:
	Won(int value = 0) : value(value) {}

	//!
	bool operator !() const //넣은 값이 true or false인지 확인해서 반대로 리턴
	{
		return (value == 0) ? true : false;
	}

	friend ostream& operator << (ostream& out, const Won& won)
	{
		out << won.value;
		return out;
	}
};

int main()
{
	const Won w1(10);
	const Won w2(0);
	
	cout << !w1 << endl; //0

	cout << boolalpha; //알파벳으로 true or false를 나타내는 것
	cout << !w2 << endl;
	return 0;
}