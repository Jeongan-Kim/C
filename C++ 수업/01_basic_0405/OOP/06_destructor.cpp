#include <iostream>

//��ü �Ҹ�� �� �ݵ�� ȣ��Ǵ� �Ҹ���.
//��ȯ���� ����. 
//�Ҵ�� ���� �����ϴ� �뵵�� ���

using namespace std;

class Test
{
public:
	Test() //class�� ������ �� ������ �����
	{
		cout << "Constructor" << endl;
	}

	~Test() //class�� ������ �� ������ �����
	{
		cout << "Destructor" << endl;
	}
};

class IntArray
{
public:
	IntArray(const int& inLength)
	{
		length = inLength;
		arr = new int[length]; //�迭 �����Ҵ�
		cout << "constructor" << endl;
	}

	~IntArray()
	{
		delete[] arr; //�迭 �����Ҵ� ����
		cout << "destructor" << endl;
	}

private :
	int* arr = nullptr;
	int length = 0;
};

int main()
{
	Test test1;

	cout << "############### 1" << endl;
	{
		cout << "############### 2" << endl;
		Test test2; //���� �����̹Ƿ� ���� ����� �����Ǹ鼭 �Ҹ��ڰ� ����Ǵ� ���� �� �� ����
		cout << "############### 3" << endl;
	}
	cout << "############### 4" << endl;

	while (true)
	{
		IntArray myArr(1000); // ������ �Ǵ� �Ҹ��ڷ� �������ִ� �۾��� �ʿ���.
	}
	return 0;
}