#include <iostream>
//��ü���� �ڷ����� ��� �ٷ� �� ����.(�Ϲ�ȭ ���α׷���)
//������ �˰����� �����ų�� ���.
// <> �� ��ü�� ���ø��̶�� ���� ��.

using namespace std;

//int GetMax(int x, int y) { return x > y ? x : y; }
//int GetMax(short x, short y) { return x > y ? x : y; }
//int GetMax(double x, double y) { return x > y ? x : y; }
//int GetMax(float x, float y) { return x > y ? x : y; }

//�̷��� ���� �� ���� �������� ���ø� �̿�

template <typename T>
T GetMax(T x, T y) { return x > y ? x : y; }

class Won
{
	int value = 0;

public:
	Won(int value = 0) : value(value) {}

	bool operator > (const Won& rhs)
	{
		return value > rhs.value;
	}

	friend ostream& operator << (ostream& out, const Won& won) //��� ������ �����ε� �Լ��� �����Լ��θ� �� �� �־���
	{
		cout << won.value;
		return out;
	}
};

int main()
{
	cout << GetMax(1, 2) << endl;
	cout << GetMax(1.0, 2.0) << endl;
	cout << GetMax(1.1f, 2.2f) << endl;
	cout << GetMax(1u, 2u) << endl;//usigned int
	cout << GetMax(1ll, 2ll) << endl; //long long

	//cout << GetMax(1, 2.0f) << endl; //�ڷ����� �ٸ��� �ȵ�

	cout << GetMax<int>(1, 2.0f) << endl; //�̷��� int������ ���� �ϸ� ���� �ȳ�

	cout << GetMax(Won(6), Won(2)) << endl; //��ü ��ü�� ���ø��� ����ؼ� �� �� ����(������ �����ε��� �� �Ŀ�)
	return 0;
}