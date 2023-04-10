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
	//{
	//	/*
	//		call by value  VS  call by reference
	//	*/
	//	int num1 = 10;
	//	int num2 = 20;

	//	int* ptr1 = &num1;
	//	int* ptr2 = &num2;

	//	int** dptr1 = &ptr1;
	//	int** dptr2 = &ptr2;

	//	swap_ptr(num1, num2);
	//	printf("함수 밖 num1 : %d, num2 = %d\n\n\n", num1, num2);


	//	swap_ptr1(ptr1, ptr2);
	//	printf("함수 밖 num1 : %d, num2 = %d\n", num1, num2); //주소를 통해 값을 바꿨기 때문에, 함수가 끝나도 값이 변경된 채로 있게 되는 것.
	//	printf("함수 밖 *ptr1 : %d, *ptr2 = %d\n\n\n", *ptr1, *ptr2);

	//	swap_ptr2(dptr1, dptr2);
	//	printf("함수 밖 num1 : %d, num2 = %d\n", num1, num2); 
	//	printf("함수 밖 **dptr1 : %d, **dptr2 = %d\n\n\n", **dptr1, **dptr2); // 주소가 바뀌어서 num1 의 주소가 *dptr2가 된 것.

	//}

#pragma endregion

#pragma region 이중 포인터 변수의 활용(과제)


	//{
	//	int* maxPtr = 0; //5
	//	int* minPtr = 0; //1
	//	int arr[5]; // 1 2 3 4 5

	//	for (int i = 0; i < 5; i++)
	//	{
	//		printf("정수 입력 %d : ", i + 1);
	//		scanf_s("%d", &arr[i]);
	//	}

	//	MaxAndMin(); //최대값 최소값이 나오게끔

	//	printf("최대 : %d, 최소 : %d \n", *maxPtr, *minPtr); // 5, 1
	//}
#pragma endregion


#pragma region 포인터 배열 vs 배열 포인터
	//포인터를 배열로 갖는 것 (포인터 배열)
	int a = 10, b = 20, c = 30;
	int* pArr[3] = { &a, &b, &c }; //[]가 더 먼저 입력됨 , 따로따로 떨어진 주소들을 모아놓은 것뿐

	printf("%d\n", *pArr[0]);
	printf("%d\n", *pArr[1]);
	printf("%d\n", *pArr[2]);


	//배열을 포인터에 넣어주면 자동으로 포인터에 배열 속 주소가 저장됨.(배열 포인터)
	int arr1[3] = { 0, 1, 2 };
	int arr2[2][3] = {
		{0, 1, 2},
		{3, 4, 5}
	};

	int arr3[3][3] = {
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8}
	};

	int(*ptrArr)[3] = arr1; //[]보다 먼저 포인터()명령이 입력됨. 포인터에 배열을 변수처럼 넣어줬다고 생각하자.

	for (int j = 0; j < 3; j++)
		printf("%d, ", ptrArr[0][j]);
	printf("\n\n");

	ptrArr = arr2;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d, ", ptrArr[i][j]);
		printf("\n");
	}

	printf("\n\n");

	ptrArr = arr3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%d, ", ptrArr[i][j]);
		printf("\n");
	}

#pragma endregion

#pragma region
	{
		int i = 0;
		while (i != 4)
			++i;

		printf("%d\n", i); // 4
	}
	{
		int a = 50;
		int* b;
		 
		b = &a;
		*b += 20;

	}
	{
		int a[5];
		int* p;

		for (int i = 0; i < 5; i++)
			a[i] = i + 10; //10, 11, 12, 13, 14

		p = a;

		for (int i = 0; i < 5; i++)
			printf("%d ", *(p + i));

		printf("\n");
	}
	{
		int arr[][3] = { 1, 2, 3, 4, 5, 6 };

		int* p = arr[1];

		int x = *p; //4
		int y = *(p + 2); //6
	}
	{
		int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		int sum1 = *(*arr + 1) + *(*arr + 2); //2 + 3 = 5
		int sum2 = *arr[1] + *arr[2];//4 + 7 =11
	}
	{
		char str1[20] = "KOREA";
		char str2[20] = "LOVE";

		char* p1 = str1;
		char* p2 = str2;

		str1[1] = p2[2]; //
		str2[3] = p1[4]; //E가 A로 바뀜

		strcat(str1, str2); //둘이 붙임.
		printf("%c\n", *(p1 + 2)); //R

	}
	{
		int arr[2][3] = { 1, 2, 3, 4, 5, 6 };
		int(*p)[3] = NULL; //배열 포인터

		p = arr;

		printf("%d\n", *(p[0] + 1) + *(p[1] + 2)); //2+6=8
		printf("%d\n", *(*(p + 1) + 0) + *(*(p + 1) + 1)); //4+5=9
	}
#pragma endregion
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
