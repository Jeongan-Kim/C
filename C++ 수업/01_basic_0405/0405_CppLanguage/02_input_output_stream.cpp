#include <iostream>

//stream : << >>를 뜻함.(입력, 출력)

int main()
{
	// >> : input operator
	// << : output operator

	int a;
	std::cin >> a; // scanf같은거
	std::cout << "입력한 숫자 : " << a << std::endl << std::endl; //한줄 더 띄기

	/*
		조정자(manipulator)
	*/

	int num = 100;

	std::cout << std::oct << num << std::endl;
	std::cout << std::dec << num << std::endl;
	std::cout << std::hex << num << std::endl;

	std::cout << std::showbase << std::showpos; //한번 쓰면 showbase가 켜진 것. showbase(어떤 진수인지), showpos(부호)
	std::cout << std::oct << num << std::endl;
	std::cout << std::dec << num << std::endl;
	std::cout << std::hex << num << std::endl;
	std::cout << std::noshowbase << std::noshowpos; //한번 쓰면 showbase가 꺼진 것.


	bool is_true = true;
	bool is_false = false;

	std::cout << std::boolalpha; //이것도 한번 쓰면 켜짐, true false를 영어로 쓰라는 말
	std::cout << is_true << std::endl;
	std::cout << is_false << std::endl;

	std::cout << std::noboolalpha; //끄기
	std::cout << is_true << std::endl;
	std::cout << is_false << std::endl;

	return 0;
}