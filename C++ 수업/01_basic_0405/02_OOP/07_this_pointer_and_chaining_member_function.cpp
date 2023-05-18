#include <iostream>

using namespace std;

/*
	this pointer : ��ü �ڽ��� ����Ű�� �뵵�� ���Ǵ� ������.
	self reference����.
	�ڷ����� ������ ���� ����
*/

//class Test
//{
//	int num;
//
//public:
//	Test(int n) : num(n)
//	{
//		cout << "num : " << num << endl;
//		cout << "num address : " << &num << endl; //���� �ּҰ� ����.
//		cout << "this address : " << this << endl; // Test �ڱ� �ڽ��� ����Ű�� ������
//	}
//
//	void ShowTestData()
//	{
//		cout << num << endl;
//	}
//
//	Test* GetThisPointer() //�̷��� ��ȯ�ϱ⵵ ��.
//	{
//		return this;
//	}
//};
//
//class Test2
//{
//	int a;
//	int b;
//	int c;
//
//public:
//	Test2() {}
//	~Test2() {} //�⺻������ �� ������ �Ⱦ����� �̷��� ���ִ� ��쵵 ����. ������ ���� �� �����Ƿ�.,
//
//	auto /*this call*/ GetA()
//	{
//		cout << this << endl;
//		return a;
//	}
//
//	//void SetA(const int& a) { a = a; } a�� � ���� ������ �Ȱ��� �̷��� �� ���ٰ� ����
//	void SetA(const int& a) { this->a = a; } //�׷��� this �����͸� �̿��ؼ� �̷��� �� �� ����.
//};
//
//int main()
//{
//	Test t1(100);
//	Test* ptr1 = t1.GetThisPointer(); //this�� ������ ��.
//	cout << ptr1 << endl;
//	ptr1->ShowTestData();
//
//
//	Test t2(200);
//	Test* ptr2 = t2.GetThisPointer(); //this�� ������ ��.
//	cout << ptr2 << endl;
//	ptr2->ShowTestData();
//
//
//	return 0;
//}


#pragma region chaining member function

//�ڱ� �ڽ��� ���������� ȣ���ϴ� �Լ�

class Calc
{
	int value;

public:
	Calc(int value) : value(value) {}

	//void Add(int value) { this->value += value; }
	//void Sub(int value) { this->value -= value; }
	//void Mul(int value) { this->value *= value; }
	//void Div(int value) { this->value /= value; }
	//void Mod(int value) { this->value %= value; }

	//���������� ���ϰ� ���� ����, ��ȯ���� �� ��ü�� ���� ���� �������� �Լ��� ���´�.
	Calc& Add(int value) { this->value += value; return *this; } //*this �������� ���� �� �ڽ��� �ּ� ������ ���´ٴ� �ǹ�.
	Calc& Sub(int value) { this->value -= value; return *this; }
	Calc& Mul(int value) { this->value *= value; return *this; }
	Calc& Div(int value) { this->value /= value; return *this; }
	Calc& Mod(int value) { this->value %= value; return *this; }
};

int main()
{
	//Calc calc(10);
	//calc.Add(5);
	//calc.Sub(2); // ������ �̷������� ���� ������ ��� ��.

	cout << "a" << "b" << "c" << "d" << "e" << endl; //�̰͵� ������ chaining

	Calc calc(10);
	calc.Add(5).Div(2).Mod(3).Mod(4).Sub(1);

	//�͸�ü�� ȣ���ؼ� ������ ����ϴ� �͵� ����(�̸� ������ �����شٴ� ��)
	//ananimous object
	Calc(20).Add(1).Add(2); //�׷��� �̰��� 1ȸ���̰� ����� �Ұ�����. �̸��� ���� ������.

	return 0;
}
#pragma endregion


/*
   <����>

   C++�� �����
   ȭ��ǥ Ÿ���� ����
   �־��� �ð� �ȿ� ȭ��ǥ ���ʴ�� ������
   
*/