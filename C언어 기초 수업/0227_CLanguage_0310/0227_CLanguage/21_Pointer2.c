#include <stdio.h>

void pointer_arr();
void pointer_operation();


int main()
{
	/*pointer_arr();*/

	/*pointer_operation();*/

	float a = 1.234567f;
	int* pa = &a;

	printf("%d", *pa);

	return 0;
}

void pointer_arr()
{
	int arr[3] = { 0, 1, 2 };

	printf("�迭�� �̸� : %p\n", arr); //�迭�� �̸��� ���������� ù ��° �ּҿ� ����.
	printf("ù ��° ��� : %p\n", &arr[0]); //������ ��Ҵ� int ũ�⸸ŭ ������� ����ȴ�.(4byte)
	printf("�� ��° ��� : %p\n", &arr[1]);
	printf("�� ��° ��� : %p\n", &arr[2]);

	//arr = &arr[1]; �̷��� ������ �ȵ�(�ּҰ��� �����ϴ� ���̶�)
	/*
										������ ����			vs			�迭�� �̸�
		�̸� ����?							����								����
		������ ��Ÿ���ų� �����ϴ°�?		�޸��� �ּ� ��					�޸��� �ּ� ��
		�ּҰ��� ������ �����Ѱ�?			����	(�ʱ�ȭ�ϸ� ��)					�Ұ���
	*/

	printf("\n");

	int arr1[3] = { 1, 2, 3 };
	double arr2[3] = { 1.1, 2.2, 3.3 };

	printf("%d %g\n", *arr1, *arr2); //%g�� float�� �ּ� ��� 

	*arr1 += 100;
	*arr2 += 120.4;

	printf("%d %g\n", arr1[0], arr2[0]); // arr1[0] == *arr1�̹Ƿ� �̷��Ե� �� �� ����

	printf("\n");

	int* ptr = &arr1[0]; // arr1�� ������ ���� �ּҸ� ���� �־��ִ� ��.

	printf("%d %d\n", ptr[0], arr1[0]);
	printf("%d %d\n", ptr[1], arr1[1]); //�����͵� �迭�� �ʱ�ȭ�Ǵ� ���ΰ�?
	printf("%d %d\n", ptr[2], arr1[2]);
	printf("%d %d\n", *ptr, *arr1);
}

void pointer_operation()
{
	int* ptr2 = 0x0010;
	double* ptr3 = 0x0010; //�̴� ������ �ʱ�ȭ�� �ƴϾ C���������� ����, ���ڸ� �����Ϳ� �ʱ�ȭ�� �� �����Ƿ�.

	printf("%p %p\n", ptr2 + 1, ptr2 + 2);
	printf("%p %p\n", ptr3 + 1, ptr3 + 2); //8�� �����ϴµ� 10 -> 18 -> 26? ���� Ȯ���� ����

	printf("\n");
	//n * sizeof(type)    n:������, type:������ Ÿ��    int �� ��� 1 �����Ҷ� 4�� ����

	printf("%p %p\n", ptr2, ptr3);
	ptr2++;
	ptr3++;
	printf("%p %p\n", ptr2, ptr3);

	/*
	*ptr = 2
	ptr = �ּ�

	arr = �ּ�
	&arr[0] = �ּ�
	arr[0] = ��
	&a =�ּ�
	*/

	/*
		arr[i] == *(arr + i)
	*/

	int arr4[3] = { 11, 22, 33 };
	int* ptr4 = arr4;
	printf("%d %d %d\n", *ptr4, *(ptr4 + 1), *(ptr4 + 2));

	printf("%d\n", *ptr4); ptr4++; //11
	printf("%d\n", *ptr4); ptr4++; //22
	printf("%d\n", *ptr4); ptr4--; //33
	printf("%d\n", *ptr4); ptr4--; //22
	printf("%d\n", *ptr4); // 11

}


/*
ȸ��(��Į�ڸ���)
���ڸ� �Է�������, ȭ������ �ƴ��� üũ�ϴ� ���α׷� �����
level
*/
