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

	printf("%d %g\n", *arr1, *arr2); //%g는 float형 주소 출력 

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


/*
회문(데칼코마니)
문자를 입력했을때, 화문인지 아닌지 체크하는 프로그램 만들기
level
*/
