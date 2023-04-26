#include <iostream>
//const ��� �˾ƺ���.

using namespace std;

class Data
{
	int value1;
	mutable int value2;

public:
	Data() : value1(0) {}

	int& GetValue() { cout << "not const" << endl; return value1; }

	//int& GetValue1() const { cout << " comnst"; return value1; } //�Լ� ��ü�� const�� ���� ��� const�� ���� ���� ������ ������ �ϸ� ������ ��.
	//��ȸ������ ������ �� �ֱ� ������.(?)
	const int& GetValue1() const { cout << "const"; return value1; } //�����ε� �Լ�. ����Լ���� ������ �����ؼ� .

	//void SetValue(int value) const { this->value1 = value; } //value�� ���ȭ �ż� ���� �Ұ�. �̶� ������ �� �ְ� ����ϴ� Ű����(mutable)�� ����
	void SetValue(int value) const { this->value2 = value; }
	const void SetValue2(int value) const { this->value2 = value; }
};

void Print(const Data& data) //������ ���� ���� const�� ��.
{
	data.GetValue1(); //�̷��� �����ٰ� ���⸸ �Ҷ� ����Լ��� ��.
}

int main()
{
	Data data1;
	const Data data2; //const�Լ��� ȣ���� �� �ִ� �Լ� ��ü.
	
	data1.GetValue();
	//data2.GetValue(); �Ұ���.
	data2.GetValue1();

	Print(data2);

	return 0;
}