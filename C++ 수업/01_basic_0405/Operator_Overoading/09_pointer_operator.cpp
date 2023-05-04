#include <iostream>

using namespace std;

//* ->

class Number
{
	int num;

public:
	Number(int n) : num(n) {}

	void ShowData()
	{
		cout << num << endl;
	}

	//-> :��ü ��ü�� �ּҰ��� ��ȯ
	Number* operator->()
	{
		return this;
	}

	//* :���� �����
	Number& operator*()
	{
		return *this;
	}

};

int main()
{
	Number num(20);
	num.ShowData();

	(*num) = 30; //num ��ü�� ������ ���·� �� �� ����.
	num->ShowData(); //num.operator->()->ShowData();

	//��� �̷� ����
	num.operator*() = 30;
	num.operator*().ShowData();


	return 0;
}