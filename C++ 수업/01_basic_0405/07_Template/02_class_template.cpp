#include <iostream>
#include "02_myArray.h"
//#include "02_myArray.cpp"//���ø� ���� �κ��� ���� ������ �ʹٸ�. ����� �־����.
//�̰͵� ������ �ƴϾ inl ������ �߰��ؼ� �۾��ϸ� ��.
#include "02_myArray.inl"
using namespace std;

int main()
{
	myArray<int> myArr(10); //int�� 10��¥�� �����Ҵ��� �� ��
	myArr.Print();

	return 0;
}