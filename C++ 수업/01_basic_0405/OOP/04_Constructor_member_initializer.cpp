#include <iostream>
//������� �ʱ�ȭ ���
using namespace std;

class Data
{
public:
	Data(int aData, int bData, int cData) //������ ���ÿ� �ʱ�ȭ�ϴ� ���� �ʿ���(�������� ���ȭ�Ǳ� ���� �ؾ� �� �ʿ䰡 �ֱ⿡)
		:a(aData), b(bData), c(cData)     //�̷��� �ϸ� �ٷ� �ʱ�ȭ����.
	{
/*		a = aData;
		b = bData;
		c = cData;*/ //�̷� ����� �Ű������� �����ؼ� �ֱ� ������ �ӵ��� ����.
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