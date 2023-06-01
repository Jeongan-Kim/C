#include <iostream>
//Ŭ���� ��ü, ��ü�� Ư��ȭ

using namespace std;

template<class T>
class A
{
public:
	A(const T& input) {}

	void DoSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void Test() {}
};

template<> //Ư��ȭ
class A<char> //char������ ����� ������ Ư��ȭ�ϰڴ�.
{
public:
	A(const char& input) {}

	void DoSomething()
	{
		cout << "char type specialization" << endl;
	}

	//���⿡�� Test�Լ��� ����. ��ó�� �Լ��� �ٸ��� ����� �� ���� �ִ�.
};

int main()
{
	A<int> aint(10);
	A<double> adouble(10.1);
	A<char> achar('a');

	aint.DoSomething();
	adouble.DoSomething();
	achar.DoSomething();

	aint.Test();
	adouble.Test();
	//achar.Test(); //��� ����

	return 0;
}