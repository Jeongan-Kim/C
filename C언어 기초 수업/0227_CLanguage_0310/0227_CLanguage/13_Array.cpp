#include <stdio.h>
#include < stdlib.h>
#include <time.h>

#define ARRSIZE 5

int get_2(void)
{
	return 2;
}

//������ �ߺ����� ��� ���
void randomnumber();

int main()
{
	int floor101, floor102, floor103, floor104;
	int floor201, floor202, floor203, floor204; //�ʹ� ���� ������ �����ϱ� �������� ����ϴ� ���� '�迭'

	//�迭 : ���� �ڷ����� ������ ������ �Ҷ�, ���� ���� �����͸� �ٷ� ��.
	int floor[40]; //int�� �迭 40�� ����, [ ] : index
	float farr[3];
	double darr[5]; //5�� ¥�� ������ ������ ����.

	//�迭 �ʱ�ȭ(3����� 0��°, 1��°, 2��°�� 3���� �Ǵ� ��)
	int arr1[3] = { 1, 2, 3 }; // ���� ������ �ʱ�ȭ�� ��.
	int arr2[3] = { 0 }; //��� 0���� �ʱ�ȭ.
	int arr3[5] = { 1, 2, 3 }; // 1, 2, 3, 0, 0���� �ʱ�ȭ ��.
	int arr4[ARRSIZE] = { 0 };
	int arr5[] = { 1, 2, 3 }; // �ʱ�ȭ�� ���� ������ arr5�� ũ�Ⱑ 3���� ����

	char arr6[5] = { 'A', 'B', 'C' }; //�ʱ�ȭ �� �� �������� �׳� 0, 0���� �ʱ�ȭ
	int a = 1;
	printf("%c, %c, %c\n", arr6[0], arr6[a], arr6[get_2()]);

	printf("%c", arr6[3]); //�� ��, 5�� ������° ���Ҹ� ������� �����Ƿ� ������ ��� ����.

	printf("\n");

	int arr7[3] = { 0, 1, 2 }; //int �� 3���� �������� �����Ƿ� 12byte
	printf("%d %d %d\n", arr7[0], arr7[1], arr7[2]);
	printf("%p %p %p\n", &arr7[0], &arr7[1], &arr7[2]);//16������ �� ���� ��� ����Ǿ� �ִ��� �ּҸ� �� �� ����.

	printf("%d\n", sizeof(arr7)); //��ü ������
	printf("%d\n", sizeof(arr7) / sizeof(int)); //�ϳ��� ������

	int size = sizeof(arr7) / sizeof(int);

	for (int i = 0; i < size; i++) //�� �迭 ���� �ε����� �� ���� ����ϴ� �ݺ���
	{
			printf("%d ", arr7[i]);
	} 

	randomnumber();

	return 0;
}

void randomnumber()
{
	srand((unsigned int)time(NULL)); // �����Լ��� �õ尪�� �������ִ� �Լ�, �ݺ��� �ȿ� ������ ���� ���� ����, �ֳĸ� �õ尡 �ʴ����ε� �ݺ����� �׺��� �� ���� ���Ƽ� ���� ���� ����.
	int number[10] = { 0 };

	for (int i = 0; i < 10; i++)
	{
		number[i] = rand() % 10 + 1;

		for (int j = 0; j < i; j++)
		{
			if (number[i] == number[j])
			{
				i--; //i�� ++�� ���̹Ƿ� �ϳ� �ٿ��� �ٽ� �̾ƿ�����
				break;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", number[i]);
	}
}

/*
	�ζ� �����
	1 2 3 4 5 6 B(���ʽ�)
	�� ������ �ϵ�
	... 5����� ����ϱ�


*/
