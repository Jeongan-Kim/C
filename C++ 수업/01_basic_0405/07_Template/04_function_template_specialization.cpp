#include <iostream>
//���ø� Ư��ȭ : �̴��� ���ø��� �������� Ư�� �� �ϳ��� ��
//Ư�� �ڷ����� ���� ���� ó���� �ϰ��� �Ҷ�.
using namespace std;

template<typename T>
T GetMax(T x, T y)
{
	return (x > y) ? x : y;
}

//char �ڷ����϶����� ���ܷ� ó���ϰ� ������.
template<> //�ƹ��͵� ��������.
char GetMax(char x, char y)
{
	cout << "warning : comparing chars" << endl; //�������̵� �ϵ��� 
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
	cout << GetMax('a', 'b') << endl; //Ư�� ��쿡�� �Ű������� �����Ƿ� �̷��� �ᵵ ��

	Storage<int> s1(5);
	s1.Print();

	Storage<double> s2(10);
	s2.Print();

	return 0;
}