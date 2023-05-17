#include <iostream>

using namespace std;

struct person
{
	void __thiscall Print(/* person* */)
	{
		cout << age << endl;
	}

	int age;
	float weight = 50.0f;
	string name = "Jeongan";
};

int main()
{
	person p1;

	p1.Print();
	//person::Print(); //이렇게는 불가능
	return 0;
}

/*
* 
* 과제
함수 호출 규약(function calling convension) 알아보기
*/