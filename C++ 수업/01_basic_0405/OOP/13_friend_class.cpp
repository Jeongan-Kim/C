#include <iostream>
//friend�� ��ü ������ �μ��� ������ �������⵵ ��. ���� ���� ������.
//friend�� ����� �ȵ�.
using namespace std;

#pragma region friend global function
class A
{
	int value = 1;

	friend void doSomething1(const A& a); //������ ���������� friend �Լ��� �����Լ�ó�� �����ؼ� �� �� ����.
	/*friend void doSomething2(const A& a)
	{
		cout << a.value << endl;
	}*///�̷��� �ᵵ ����
};

void doSomething1(const A& a)
{
	cout << a.value << endl;
}

int main()
{
	A a;
	doSomething1(a);


	return 0;
}

#pragma endregion


#pragma region friend member class //�̰� �� ������.
class A
{
public:
	void attack(B& b); //Ŭ���� B�� ������ ������ ���� �ͼ� ��

private:
	int a;
};

class B
{
	friend void A::attack(B& b); //B�� A���� attack���� ��� ������ ���� �����ϵ��� ����Ѵٴ� ��.

private:
	int hp = 100;
};


void A::attack(B& b)
{
	cout << "b�� ü�� : " << b.hp << endl;

	cout << "����!" << endl;
	b.hp -= 10;
}

int main()
{
	A a;
	B b;

	//b.a; �̷��� �Ұ���(?)
}

#pragma endregion


#pragma region friend class

class A
{
public:
	void PrintBValue1(class B& b);
	void PrintBValue2(class B& b);
};

class B
{
	friend class A; // B�� ��� ��� ������ A���� ���� ������.
	int value1 = 10;
	int value2 = 20;
};

void A::PrintBValue1(B& b)
{
	cout << b.value1 <<endl;
}

void A::PrintBValue2(B& b)
{
	cout << b.value2 << endl;
}

int main()
{
	A a;
	B b;

	a.PrintBValue1(b);
	a.PrintBValue2(b);
}

#pragma endregion


