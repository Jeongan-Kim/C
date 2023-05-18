#include <iostream>

int main()
{
	//포인터 변수는 반드시 null 로 초기화 해줘야 했었음
	int* ptr = nullptr; //NULL이 아니라 nullptr
	int* ptr2(nullptr);
	int* ptr3{ nullptr };

	std::nullptr_t nptr; //무조건 null만 받는 ptr(잘 쓰이지 않음)

	return 0;
}