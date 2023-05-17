#include <iostream>

using namespace std;

/*
L-value R-value

int a = 10;
L-value : ���߿� �ٽ� ������ ������ ��
R-value : ���� ������ ������ �Ұ����� ��
*/

int Test1(int& a) //�������� ����Ǿ� ���� �������� �ٲٰڴ�.(copy)
{
	return a; //���� ���� ������.
}

int Test2(int&& a) //�������� �����Ƿ� �� �ȿ����� ���� ���ڴ�.(move)
{
	return a;
}

int main()
{
	int val = 5;
	int& r = val; //r-value reference, &�� �����̹Ƿ� ������ ��� �ִٴ� �ǹ�, ������ ���� ���� ���� ����ų ��(?), �����Ͷ� ���� �ǹ̶�� ���� ��
	int* ptr = &val;
	//reference�� ������ �������� �Ҵ絵 �����൵ ������ �����Ϳ� ���� ������ �Ѵٴ� �� �߿���.

	r = 10;

	cout << val << endl;
	cout << r << endl;

	//int& r2; �Ұ���
	//int& r3 = 10; �Ұ���

	const int& r4 = 10; // ���ȭ �Ǿ �ٽ� r4�� ������ ���� ���⿡ ����

	//&&�� &�ΰ��� �ǹ̰� �ƴ϶� &&ó�� ���� ��. &�� &&�� ���α׷����� �ǵ��� ǥ���ϱ� ���� �����.

	int&& rr = 10; //const int rr�̶�� �����.

	return 0;
}
