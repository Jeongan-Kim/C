#include <iostream>
//다이아몬드 상속 문제
/*
	  A
	 / \
	B   C  (상속)
     \ /
	  D    (상속)

	class A{};
	class B : public A {};
	class C : public A {};
	class D : public B, public C{};
	//이런 경우 D는 A를 두개 받아서, 어떤 걸 사용해야 할지 모호성 문제가 생김
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
	//A가 두개 생성됨.

//	copier.i; //i가 어떤 A의 i인지 모호해짐.(ambiguous)
	//-> virtual 키워드로 가상 상속을 해서 i가 하나만 존재할 수 있게 해서 해결할 수 있음.(A가 하나만 생성되게 됨.)

	return 0;
}