#include <iostream>

using namespace std;

template<class T>
class A
{
	T value;

public:
	A(const T& value) :value(value) {}

	void Print()
	{
		cout << value << endl;
	}
};

//������ ����� ��쿡�� Ư��ȭ
template<class T>
class A<T*>
{
	T* value;

public:
	A(T* value) :value(value) {}

	void Print()
	{
		cout << *value << endl;
	}
};

int main()
{
	A<int> Aint(123);
	Aint.Print();

	int temp = 456;
	A<int*> Aptr(&temp);
	Aptr.Print(); //������ �ּҰ��� ����
	//�������� ��쿡�� ���� �����Բ� �ϰ� ������. �������� ��� Ư��ȭ�� ����


	return 0;
}