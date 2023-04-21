#include <iostream>
//멤버변수 초기화 방법
using namespace std;

class Data
{
public:
	Data(int aData, int bData, int cData) //생성과 동시에 초기화하는 것이 필요함(변수들이 상수화되기 전에 해야 할 필요가 있기에)
		:a(aData), b(bData), c(cData)     //이렇게 하면 바로 초기화가됨.
	{
/*		a = aData;
		b = bData;
		c = cData;*/ //이런 방식은 매개변수를 복사해서 넣기 때문에 속도가 느림.
	}

	void print()
	{
		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
	}

private :
	const int a = 10;
	const int b = 10;
	const int c = 10;
};

int main()
{
	Data data1(20, 20, 20);

	data1.print();

	return 0;
}