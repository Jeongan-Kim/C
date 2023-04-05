#include <iostream> //input output 흐름(출력) , .h 같은 거 안붙음. 흘려 보낸다는 뜻!
#include <cstdio> //<stdio.h c언어의 헤더파일 사용하고 싶을때.

int main()
{
	std::cout << "Hello, c++!!" << std::endl; //endl은 개행(\n)과 같음, 출력 버퍼에 들어갔다가 지워지면서 띄워줘서 \n보다 좀 느림.

	std::cout << "Hello, c++!!" << "\n";

	int x = 10;
	int y = 20;

	std::cout << "x = " << x << "y = " << y << std::endl;
	std::cout << "x = " << x << " " << "y = " << y << std::endl; // 중가에 띄우고 싶으면 이렇게도 가능.
	std::cout << "x + y = " << x + y << std::endl;

	return 0;
}