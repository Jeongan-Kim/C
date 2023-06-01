#include <iostream>
#include <array>
//�ڷ����� �ƴ� ���ø�?
//���� �ڷ����� �迭�� ���鶧, �� ������ �ʰ� ���ø����� �� �ٷ� �� �ִ�.
using namespace std;

template<typename T, unsigned int SIZE> //���ø� �Ű� ������ �ٸ� <� Ÿ���̵� ����, ��� ������>
class MyArray
{
public:
	MyArray() = default;
	~MyArray() {}

	T& operator[](int index)
	{
		return arr2[index];
	}

private:
	T arr1[10]; //�����Ҵ�� �����
	T arr2[SIZE]; //������ Ÿ�ӿ� ���� ���⿡ ������ ����
};

int main()
{
	MyArray<int, 10> arr1;//int�� 10���� �迭
	MyArray<float, 20u> arr2; //u�� unsigned int��� �ǹ�

	for (int i = 0; i < 10; i++)
		arr1[i] = i;

	for (int i = 0; i < 20; i++)
		arr2[i] = i;

	for (int i = 0; i < 20; i++)
		cout << arr2[i] << ' ';


	array<int, 10> arr3; //array����� �߰��ؼ� ����� �Ͱ� �����.

	for (int i = 0; i < 10; i++)
		arr3[i] = i;

	for (int i = 0; i < 10; i++)
		cout << arr3[i] << ' ';

	return 0;
}