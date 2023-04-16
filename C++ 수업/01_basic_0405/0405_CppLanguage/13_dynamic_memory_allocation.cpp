#include <iostream>

struct Test
{
	int a;
	int b;
	std::string str;

	void printNUM()
	{
		std::cout << "Hello" << std::endl;
	}
};

int main()
{
	//int* ptr = (int*)malloc(5 * sizeof(int));
	//if (ptr == NULL)
	//	exit(1); //예외 처리를 해줬어야 안전했음
	//free(ptr);
	//ptr = NULL;

	//int* ptr1 = new int; //C++ 동적할당
	//delete ptr; //해제, 널 초기화 해주지 않아도 됨

	//int* ptr2 = new int(7); //크기를 직접 초기화
	//delete ptr2;

	//int* ptr3 = new int{ 7 };
	//delete ptr3;

	//int* ptr4 = new(std::nothrow) int{ 7 }; //안정적으로 예외처리를 해주기 위해서 이렇게 초기화

	//if (ptr4 == nullptr) //예외 처리
	//	std::cout << "Error";

	//if (ptr4 != nullptr)
	//	delete ptr4;
	//
	//int* arr = new int[10]{ 1, 2, 3, 4, 5, 6 };
	//delete[] arr;

	////포인터 배열을 2차원처럼 사용할 수 있다.
	//int** ptrArr = new int* [5];

	//ptrArr[0] = new int[10];
	//ptrArr[1] = new int[10];
	//ptrArr[2] = new int[10];
	//ptrArr[3] = new int[10];
	//ptrArr[4] = new int[10];

	////지울때에는 안에 것부터 지우고 바깥을 지움
	//for (int i = 0; i < 5; i++)
	//	delete[] ptrArr[i];

	//delete ptrArr;

	Test* test = new Test; //malloc으로 해보기.

	test->a = 10;
	test->b = 20;
	test->str = "hello";
	test->printNUM();

	//malloc과 new의 차이 : malloc은 구조체에서 pod(plain old data : 연속된 메모리) 타입을 인자로 받아와서 쓸 수 있음
	//string, 함수 같은 건 pod 타입이 아니라서 malloc 쓸 수 없음.

	return 0;
}

/*
<과제>

빙고 게임 했던 거
함수 등등 밖으로 빼는 작업해 보기(빙고 개수 카운트, 빙고 중복 체크, 빙고 그리기 등)
빙고 자체를 포인터로 받아오기


섯다
족보는 간단하게 땡까지만(1땡부터 10땡, 끝(?))
플레이어 수 입력
플레이어 이름 각각 입력

플레이어들이 갖고 있는 패 랜덤으로 주고, 건 돈, 결과값 뽑고,
계속할지 그만할지 정하기 방식으로.

*/