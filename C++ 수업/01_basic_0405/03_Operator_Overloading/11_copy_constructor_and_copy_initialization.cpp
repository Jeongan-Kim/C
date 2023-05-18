#include <iostream>

using namespace std;

class Test
{
	int num1;
	int num2;

public:
	//Ŭ������ �����ϸ� �⺻���� �����Ǵ� �Լ�(Ư���ɹ� �Լ�, special member function)
	// --������ �ټ��� �� �ϳ��� ����� ��
	//�⺻ ������
	//���� ������ : �� ��ü�� �״�� ���ͼ� ����Ǵ� ����
	//�̵� ������
	//���� ���� ������
	//�̵� ���� ������
	// 
	//�Ҹ���
	Test(int n1, int n2) : num1(n1), num2(n2) //�̷��� ����� �ָ� �⺻ �����ڴ� �ڵ����� �����.
	{}
};

class Fraction
{
	int numerator;
	int denominator;

public:
	Fraction(int num = 0, int den = 0)
		: numerator(num), denominator(den)
	{
		cout << "constructor" << endl;
	}

	//���� ������
	/*explicit*/ Fraction(const Fraction& fraction) //�״�� �������ϱ� const, �� �ڽ��̴ϱ� & �ٿ���
	{
		cout << "copy constructor" << endl;
	}
	//explicit�� �տ� ���̸� ���������� ��������ڰ� �ڵ����� ����� �ִ� �� ���� ��

	//���� ���� ������
	Fraction& operator = (const Fraction& rhs)
	{
		cout << "copy assignment operator" << endl;
		return *this;
	}
};

Fraction CreateFraction() //�̸� �ִ� ��ü : ��ü�� ����� �Լ�
{
	Fraction temp(5, 2); //�����ڸ� ���ؼ� �ӽ� ��ü�� ����� �ش���
	
	return temp; //��ȯ��
}

int main()
{
	Test t1(1, 2);
	Test t2 = t1; //t2�� t1 ����Ǿ� ���鼭(=) ����� ���ÿ� ���� �����ڰ� �ڵ� ������.
	//Test t2(t1); �̷��Ե� ����

	Fraction frac(3, 5); //��ü �ϳ� �����
	Fraction copy1(frac); //copy initialization(���� ������)
	Fraction copy2 = frac; //�̰͵� ���� ������

	copy2 = frac; //copy assignment operator(���� ���� ������) =

	{
		int a = 5; //����
		int b = a; //���� ����
	}

	CreateFraction(); //�̶��� ���� �����ڰ� ���� -> ��ȿ����

	return 0;
}