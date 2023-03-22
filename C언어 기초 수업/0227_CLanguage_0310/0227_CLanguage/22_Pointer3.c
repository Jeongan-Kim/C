#include <stdio.h>

//주소값을 전달해서 사용하기 위해 포인터를 사용한다.

void doublePointer();//이중 포인터, **로 표현, 주소의 주소를 전달하는 포인터 **dptr = *ptr
void swap_ptr(int num1, int num2);
void swap_ptr1(int* ptr1, int* ptr2);
void swap_ptr2(int** dptr1, int** dptr2);
void MaxAndMin(int* arr/* 매개변수 */); //배열을 매개변수로 넣을때 포인터를 이용해서 넣을 수 있음(1차원 배열의 경우)


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
		printf("함수 밖 num1 : %d, num2 = %d\n\n\n", num1, num2);


		swap_ptr1(ptr1, ptr2);
		printf("함수 밖 num1 : %d, num2 = %d\n", num1, num2); //주소를 통해 값을 바꿨기 때문에, 함수가 끝나도 값이 변경된 채로 있게 되는 것.
		printf("함수 밖 *ptr1 : %d, *ptr2 = %d\n\n\n", *ptr1, *ptr2);

		swap_ptr2(dptr1, dptr2);
		printf("함수 밖 num1 : %d, num2 = %d\n", num1, num2); 
		printf("함수 밖 **dptr1 : %d, **dptr2 = %d\n\n\n", **dptr1, **dptr2); // 주소가 바뀌어서 num1 의 주소가 *dptr2가 된 것.

	}

#pragma endregion

//#pragma region 이중 포인터 변수의 활용(과제)
//
//
//	{
//		int* maxPtr = 0; //5
//		int* minPtr = 0; //1
//		int arr[5]; // 1 2 3 4 5
//
//		for (int i = 0; i < 5; i++)
//		{
//			printf("정수 입력 %d : ", i + 1);
//			scanf_s("%d", &arr[i]);
//		}
//
//		MaxAndMin(); //최대값 최소값이 나오게끔
//
//		printf("최대 : %d, 최소 : %d \n", *maxPtr, *minPtr); // 5, 1
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

	**dptr = 6.15; //이중포인터 이용해서 num 초기화하는 것
	printf("num : %g\n", num);

}

void swap_ptr(int num1, int num2)
{
	int temp = NULL;

	temp = num1;
	num1 = num2;
	num2 = temp;

	printf("함수 안 num1 : %d, num2 = %d\n", num1, num2);
}

void swap_ptr1(int* ptr1, int* ptr2)
{
	int* temp = NULL;

	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;

	printf("함수 안 *ptr1 : %d, *ptr2 = %d\n", *ptr1, *ptr2);


	return;
}

void swap_ptr2(int** dptr1, int** dptr2)
{
	int* temp = NULL;

	temp = *dptr1;
	*dptr1 = *dptr2;
	*dptr2 = temp; //주소를 변경하는 것

	printf("함수 안 **dptr1 : %d, **dptr2 = %d\n", **dptr1, **dptr2);

	//주소를 바꾼다는 것
	//int a = 0;
	//int b = 5;
	//int* ptr = &a;
	//*ptr = 10;

	//ptr = &b;
	//*ptr = 50;

	return;
}
