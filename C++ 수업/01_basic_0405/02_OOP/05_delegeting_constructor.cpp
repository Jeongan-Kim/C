#include <iostream>

//위임 생성자 : 어떤 특정 멤버 변수를 다른 걸로 초기화하고 싶을때 사용

using namespace std;

class Student
{
public:
	Student(const int& id, const string& name) //받아오면서 바뀌면 안되니까 const를 붙여서 안전하게
		:id(id), name(name) // 이름이 같아도 괄호로 형식 구분이 되므로 괜찮음.
	{}

	//id는 0으로 두고, 이름만 계속 바꾸고 싶다면
	Student(const string& name) 
		:Student(0, name) //다시 나를 불러서 이렇게 하면 됨.(위임 생성자)
	{}

private:
	int id;
	string name;
};

//다른 방법
class Student2
{
public:
	Student(const int& id, const string& name)
	{
		Initialize(id, name);
	}

	Student2(const string& name)
	{
		Initialize(0, name);
	}

	void Initialize(const int& id, const string& name)
	{
		//TODO : 나중에 초기화 해주기 // 보기 - 작업목록에서 볼 수 있음 ( 주석 쉽게 찾는 방법 )
	}

private:
	int id;
	string name;
};

int main()
{

	return 0;
}