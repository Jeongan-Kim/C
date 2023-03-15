#include <stdio.h>

/*
����(local) ����
����(global) ���� : main ���� ���� ����
*/

//���� ����
int global; // ���α׷� ��ü�� ��ȿ ����, �������� ������ ���ؼ��� ������� �ʴ� �� ����, �ʱ�ȭ ���� ������ �ڵ����� 0���� ��

char var1 = 'G';

void LocalCount();
void StaticCount();

int main()
{
	printf("�ʱ�ȭ ���� ���� global �� : %d\n", global);

	printf("main������ var1 : %c\n", var1);
	//���� ���� : Ư�� ���������� ����� �� �ִ� ����, ��ȣ �ȿ� ������ ���� ������� ���� ��.
	{
		char var1 = 'L';
		printf("{}������ var1 : %c\n", var1); // ����� �� ���� ����� �������� ����� ���� �켱���� ��.(�Ұ�ȣ�� ����)
	}

	printf("main������ var1 : %c\n", var1); //���� �ٲ� �� �ƴ϶� ���� �ۿ����� ���� ���� ���ǰ� ������.

	for (int i = 0; i < 5; i++)
	{
		LocalCount();
		StaticCount();
	}
	return 0;
}

void LocalCount()
{
	int count = 1;

	printf("local count : %d\n", count);
	count++;
}

void StaticCount()
{
	static int count = 1; //static : ���� ����, ���α׷� ���� �ÿ� �Ҹ��. �� ó�� ������ ��� �ϴ� ���� ������ �ٸ��� ������ ���� ���ܳ�. ���� �������� ������.
	//static�� ���� ���� �ÿ��� �ʱ�ȭ�� ��.
	printf("static count : %d\n", count);
	count++;
}
