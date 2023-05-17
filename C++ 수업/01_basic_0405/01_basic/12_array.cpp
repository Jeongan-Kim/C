#include <iostream>
#include <array>

int main()
{
	using namespace std;

	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[]{ 1, 2, 3, 4, 5 }; //c++에서는 =없어도 됨
	//int arr3[](1, 2, 3, 4, 5); //이건 불가능
	
	/*
		STL : Standard Template Libraries
		배열 구조를 간단하게 짜고 싶을때 사용

	*/

	//< >: templete
	std::array<int, 5> arr4; //int 가 5개인 arr4라는 배열이 선언됨, 더 직관적
	array<int, 5> arr5{ 1, 2, 3, 4, 5 }; //초기화도 가능

	cout << arr5[0] << endl;
	cout << arr5[1] << endl;
	cout << arr5.at(2) << endl; //at으로 원소에 접근 가능
	cout << arr5.at(3) << endl;
	cout << arr5.at(4) << endl;
	cout << arr5.size() << endl; //size()로 사이즈 측정 가능

	//cout << arr5[5] << endl; //쓰레기값 나오지만 어쨌든 접근은 됨.
	//cout << arr5.at(5) << endl; //예외 처리가 되어서 터짐. 대신 느림. 안정적.

	return 0;
}