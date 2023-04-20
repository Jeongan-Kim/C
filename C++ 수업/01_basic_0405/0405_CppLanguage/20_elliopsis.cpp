#include <iostream>
#include <cstdarg>

using namespace std;

//�����Լ�
//�Ű������� ������ �͵��� ����� �����ִ� �Լ��� ������
double findAverage(int count, ...) //��� ������ �𸣴ϱ� ... ���� ��
{
	double sum = 0;

	va_list lists;

	va_start(lists, count);

	for (int arg = 0; arg < count; arg++)
	{
		sum += va_arg(lists, int);
	}

	va_end(lists);//�����Ҵ� ������ �ֵ��� ������ �ִ� ��.

	return sum / count;
}

int main()
{
	cout << findAverage(3, 1, 2, 3) << endl;
	cout << findAverage(5, 1, 2, 3, 4, 5) << endl;
	cout << findAverage(3, 1, 2, 3, 4, 5) << endl; // 5���� �־ ī��Ʈ ���� �´� ������ŭ�� ��� ��꿡 ��.

	return 0;
}

/*
���� ���� : C���
��ü ����

*/