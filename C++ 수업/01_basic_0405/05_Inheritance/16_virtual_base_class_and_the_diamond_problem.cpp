#include <iostream>
//���̾Ƹ�� ��� ����
/*
	  A
	 / \
	B   C  (���)
     \ /
	  D    (���)

	class A{};
	class B : public A {};
	class C : public A {};
	class D : public B, public C{};
	//�̷� ��� D�� A�� �ΰ� �޾Ƽ�, � �� ����ؾ� ���� ��ȣ�� ������ ����
*/

using namespace std;

class PoweredDevice
{
public:
	PoweredDevice() = default;
	PoweredDevice(int power) { cout << "PoweredDevice" << power << endl; }

	int i;
};

class Scanner : virtual public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		:PoweredDevice(power)
	{
		cout << "Scanner : " << scanner << endl;
	}
};

class Printer : virtual public PoweredDevice
{
public:
	Printer(int printer, int power)
		:PoweredDevice(power)
	{
		cout << "Printer : " << printer << endl;
	}
};

class Copier : public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power1, int power2, int power3)
		:Scanner(scanner, power1)
		, Printer(printer, power2)
		, PoweredDevice(power3)
	{}
};

int main()
{
	Copier copier(1, 2, 3, 4, 5);

	cout << &copier.Scanner::PoweredDevice::i << endl;
	cout << &copier.Printer::PoweredDevice::i << endl;
	//A�� �ΰ� ������.

//	copier.i; //i�� � A�� i���� ��ȣ����.(ambiguous)
	//-> virtual Ű����� ���� ����� �ؼ� i�� �ϳ��� ������ �� �ְ� �ؼ� �ذ��� �� ����.(A�� �ϳ��� �����ǰ� ��.)

	return 0;
}