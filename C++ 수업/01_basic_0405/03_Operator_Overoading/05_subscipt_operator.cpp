#include <iostream>
// [] �迭 �ε����� �����ϴ� ������(?)
using namespace std;

class IntArray //�迭 Ŭ����
{
	int list[3];

public:
	//int Get(int index) { return list[index]; }
	//void Set(int index, int value) { list[index] = value; }

	//int* GetList() { return list; }


	int& operator[] (int index)
	{
		if (index < 0 || index >= 10)
		{
			cout << "Array index out of bound exception" << endl;
		}

		return list[index];
	}
};

int main()
{
	//int arr[3] = { 1, 2, 3 };
	//cout << arr[-1] << endl;
	//cout << arr[3] << endl; //��� �˻縦 ���� �ʱ� ������ �������� ������ ������ ���� ����. �׷��� �迭 Ŭ������ ���� ����ϱ⵵ ��.

	IntArray list;
	//list.Set(0, 1);
	//list.Set(1, 2);
	//list.Set(2, 3);

	//cout << list.Get(0) << endl;
	//cout << list.Get(1) << endl;
	//cout << list.Get(2) << endl;
	//Ŭ���� ���� �Լ� �����̹Ƿ� ���� �ſ� ������


	//auto arr = list.GetList(); //�̷��� �迭�� ũ�Ⱑ ������ �𸣱� ������ ������ �����ε��� �ϴ� ��.

	//arr[0] = 1;
	//arr[1] = 2;
	//arr[2] = 3;


	list[0] = 1;
	list[1] = 2;
	list[2] = 3;

	cout << list[0] << endl;
	cout << list[1] << endl;
	cout << list[3] << endl;
	cout << list[20] << endl; //���� ó�� �Ϸ�.


	return 0;
}