#include <stdio.h>


//���̰� ���� �� 1���� ���� �迭 a, b�� �Ű������� �־����ϴ�. a�� b�� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.
//�̶�, a�� b�� ������ a[0] * b[0] + a[1] * b[1] + ... + a[n - 1] * b[n - 1] �Դϴ�. (n�� a, b�� ����)
//���ѻ���
//a, b�� ���̴� 1 �̻� 1000 �����Դϴ�.
//a, b�� ��� ���� - 1000 �̻� 1000 �����Դϴ�.
//����� ��
//a   b   result
//[1, 2, 3, 4][-3, -1, 0, 2] 3
//[-1, 0, 1][1, 0, -1] - 2
//����� �� ����
//����� �� #1
//a�� b�� ������ 1 * (-3) + 2 * (-1) + 3 * 0 + 4 * 2 = 3 �Դϴ�.
//����� �� #2
//a�� b�� ������(-1) * 1 + 0 * 0 + 1 * (-1) = -2 �Դϴ�.


void solution(int a[], int size_a, int b[]);
void scanf(int a[], int size_a);

int main()
{
	//int a[3] = { -1, 0, 1 };
	//int b[3] = { 1, 0, -1 };
	int arr_size;
	int a[1000];
	int b[1000];

	printf("���̰� ���� �� 1���� ���� �迭 a, b�� �Է��� �ּ���.\n");
	printf("���� ���� �迭�� ���̸� �����ϼ���.(1~1000) : ");

	while (true)
	{
		scanf_s("%d", &arr_size);
		if (arr_size > 1000 || arr_size < 0)
		{
			printf("���̰� 1 �̻� 1000 ���ϰ� �ƴմϴ�. �ٽ� �Է��� �ּ���.\n");
		}
		else
			break;
	}

	printf("a �迭(���� ���� : -1000 ~ 1000) : ");
	scanf(a, arr_size);

	printf("\n");

	printf("b �迭(���� ���� : -1000 ~ 1000) : ");
	scanf(b, arr_size);

	printf("\n");

	solution(a, arr_size, b);

	return 0;
}

void solution(int a[], int size_a, int b[])
{
	int inner_product = 0;
	printf("a�� b�� ������ ");

	for (int i = 0; i < size_a; i++)
	{
		if (a[i] < 0)
			printf("(%d) ", a[i]);
		else 
			printf("%d ", a[i]);

		printf("* ");

		if (b[i] < 0)
			printf("(%d) ", b[i]);
		else
			printf("%d ", b[i]);

		if (i < size_a - 1)
			printf("+ ");

		inner_product += a[i] * b[i];
	}
	printf("= %d\n", inner_product);
	
}

void scanf(int a[], int size_a)
{
	for (int i = 0; i < size_a; i++)
	{
		scanf_s("%d", &a[i]);
		while (true)
		{
			if (a[i] > 1000 || a[i] < -1000)
				printf("���� ������ ��� ���Դϴ�. �ٽ� �Է��� �ּ���.\n");
			else
				break;
		}
	}
}
