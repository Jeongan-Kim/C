#include <iostream>

using namespace std;

//���� ������ + - !

class Won
{
	int value;
public:
	Won(int value = 0) : value(value) {}

	//!
	bool operator !() const //���� ���� true or false���� Ȯ���ؼ� �ݴ�� ����
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

	cout << boolalpha; //���ĺ����� true or false�� ��Ÿ���� ��
	cout << !w2 << endl;
	return 0;
}