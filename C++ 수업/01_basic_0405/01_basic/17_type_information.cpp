#include <iostream>

using namespace std;

int add(int a, int b) { return a + b; }
short add(short a, short b) { return a + b; }
float add(float a, float b) { return a + b; }
//�̷��� ���� �ڷ������� �����ε� �Լ��� ����� ������ �����ϰ� ���� ����� �˾ƺ���.

/*
Template 
���� �̸� �Լ��� ���� �ڷ������� ����� ������ ���� ��
*/

template <typename T> 
T add(T a, T b) //�����ε� �Լ� �� �������� �ʾƵ� �������� �����ؼ� �� �� �ִ� ���� ��.
{
	return a + b;
}

int main()
{
	add(10, 20);
	add(10.0f, 20.0f);
	add(20.1, 50.2);


	return 0;
}