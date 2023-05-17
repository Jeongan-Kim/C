#include <iostream>
//������ ����ȯ ȣ��
using namespace std;

class Fraction
{
	int numerator;
	int denominator;

public:
	Fraction(int num, int den)
		:numerator(num), denominator(den)
	{
		cout << "constructor" << endl;
	}

	Fraction(const Fraction& other)
		:numerator(other.numerator), denominator(other.denominator) 
	{
		cout << "copy constructor" << endl;
	}

	//��ȯ ������
	Fraction(int a) //�Ű� ������ �� �ϳ� �� ���� ��ȯ ������(�ٸ� �ڷ������� ����ȯ�ϰ� ���� �� ���)
		:numerator(a), denominator(1)
	{
		cout << "conversion constructor" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction frac)
	{
		cout << frac.numerator << " / " << frac.denominator << endl;
		return out;
	}

};

void PrintFraction(Fraction frac) //�̶��� ����ż� �Ű������� ��ü�� ���Ƿ� ���� �����ڰ� ����
{
	//�̶��� �Ű� ������ � int ���� �ڷ����� �ƴ϶� ��ü�� ������ ������, �ڷ����� �ٸ� �� ���͵�
	//�ڵ����� ����ȯ�� �Ͼ
	//�����ַ��� �Լ� �տ� explicit�� �ٿ�����.
	cout << frac << endl;
}
int main()
{
	Fraction frac1(10, 20);
	Fraction frac2(frac1);

	Fraction frac3(1); //�ڷ����� �ùٸ�
	Fraction frac4('A'); //�ڷ����� char������ �ٸ����� �ڵ����� ������ ����ȯ�� �Ͼ�� ��
	Fraction frac5(3.14f); //�̶��� ����ȯ�� �Ͼ���� �ڷᰪ�� �߸��� ��.

	PrintFraction(frac1);
	PrintFraction(frac2);
	PrintFraction(frac3);
	PrintFraction(frac4);
	PrintFraction(frac5);

	cout << endl;
	
	//�̷��� �ڷ����� ���� �ʴ� �� ���� ���� �Ǵ� �� �����ѵ�, �����ַ��� �Լ� �տ� explicit�� �ٿ���
	PrintFraction(1);
	PrintFraction('A');
	PrintFraction(3.14f);

	return 0;
}