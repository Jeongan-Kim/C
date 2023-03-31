#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//c언어의 동적할당
//malloc : 동적할당  => 우리가 직접 할당해주고 직접 해제해 줘야 함(안그럼 메모리 누수가 일어남). 그래서 런 타임때 크기가 결정된다. (반대 경우는 컴파일 중에 크기가 결정됨)


void dynamic_allocation();
char* scanName();


char name[30]; //문제 해결을 위해 전역 변수로 빼버리면 해결됨

char* readName()//이름을  쓰고 읽어오는 함수를 만들어 보자.
{
	/*char name[30];*/
	printf("이름을 입력하시오 : ");
	gets(name); //공백을 포함해서 받아오는 것.

	return name;
}

//함수를 들어갔다가 나와도 값이 유지되게 늘 전역변수 취급을 해야 하는 등의 작업을 하지 않아도 되는 게 "동적 할당"!

int main()
{
	//{
	//	char* name1;
	//	char* name2; 

	//	name1 = readName();
	//	printf("name1 : %s\n", name1);

	//	name2 = readName(); //이 함수가 끝나고 변수 메모리 할당이 해제되어 
	//	printf("name2 : %s\n", name2); //출력해서 제대로 값이 안나오게됨. (지역 변수 문제와 비슷)
	//}

	//dynamic_allocation();
	{
		char* name = scanName();

		printf("name : %s\n", name);

		free(name);
		name = NULL;
	}
	
	return 0;
}

//	<과제>
// 백준 블랙잭(https://www.acmicpc.net/problem/2798)
//
//재귀 사용, 안되면 for문 사용
//
//brute(난폭한) 모든 경우를 확인하겠다는 뜻

void dynamic_allocation() //우리가 주소에 직접 접근을 하기 위해서는 포인터를 써야 함.
{
	//malloc
	{
		int* ptr = NULL;
		int num = 5;

		ptr = (int*)malloc(sizeof(int) * num); //int 형 포인터, int형짜리이고 길이가  num인 것을 할당하겠다는 뜻


		if (ptr == NULL)
		{
			printf("메모리 할당 실패!!\n");

			exit(EXIT_FAILURE); //exit(0);이랑 같음  0이면 정상 종료, 1이면 오류났다는 뜻 => 1
			//exit(EXIT_SUCCESS); //정상 반환 => 0
		}

		printf("Before dfree 0x%p\n", ptr);

		free(ptr); //할당을 해제하는 것

		printf("After dfree 0x%p\n", ptr); //해제 했음에도 주소가 출력됨 => 허상 포인터(dangling pointer) : 해제된 공간을 가리키고 있는 포인터

		ptr = NULL; //그래서 NULL로 초기화까지 해줘야 함.

		printf("After dfree 0x%p\n", ptr); //공간 사라짐
		
		
		//free하고 NULL로 초기화 두번하기 귀찮으니 define으로 해줄 수도 있음. => free만 해도 NULL초기화까지 되게끔.
#define FREE(ptr) if(ptr != NULL) {free(ptr); ptr = NULL;}
	}


	//calloc
	{
		int size = 0;

		printf("동적 할당 할 int형 변수의 메모리 공간 입력 => ");
		scanf_s("%d", &size);

		int* ma, * ca;
		ma = (int*)malloc(sizeof(int) * size);
		ca = (int*)calloc(size, sizeof(int)); // 멀록과 형태가 다를뿐 비슷함. 해석은 약간 다를 수 있음

		printf("\n초기화 전\n\n");
		for (int i = 0; i < size; i++)
		{
			printf("ma[%d] : %d\n",   i, ma[i]); //쓰레기값
			printf("ca[%d] : %d\n\n", i, ca[i]); //0
		}
		//malloc은 초기화가 안돼서 쓰레기 값이 나오고 calloc은 초기화가 자동으로 되어서 0이 나옴 => 일단 쓰레기는 안나오게 0으로 초기화 하는 건가?

		for (int i = 0; i < size; i++) //그래서 malloc을 초기화한 후에는 제대로 둘다 0으로 나옴
		{
			ma[i] = 0;
		}

		printf("\n초기화 후\n\n");
		for (int i = 0; i < size; i++)
		{
			printf("ma[%d] : %d\n", i, ma[i]); //0
			printf("ca[%d] : %d\n\n", i, ca[i]); //0
		}

		//주소 초기화도 필수로 꼭 해주자!
		free(ca);
		ca = NULL;

		free(ma);
		ma = NULL;
	}

	//realloc
	{
		//이미 할당한 후에 공간 확장을 하고 싶을때 사용
		int size = 0;

		printf("동적 할당 할 double형 변수의 메모리 공간 입력 => ");
		scanf_s("%d", &size);

		double* ptr = (double*)calloc(size, sizeof(double));

		printf("\nptr의 할당받은 주소 : %p\n", ptr);

		for (int i = 0; i < size; i++)
			printf("ca[%d] : %lf\n", i, ptr[i]);

		printf("재할당 할 double형 변수의 메모리 공간 입력 => ");
		scanf_s("%d", &size);

		ptr = (double*)realloc((double*)ptr, size);
		printf("\nptr의 재할당받은 주소 : %p\n", ptr);

		for (int i = 0; i < size; i++)
			printf("ca[%d] : %lf\n", i, ptr[i]); //재할당된 공간은 초기화가 안됨. 확장할때 뒤에 다른 할당된 메모리라 연달아 만들어지지 않는다면 연달아 만들수 있는 새로운 주소를 찾아 재할당되기도 함.

		printf("\n");

		free(ptr);
		ptr = NULL;
	}
	{
		int n = 5;
		double* ptr = (double*)malloc(n * sizeof(double));

		if (ptr != NULL)
		{
			for (int i = 0; i < n; i++)
				printf("ptr[%d] : %lf\n", i, ptr[i]);

			printf("\n");

			for (int i = 0; i < n; i++) //포인터 연산
				*(ptr + i) = (double)i;

			for (int i = 0; i < n; i++)
				printf("ptr[%d] : %lf\n", i, ptr[i]);
			printf("\n");

			free(ptr);
			ptr = NULL;
			
		}
	}


	//내부 단편화 문제 : 메모리 남은 공간이 충분하지만 조각조각 짤려 있어서 (구조체처럼 고정단위 할당 때문에) 할당이 불가한 문제
	//외부 단편화 문제 : 동적할당을 하면서 할당, 해제를 반복하면서 사이사이 틈이 생겨서. 공간은 충분한데 할당이 불가한 문제
	//허상 포인터 || 메모리 누수 현상 : 동적할당 후 메모리 할당 해제를 안해서. 포인터가 할당 해제됨 공간을 가리키는 문제 || 그 공간만큼을 못 사용하는 문제.
	
}

char* scanName()
{
	char buffer[100] = { 0 };

	printf("이름을 입력하시오 : ");
	gets(name); 
	//scanf_s("%s", buffer, sizeof(buffer)); 도 가능

	int size = strlen(buffer) + sizeof((char)('\0')); //문자 개수 + NULL공간까지 세어줌

	if (size == sizeof((char)('\0')))
		return NULL;

	char* name = (char*)calloc(size, sizeof(char));

	if (name != NULL)
		strcpy_s(name, size, buffer);

	return name;
}
