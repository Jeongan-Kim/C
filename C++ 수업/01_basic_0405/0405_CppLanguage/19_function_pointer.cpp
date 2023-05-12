#include <iostream>
#include <functional>

using namespace std;

//�Լ� ������ ���� �������� ���

bool func(const int& x) //L-value reference
{
	return x > 0;
}

typedef myint int; //myint�� intó�� ���ڴ�!

typedef bool(*funcPtr)(const int&);

using funcType = bool(*)(const int&);

int main()
{
	bool (*pf)(const int&) = func; //�Լ� ������ ���� ��� ���ϰ� (������ �̸�)(�Ű����� ����)

	funcPtr f = func;
	
	funcType f2 = func;

	std::function<bool(const int&)> f3 = func; //functional ��� ������ ���� �� �� �ִ� ��.

	return 0;
}