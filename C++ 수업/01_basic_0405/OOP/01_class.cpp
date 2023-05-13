#include <iostream>

using namespace std;
//간단하게 변수만 쓸 때는 struct 가 좋고, 동작을 나타내고 그럴 때에는 class가 좋음.
struct person
{
private : //struct도 접근 지정자를 쓸 수 있지만 private를 생략했을 때 class처럼 자동으로 은닉되지는 않음.

	string name;
	int age;
	float height;
	float weight;
	bool favorite;
};

//class 선언 방법
class Person //선언 자체가 캡슐화, 접근 지정자를 통해 공개할 정보 등을 지정할 수 있음
{
	/*string name;
	int age;
	float height;
	float weight; 
	bool favorite;*/  //이렇게 위에 그냥 써주면 private가 생략된 자동으로 은닉된 정보로 인식됨.

public: //활동들을 다룸
	void Work()
	{

	}
	
	void Sleep()
	{

	}

protected: //나와 자식 클래스에서만 쓸 수 있는 정보

private: //이 안에서만 사용 가능한 정보, 보통 변수를 다룸
	string name;
	int age;
	float height;
	float weight;
	bool favorite;
};

int main()
{
	Person p; // 이렇게 해야 실체가 생겨서 object, instance라고 할 수 있음
	person p1;

	//p1.age= 1;
	p.Sleep();

	return 0;
}