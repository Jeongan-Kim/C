#include <iostream>
#include "02_myArray.h"
//#include "02_myArray.cpp"//템플릿 정의 부분을 굳이 나누고 싶다면. 헤더에 넣어버림.
//이것도 정석은 아니어서 inl 파일을 추가해서 작업하면 됨.
#include "02_myArray.inl"
using namespace std;

int main()
{
	myArray<int> myArr(10); //int형 10개짜리 동적할당을 한 것
	myArr.Print();

	return 0;
}