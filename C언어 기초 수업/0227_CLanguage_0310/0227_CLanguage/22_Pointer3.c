#include <stdio.h>

//�ּҰ��� �����ؼ� ����ϱ� ���� �����͸� ����Ѵ�.

void doublePointer();//���� ������, **�� ǥ��, �ּ��� �ּҸ� �����ϴ� ������ **dptr = *ptr
void swap_ptr(int num1, int num2);
void swap_ptr1(int* ptr1, int* ptr2);
void swap_ptr2(int** dptr1, int** dptr2);
void MaxAndMin(int* arr/* �Ű����� */); //�迭�� �Ű������� ������ �����͸� �̿��ؼ� ���� �� ����(1���� �迭�� ���)


int main()
{
	//doublePointer();

#pragma region SWAP
	{
		/*
			call by value  VS  call by reference
		*/
		int num1 = 10;
		int num2 = 20;

		int* ptr1 = &num1;
		int* ptr2 = &num2;

		int** dptr1 = &ptr1;
		int** dptr2 = &ptr2;

		swap_ptr(num1, num2);
		printf("�Լ� �� num1 : %d, num2 = %d\n\n\n", num1, num2);


		swap_ptr1(ptr1, ptr2);
		printf("�Լ� �� num1 : %d, num2 = %d\n", num1, num2); //�ּҸ� ���� ���� �ٲ�� ������, �Լ��� ������ ���� ����� ä�� �ְ� �Ǵ� ��.
		printf("�Լ� �� *ptr1 : %d, *ptr2 = %d\n\n\n", *ptr1, *ptr2);

		swap_ptr2(dptr1, dptr2);
		printf("�Լ� �� num1 : %d, num2 = %d\n", num1, num2); 
		printf("�Լ� �� **dptr1 : %d, **dptr2 = %d\n\n\n", **dptr1, **dptr2); // �ּҰ� �ٲ� num1 �� �ּҰ� *dptr2�� �� ��.

	}

#pragma endregion

//#pragma region ���� ������ ������ Ȱ��(����)
//
//
//	{
//		int* maxPtr = 0; //5
//		int* minPtr = 0; //1
//		int arr[5]; // 1 2 3 4 5
//
//		for (int i = 0; i < 5; i++)
//		{
//			printf("���� �Է� %d : ", i + 1);
//			scanf_s("%d", &arr[i]);
//		}
//
//		MaxAndMin(); //�ִ밪 �ּҰ��� �����Բ�
//
//		printf("�ִ� : %d, �ּ� : %d \n", *maxPtr, *minPtr); // 5, 1
//	}
//#pragma endregion
	return 0;
}

void doublePointer()
{
	double num = 3.14; // &num == ptr
	double* ptr = &num; //&ptr == dptr
	double** dptr = &ptr;

	printf("&dptr = 0x%p\n", &dptr);
	printf("&ptr = 0x%p\n", &ptr);
	printf("&num = 0x%p\n\n", &num);

	printf("&ptr = 0x%p\n", &ptr);
	printf("&ptr = 0x%p\n\n", dptr);

	printf("&num = 0x%p\n", &num);
	printf("&num = 0x%p\n", ptr);
	printf("&num = 0x%p\n\n", *dptr);

	printf("num : %g\n", num);
	printf("num : %g\n", *ptr);
	printf("num : %g\n\n", **dptr);

	**dptr = 6.15; //���������� �̿��ؼ� num �ʱ�ȭ�ϴ� ��
	printf("num : %g\n", num);

}

void swap_ptr(int num1, int num2)
{
	int temp = NULL;

	temp = num1;
	num1 = num2;
	num2 = temp;

	printf("�Լ� �� num1 : %d, num2 = %d\n", num1, num2);
}

void swap_ptr1(int* ptr1, int* ptr2)
{
	int* temp = NULL;

	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;

	printf("�Լ� �� *ptr1 : %d, *ptr2 = %d\n", *ptr1, *ptr2);


	return;
}

void swap_ptr2(int** dptr1, int** dptr2)
{
	int* temp = NULL;

	temp = *dptr1;
	*dptr1 = *dptr2;
	*dptr2 = temp; //�ּҸ� �����ϴ� ��

	printf("�Լ� �� **dptr1 : %d, **dptr2 = %d\n", **dptr1, **dptr2);

	//�ּҸ� �ٲ۴ٴ� ��
	//int a = 0;
	//int b = 5;
	//int* ptr = &a;
	//*ptr = 10;

	//ptr = &b;
	//*ptr = 50;

	return;
}
