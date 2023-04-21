#include <iostream>

//객체 소멸될 때 반드시 호출되는 소멸자.
//반환형이 없음. 
//할당된 것을 해제하는 용도로 사용

using namespace std;

class Test
{
public:
	Test() //class가 생성될 때 무조건 실행됨
	{
		cout << "Constructor" << endl;
	}

	~Test() //class가 없어질 때 무조건 실행됨
	{
		cout << "Destructor" << endl;
	}
};

class IntArray
{
public:
	IntArray(const int& inLength)
	{
		length = inLength;
		arr = new int[length]; //배열 동적할당
		cout << "constructor" << endl;
	}

	~IntArray()
	{
		delete[] arr; //배열 동적할당 해제
		cout << "destructor" << endl;
	}

private :
	int* arr = nullptr;
	int length = 0;
};

int main()
{
	Test test1;

	cout << "############### 1" << endl;
	{
		cout << "############### 2" << endl;
		Test test2; //지역 변수이므로 지역 벗어나면 해제되면서 소멸자가 실행되는 것을 볼 수 있음
		cout << "############### 3" << endl;
	}
	cout << "############### 4" << endl;

	while (true)
	{
		IntArray myArr(1000); // 터지게 되니 소멸자로 해제해주는 작업이 필요함.
	}
	return 0;
}