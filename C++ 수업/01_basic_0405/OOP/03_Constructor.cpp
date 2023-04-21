#include <iostream>

using namespace std;

//������. ���� ������. �̵� ������.
//��� ���� �ʱ�ȭ�Ҷ� �ַ� ���
class Fraction
{
public:
	Fraction() // �⺻ ������ : class�� �̸��� ����. / ��ü�� �����Ǹ� �ڵ����� �� �ѹ� ��������� ȣ��Ǵ� �Լ���.(���� ������ �ʾƵ�)
	{
		cout << "Constructor!" << endl;
	}
	//�����ڵ� �����ε��� ������.

	Fraction(int a, int b)
	{
		cout << "Constructor2!" << endl;
	}

	//�����ڵ� default parameter�� ���� ���� ������ ��ȣ�� ���������� �����ؾ� ��.
	//Fraction(int a = 7, int b = 8)
	//{
	//	cout << "Constructor2!" << endl;
	//}

	//���� ������
	Fraction(const Fraction& data) //�ܺο� �����ϴ� ������ �����ؼ� ȣ���ϴ� ���.(�����ϰ� const�ٿ��� ��������)
	{
		cout << "Constructor3!" << endl;
	}

	//�̵� ������
	Fraction(Fraction&& data) noexcept //R value reference�� ������. �� ��ü�� �������� ��. noexcept�� ����ó�� �� �� ���ٰ� �Ҷ� ����
	{
		cout << "Constructor4!" << endl;
	}

private:
	int numerator = 10;
	int denominator = 10;
};

int main()
{
	Fraction frac; //��ü ����.
	Fraction frac1(1, 2); //�ٸ� �����ڸ� ������� ������ �⺻ �����ڰ� ���õ�.
	Fraction frac11(1.0, 3);
	//Fraction frac111{ 1.0, 3 }; �� ������ ���� ���� ��.(?)

	Fraction frac2(frac1); //���� ������ ȣ���Ҷ�
	Fraction frac3(std::move(frac1)); //�̵� ������ ȣ���Ҷ�
	return 0;
}