#include <stdio.h>

void pointer_arr();
void pointer_operation();
void string_pointer();
void pointer_arr_and_2d_arr();
void pointer_and_const_arr();
void void_pointer();


int main()
{
	pointer_arr();

	pointer_operation();

	string_pointer();

	pointer_arr_and_2d_arr();

	pointer_and_const_arr();
	void_pointer();

	return 0;
}

void pointer_arr()
{
	int arr[3] = { 0, 1, 2 };

	printf("배열의 이름 : %p\n", arr); //배열의 이름은 포인터이자 첫 번째 주소와 같다.
	printf("첫 번째 요소 : %p\n", &arr[0]); //각각의 요소는 int 크기만큼 띄워져서 저장된다.(4byte)
	printf("두 번째 요소 : %p\n", &arr[1]);
	printf("세 번째 요소 : %p\n", &arr[2]);

	//arr = &arr[1]; 이러한 연산이 안됨(주소값을 변경하는 것이라서)
	/*
										포인터 변수			vs			배열의 이름
		이름 존재?							존재								존재
		무엇을 나타내거나 저장하는가?		메모리의 주소 값					메모리의 주소 값
		주소값의 변경이 가능한가?			가능	(초기화하면 됨)					불가능
	*/

	printf("\n");

	int arr1[3] = { 1, 2, 3 };
	double arr2[3] = { 1.1, 2.2, 3.3 };

	printf("%d %g\n", *arr1, *arr2); //%g는 float형 값 출력 

	*arr1 += 100;
	*arr2 += 120.4;

	printf("%d %g\n", arr1[0], arr2[0]); // arr1[0] == *arr1이므로 이렇게도 쓸 수 있음

	printf("\n");

	int* ptr = &arr1[0]; // arr1과 같지만 시작 주소를 직접 넣어주는 것.

	printf("%d %d\n", ptr[0], arr1[0]);
	printf("%d %d\n", ptr[1], arr1[1]); //포인터도 배열로 초기화되는 것인가?
	printf("%d %d\n", ptr[2], arr1[2]);
	printf("%d %d\n", *ptr, *arr1);
}

