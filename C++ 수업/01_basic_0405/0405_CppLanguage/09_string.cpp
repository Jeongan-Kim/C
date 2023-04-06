#include <iostream>
#include <string> //.h말고

using namespace std;

int main()
{
	char myStr[] = "Hello C"; //C스타일 문자열
	const char* myStr2 = "Hello C"; //포인터로 선언하는 문자열은 상수로 초기화 되는 거라 수정이 불가. (C++에서는 상수화를 꼭 해줘야 함.)

	string str = "Hello C++"; //C++스타일

	cout << str.size() << endl; //NULL제외 길이
	cout << str.length() << endl; //NULL제외 길이

	string a("Hello, ");
	string b("C++!!"); //직접 초기화

	string c = a + b; //문자열 연산
	cout << c << endl;

	c += ", good!!";	
	cout << c << endl;

	cout << c[4] << endl; //문자열의 4번째 원소 출력

	return 0;
}