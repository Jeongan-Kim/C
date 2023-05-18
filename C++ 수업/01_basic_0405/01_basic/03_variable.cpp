#include <iostream>


int main()
{
	//초기화
	int x = 10; //copy initialization
	int y(10); // direct initialization
	int z{ 10 }; //uniform initialization

	int a = 1.1; //warning 컴파일 오류는 안나지만 더 안전하게 해보라 경고 나옴. 0.1이 잘리기때문
	//int b{ 1.1 }; //error int 형에 double형을 넣엇다는 것이 명확하므로 오류
	char c = 500; //warning 값이 잘림
	//char d{ 500 }; //error 

	/*
		limits 한계값
	*/

	std::cout << std::numeric_limits<short>::max() << std::endl;
	std::cout << std::numeric_limits<int>::min() << std::endl;
	std::cout << std::numeric_limits<int>::max() << std::endl;
	std::cout << std::numeric_limits<float>::min() << std::endl;
	std::cout << std::numeric_limits<float>::max() << std::endl;

	/*
		casting
	*/

	int i = 10;
	float k = 10.0f;

	std::cout << k << std::endl;
	std::cout << (int)k << std::endl; //(int)k : 명시적 형변환 << C스타일, 강제적
	std::cout << int(k) << std::endl; //C++스타일
	std::cout << static_cast<int>(k) << std::endl; //C++스타일, 제일 안전, 제일 많이 씀

	/*
		const vs constexpr
	*/
	const int c1(123); //직접 초기화
	//const는 자료형이 런타임때 정해짐

	int i1 = 10;
	const int c2 = i1; //상수를 변수로 초기화,

	int arr1[c1]; //c1이 상수라서 배열에 넣을 수 있음.
	//int arr2[c2]; // 변수를 넣은 c2는 자료형이 어떤 것인지 정해지기 전이므로 불가능

	constexpr float PI = 3.141592f;

	float PI2 = 3.141592f;
	//constexpr float PI3 = PT2; //불가능, 상수를 넣어줘야 함

	constexpr int arrSize = 10;
	int arr[arrSize];


	return 0;
}