void pointer_operation()
{
	int* ptr2 = 0x0010;
	double* ptr3 = 0x0010; //이는 적절한 초기화가 아니어서 C버전에서만 가능, 숫자를 포인터에 초기화할 수 없으므로.

	printf("%p %p\n", ptr2 + 1, ptr2 + 2);
	printf("%p %p\n", ptr3 + 1, ptr3 + 2); //8씩 증가하는데 10 -> 18 -> 26? 직접 확인해 보기

	printf("\n");
	//n * sizeof(type)    n:증가량, type:데이터 타입    int 인 경우 1 증가할때 4씩 증가

	printf("%p %p\n", ptr2, ptr3);
	ptr2++;
	ptr3++;
	printf("%p %p\n", ptr2, ptr3);

	/*
	*ptr = 2
	ptr = 주소

	arr = 주소
	&arr[0] = 주소
	arr[0] = 값
	&a =주소
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

void string_pointer()
{
	char str[] = "string";
	printf("%s\n", str);

	str[0] = 'c';
	printf("%s\n", str);

	char* pstr = "ptrSting"; //숫자형 문자열, 첫번째 변수의 주소를 가리키고 있는 변수.
	//pstr[0] = 'c';
	//printf("%s\n", pstr);  //오류남
}

void pointer_arr_and_2d_arr()
{
	float arr[2][4] =
	{
		{1.0f, 2.0f, 3.0f, 4.0f},
		{5.0f, 6.0f, 7.0f, 8.0f}
	};

	//arr == &arr[0] //배열의 이름은 배열의 첫번째 요소의 주소
	//arr == &arr[0][0] == arr[0] == &arr[0]

	printf("&arr[0][0] : 0x%p\n", arr);
	printf("&arr[0][0] : 0x%p\n", arr[0]);
	printf("\n");

	printf("&arr[0][0] : 0x%p\n", *arr); //*arr : 2차원의 배열의 역참조는 첫 행의 주소가 나옴, 2차원이니 1차원의 첫번째 이름인 것
	printf("&arr[0][0] : 0x%p\n", &arr[0]);
	printf("&arr[0][0] : 0x%p\n", &arr[0][0]);
	printf("\n");

	printf("arr[0][0] : %f\n", arr[0][0]);
	printf("arr[0][0] : %f\n", *arr[0]);
	printf("arr[0][0] : %f\n", **arr); // 2차원-> 1차원-> 원소
	printf("\n");

	//int num = 1;
	//int* ptr = &num;

	//ptr, &num : 주소값
	//num, *ptr : 값

	//두 번째 행의 주소
	printf("0x%p\n", (arr + 1));
	printf("0x%p\n", (&arr[1]));
	printf("0x%p\n", (arr[1]));
	printf("0x%p\n", *(arr + 1));
	printf("0x%p\n", (&arr[0] + 1));
	printf("0x%p\n", (&arr[1][0]));
	printf("\n");

	//1행 2열의 값
	printf("%f\n", *(*(arr + 1) + 2)); //행을 정하고 역참조로 열로 나온 뒤 역참조 해서 값을 찍음
	printf("\n");

	int arr1[2][3] =
	{
		{0, 1, 2},
		{3, 4, 5}
	};

	//2차원 배열은 역참조 2번이 아님.
	//int** ptrArr = arr1;
	//printf("%d ", ptrArr[0][0]);

	{
		//2차원 배열을 포인터에 저장시키는 방법, 행 각각을 나눠서 저장하기에 주소가 연달아 들어가지는 않음(?)
		int arr0[3] = { 10, 20, 30 };
		int arr1[3] = { 40, 50, 60 };

		int* ptrArr[2] = { arr0, arr1 }; 

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%d(==%d, %d) => 0x%p\n", ptrArr[i][j], *(ptrArr[i] + j),
					*(*(ptrArr + i) + j), &ptrArr[i][j]); //포인터 변수 배열의 요소 여러가지 표현 방식
			}
			printf("\n");
		}
	}

	{
		//2차원 배열과 그 주소를 각각 프린트 하는 여러가지 방법
		int myArr[2][3] = { {1, 2, 3}, {4, 5, 6} };
		
		int* ptrArr[3];
		ptrArr[0] = myArr[0];
		ptrArr[1] = myArr[1];

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%d %d %d %d 0x%p 0x%p\n",
					myArr[i][j], ptrArr[i][j], *(ptrArr[i] + j), *(*(ptrArr + i) + j),
					&myArr[i][j], &ptrArr[i][j]);
			}
		}
	}
}

void pointer_and_const_arr()
{
	//1
	const int a = 5; //const가 int를 상수화 하여 a가 변할 수 없게 고정
	double const d = 3.14; //const가 앞의 자료형을 상수화
	//const는 앞이나 뒤에 붙이는 것이 둘다 같음. 하나만 있을때는 일반적으로 앞에 붙임

	//2
	const int arr1[5] = { 1, 2, 3, 4, 5 }; //배열 안의 모든 수를 상수화하여 고정
	//arr1[0] = 5; 오류남

	//3
	const double arr2[3] = { 1.0, 2.0, 3.0 };
	//arr2[0] = 5; 오류남
	const double* ptr1 = arr2; //배열을 상수화하면 포인터도 고정을 해줘야 함
	//double* ptr1 = arr2; //배열은 고정이지만 포인터는 고정이 아니므로 바꿀 수 있음

	//*ptr1 = 3.0; // 주소로 값을 변경
	//ptr1[0] = 3.0; // 인덱스 값 이용

	//4
	double const* const ptr3 = arr2;

	//ptr3 += 1;
	//ptr3++; //변경 불가능.

}

void void_pointer()
{
	//자료형이 정해지지 않은 포인터. 어떤 자료형이든 저장할 수 있는 포인터. 대신 그 주소의 값을 출력할 수는 없음 또한 포인터 연산도 불가능.
	//그래서 역참조하면서 출력할때에는 형변환을 해줘야 함.
	//쓸모없어보이지만 형이 정해지지 않은 동적할당을 할때에 씀.

	//void i; void 안에 변수를 넣을 수는 없음

	int num = 10;
	int* p = &num;
	void* vp = p;

	printf("p : %p\n", p);
	printf("vp : %p\n\n", vp);

	printf("*p : %d\n", *p);
	//printf("*vp : %d\n", *vp); // 어떻게 표현해야 알지 몰라서 오류남

	int* p0 = (int*)vp; //vp의 자료형을 int로 형 변환해 줌
	printf("p0 : %d\n", *p0);

	int nums[] = { 1, 2, 3 };
	void* voidptr = nums;

	//printf("%d", *voidptr); 오류
	printf("%d", *(int*)voidptr);
}


/*
회문(데칼코마니)
문자를 입력했을때, 회문인지 아닌지 체크하는 프로그램 만들기
level

영화관 자리 예매하는 프로그램(자리 예매시 A열의 좌석 번호 입력)
예매하면 그 좌석이 x표시 되고, 
같은 자리를 예매하면 예매 완료되었다는 메세지가 뜨는 것.


빙고(포인터 사용 안해도 됨) : 랜덤으로 수(1~25)를 5x5로 찍고, 수를 입력하면 그 자리가 X되는 것)
3빙고되면 끝나게끔
*/
