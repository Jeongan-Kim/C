#include <stdio.h>

//포인터 : 주소라고 생각하면 좋음, 이름이나 집 주소 등등 여러 주소가 있음(16진수로) , 포인터도 크기가 있음
//포인터 변수 : 포인터의 값을 입력하는 변수/ 4byte(x86), 8byte(x64)

int main()
{
	int num = 7;
	int* pnum; //포인터 넘버 변수의 선언
	pnum = &num; //num의 주소(시작 부분의)를 포인터 변수에 넣고 직접 num을 건드릴 것임.

	//int* pnum1 = &5;  변수를 넣어줘야 주소값이 선언됨.

	printf("%d\n", *pnum);
	printf("%d\n\n", num);

	*pnum = 20; //*pnum == num //포인터 변수가 가리키는 값을 직접 초기화

	printf("%p\n", pnum); //%p는 주소값
	printf("%d\n", *pnum);
	printf("%d\n", num);
	printf("%p\n", &num);
	printf("%d\n", (int)sizeof(pnum));

	int* ptr; //쓰레기값으로 초기화됨. 의미가 없음. 나중에 초기화를 해 주고 싶으면 NULL로 초기화해놓으면 됨.
	int* ptr = NULL;


	return 0;
}