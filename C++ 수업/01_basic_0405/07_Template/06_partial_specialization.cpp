#include <iostream>
//�κ� Ư��ȭ

using namespace std;

//#pragma region 1. �Ϲ� �Լ� �κ� Ư��ȭ
//template <class T, int size>
//class StaticArray //���� �迭 Ŭ����
//{
//	T arr[size]; //nonŸ������
//
//public:
//	T* GetArray() { return arr; }
//
//	T& operator[](int index)
//	{
//		return arr[index];
//	}
//
//	void Print1()
//	{
//		for (int i = 0; i < size; i++)
//		{
//			cout << (*this)[i] << ' '; //arr[i] ��ü�� �ڽ� ���̹Ƿ� this�� �ᵵ ��
//		}
//		cout << endl;
//	}
//};
//
//template<typename T, int size>
//void Print2(StaticArray<T, size>& arr) //�� Ŭ������ ��ü�� �ϳ� �޾ƿͼ� �Է�.
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//	cout << endl;
//}
//
////�� �Լ��� char���϶��� Ư��ȭ�ϰ� ������
//template<int size>
//void Print2(StaticArray<char, size>& arr)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i]; //���ڿ��̴ϱ� ���� ���� ���ְԲ�
//	}
//	cout << endl;
//}
//
//#pragma endregion

#pragma region 2. Ŭ���� ��� �Լ� �κ� Ư��ȭ
//����� �̿��ؼ� �κ� Ư��ȭ�� ����� ��
template <class T, int size>
class StaticArray_Base
{
	T arr[size]; 

public:
	T* GetArray() { return arr; }

	T& operator[](int index)
	{
		return arr[index];
	}

	virtual void Print1() //�������̵��� �� �ְ� virtual Ű���� ���̱�
	{
		for (int i = 0; i < size; i++)
		{
			cout << (*this)[i] << ' '; 
		}
		cout << endl;
	}
};

//�Ϲ������� ����Ҷ�
template<class T, int size>
class StaticArray : public StaticArray_Base<T, size>
{

};

//char ���϶��� Ư��ȭ
template<int size>
class StaticArray<char, size> : public StaticArray_Base<char, size>
{
public:
	void Print1() override
	{
		for (int i = 0; i < size; i++)
		{
			cout << (*this)[i];
		}
		cout << endl;
	}
};


#pragma endregion

int main()
{
	StaticArray<int, 4> int4;
	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	int4.Print1();
	//Print2(int4); //���ø�ȭ ��Ų �Լ��ε� ����.

	StaticArray<char, 6> char6;
	char6[0] = 'H';
	char6[1] = 'E';
	char6[2] = 'L';
	char6[3] = 'L';
	char6[4] = 'O';
	char6[5] = '\n';

	char6.Print1();
	//Print2(char6);
	return 0;
}